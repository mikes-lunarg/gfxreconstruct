#!/usr/bin/env python3

# Copyright (c) 2026 LunarG, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
'''
Controller for gfxrecon-replay's --remote feature.

gfxrecon-replay is the client and connects outward to this controller, which
acts as the server. This script listens for that connection, sends the replay
settings, then prints log/progress messages and saves any files (screenshots,
dump-resources) that replay streams back.

Wire format: each frame is a little-endian uint32 length prefix followed by
that many payload bytes. Structured messages are JSON. A binary file payload is
a JSON "file" frame immediately followed by a raw binary frame.

Desktop usage:
    python3 scripts/replay_controller.py --port 9001 -- --loop-count 3 capture.gfxr
    gfxrecon-replay --remote tcp:localhost:9001

Android usage (replay connects to an abstract unix socket forwarded to the PC):
    adb reverse localabstract:gfxrecon tcp:9001
    python3 scripts/replay_controller.py --port 9001 -- /sdcard/capture.gfxr
    # launch the replay activity with intent args: --remote unix:@gfxrecon
'''

import argparse
import json
import os
import queue
import select
import socket
import struct
import subprocess
import sys
import threading

TRIGGER_COMMANDS = {
    'p': 'pause',
    'pause': 'pause',
    'r': 'resume',
    'resume': 'resume',
    's': 'step',
    'n': 'step',
    'step': 'step',
    'q': 'stop',
    'stop': 'stop',
}


def recv_exact(conn, length):
    '''Read exactly length bytes, or return None if the peer closes early.'''
    chunks = []
    remaining = length
    while remaining > 0:
        chunk = conn.recv(remaining)
        if not chunk:
            return None
        chunks.append(chunk)
        remaining -= len(chunk)
    return b''.join(chunks)


def recv_frame(conn):
    '''Read one length-prefixed frame. Returns bytes, or None on disconnect.'''
    header = recv_exact(conn, 4)
    if header is None:
        return None
    (length, ) = struct.unpack('<I', header)
    if length == 0:
        return b''
    return recv_exact(conn, length)


def send_frame(conn, payload):
    conn.sendall(struct.pack('<I', len(payload)) + payload)


def send_json(conn, obj):
    send_frame(conn, json.dumps(obj).encode('utf-8'))


def send_command(conn, line):
    '''Send the trigger matching one line of command input.'''
    line = line.strip().lower()
    if not line:
        return
    action = TRIGGER_COMMANDS.get(line)
    if action is None:
        print(f"Unknown command '{line}' (p=pause, r=resume, s=step, q=stop)")
        return
    send_json(conn, {'type': 'trigger', 'action': action})


def start_command_reader():
    '''Read stdin lines on a daemon thread; select() on stdin is POSIX-only, but a queue works everywhere.'''
    commands = queue.Queue()

    def reader():
        for line in sys.stdin:
            commands.put(line)

    threading.Thread(target=reader, daemon=True).start()
    return commands


def handle_session(conn, replay_args, output_dir):
    '''Run the handshake and process messages until replay reports done.'''
    # Handshake: replay greets us, we reply with settings, replay acknowledges.
    hello = recv_frame(conn)
    if hello is None:
        print('Replay disconnected before handshake', file=sys.stderr)
        return False
    hello = json.loads(hello)
    if hello.get('type') != 'hello':
        print(f'Unexpected first message: {hello}', file=sys.stderr)
        return False
    print(f"Connected to replay (protocol version {hello.get('version')})")

    send_json(conn, {'type': 'settings', 'args': replay_args})
    print(f'Sent settings: {replay_args}')

    ready = recv_frame(conn)
    if ready is None or json.loads(ready).get('type') != 'ready':
        print('Replay did not acknowledge settings', file=sys.stderr)
        return False

    commands = None
    if sys.stdin.isatty():
        commands = start_command_reader()
        print('Commands: p=pause, r=resume, s=step, q=stop (press Enter after each)')

    success = False
    prev_msg_type = None
    last_frame = None
    last_op = None
    last_current = None
    last_total = None
    while True:
        if commands is not None:
            # Windows select() only supports sockets, so poll the socket and drain queued stdin commands.
            readable, _, _ = select.select([conn], [], [], 0.1)
            while not commands.empty():
                send_command(conn, commands.get_nowait())
            if conn not in readable:
                continue

        frame = recv_frame(conn)
        if frame is None:
            print('Replay disconnected')
            break

        msg = json.loads(frame)
        msg_type = msg.get('type')

        if msg_type == 'log':
            print(f"[{msg.get('level', '?'):7}] {msg.get('message', '')}")
        elif msg_type in ('progress', 'operation_progress'):
            # Frame-level 'progress' and bounded 'operation_progress' share one in-place status line.
            if msg_type == 'progress':
                last_frame = msg.get('frame')
            else:
                last_op = msg.get('operation', 'operation')
                last_current = msg.get('current')
                last_total = msg.get('total')
            if prev_msg_type in ('progress', 'operation_progress'):
                print(
                    f"\033[F", end=''
                )  # Move cursor up one line to overwrite previous progress
            # 'frame' may be unknown if an operation reports before any frame progress.
            parts = []
            if last_frame is not None:
                parts.append(f"frame {last_frame}")
            if last_current is not None:
                parts.append(f"{last_op} {last_current}/{last_total}")
            print(f"--- progress: {', '.join(parts)}")
        elif msg_type == 'file':
            # A "file" message is always followed by a raw binary frame.
            name = msg.get('name', 'unnamed')
            expected = msg.get('size', 0)
            blob = recv_frame(conn)
            blob = blob if blob is not None else b''
            save_file(output_dir, name, blob, expected)
        elif msg_type == 'done':
            success = bool(msg.get('success'))
            print(f'Replay finished (success={success})')
            break
        else:
            print(f'Unknown message: {msg}', file=sys.stderr)

        prev_msg_type = msg_type

    return success


def save_file(output_dir, name, blob, expected_size):
    if len(blob) != expected_size:
        print(
            f"Warning: '{name}' expected {expected_size} bytes, got {len(blob)}",
            file=sys.stderr)

    # Keep the relative path from replay but anchor it under output_dir, and
    # never let it escape via leading slashes or '..'.
    safe_name = os.path.normpath(name).lstrip(os.sep)
    if safe_name.startswith('..'):
        safe_name = os.path.basename(name)
    dest = os.path.join(output_dir, safe_name)

    os.makedirs(os.path.dirname(dest) or '.', exist_ok=True)
    with open(dest, 'wb') as out:
        out.write(blob)
    print(f"Saved file: {dest} ({len(blob)} bytes)")


def main():
    parser = argparse.ArgumentParser(
        description='Control gfxrecon-replay over its --remote socket.',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=
        'Everything after -- is forwarded to replay as its settings args string.'
    )
    parser.add_argument('--host',
                        default='127.0.0.1',
                        help='Address to listen on (default: 127.0.0.1).')
    parser.add_argument('--port',
                        type=int,
                        default=9001,
                        help='TCP port to listen on (default: 9001).')
    parser.add_argument('--adb', action='store_true', help='Launch replay on an connected Android device via adb.')
    parser.add_argument(
        '--output-dir',
        default='remote_output',
        help=
        'Directory for files streamed back by replay (default: remote_output).'
    )
    parser.add_argument(
        'replay_args',
        nargs=argparse.REMAINDER,
        help='Replay settings args, e.g. -- --loop-count 3 capture.gfxr')
    args = parser.parse_args()

    # Strip a leading '--' separator if argparse left it in the remainder.
    replay_args = args.replay_args
    if replay_args and replay_args[0] == '--':
        replay_args = replay_args[1:]
    if not replay_args:
        parser.error(
            'No replay args given. Pass them after --, e.g. -- capture.gfxr')

    os.makedirs(args.output_dir, exist_ok=True)

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((args.host, args.port))
    server.listen(1)
    print(f'Listening on {args.host}:{args.port}')

    if args.adb:
        try:
            # Use adb reverse to forward the socket for Android replay.
            LOCAL_ABSTRACT_NAME = 'gfxrecon'
            subprocess.run(['adb', 'reverse', f'localabstract:{LOCAL_ABSTRACT_NAME}', f'tcp:{args.port}'], check=True)
            print(f"ADB reverse set up: tcp:{args.port} -> localabstract:{LOCAL_ABSTRACT_NAME}")

            # Launch the replay activity on the device with the --remote argument pointing to the abstract socket.
            subprocess.run(['adb', 'shell', 'am', 'start', '-n', 'com.lunarg.gfxreconstruct.replay/.ReplayActivity', '-a', 'android.intent.action.MAIN', '-c', 'android.intent.category.LAUNCHER', '--es', 'args', f'"--remote unix:@{LOCAL_ABSTRACT_NAME}"'], check=True)

        except subprocess.CalledProcessError as e:
            print(f"Failed to set up adb remote: {e}", file=sys.stderr)
            return 1

    try:
        conn, peer = server.accept()
    except KeyboardInterrupt:
        print('\nInterrupted while waiting for replay')
        return 1

    print(f'Replay connected from {peer[0]}:{peer[1]}')
    with conn:
        success = handle_session(conn, ' '.join(replay_args), args.output_dir)

    return 0 if success else 1


if __name__ == '__main__':
    sys.exit(main())
