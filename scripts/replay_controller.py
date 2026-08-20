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
Controller for gfxrecon-replay's remote feature.

This script sends replay settings, then prints log/progress messages and saves
any files (screenshots, dump-resources) that replay streams back. It supports
both directions of connection setup:

  * Default (listen): this controller is the server; replay dials in with
    --remote-connect.
  * --connect HOST:PORT: this controller dials out to a replay that is listening
    with --remote-listen.

Wire format: each frame is a little-endian uint32 length prefix followed by
that many payload bytes. Structured messages are JSON. A binary file payload is
a JSON "file" frame immediately followed by a raw binary frame.

Replay settings travel as key/value pairs, not as a command line: a key is a
replay option with its leading dashes stripped and '-' replaced by '_', and
every value is a string. Write them after -- as key=value, or as a bare key for
an option that takes no value; see settings_from_args().

Desktop usage (replay connects out):
    python3 scripts/replay_controller.py --listen 127.0.0.1:9001 -- --loop-count=3 capture_file=capture.gfxr
    gfxrecon-replay --remote-connect tcp:localhost:9001

Desktop usage (replay listens):
    gfxrecon-replay --remote-listen tcp:0.0.0.0:9001 capture.gfxr
    python3 scripts/replay_controller.py --connect localhost:9001 -- --loop-count=3 capture_file=capture.gfxr

Android usage (replay connects out, abstract unix socket forwarded to the PC):
    adb reverse localabstract:gfxrecon tcp:9001
    python3 scripts/replay_controller.py --listen 127.0.0.1:9001 -- capture_file=/sdcard/capture.gfxr
    # launch the replay activity with intent args: --remote-connect unix:@gfxrecon

Android usage (replay listens, abstract unix socket forwarded to the PC):
    python3 scripts/replay_controller.py --connect localhost:9001 --adb -- capture_file=/sdcard/capture.gfxr
    # sets up: adb forward tcp:9001 localabstract:gfxrecon
    # launches the replay activity with intent args: --remote-listen unix:@gfxrecon
'''

import argparse
import base64
import json
import os
import queue
import select
import socket
import struct
import subprocess
import sys
import threading
import time

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

# Replay options whose value names a file replay reads. When the value is a file on this machine, it is pushed to
# replay during the handshake. Normalized settings keys; keep in sync with kRemoteInputFileArguments in
# tools/replay/replay_settings.h, which holds the same options in their command-line spelling.
INPUT_FILE_OPTIONS = (
    'dump_resources',
    'frame_warm_up_spirv',
    'load_pipeline_cache',
)

last_prog = time.time()
wire_bytes = 0  # every byte read off the socket, length prefixes included
step_bytes = 0  # wire bytes since the last progress message
step_files = 0  # 'file' messages since the last progress message

# PROTOTYPE base64 accounting, for comparing an all-JSON protocol against raw binary frames.
payload_bytes = 0  # file contents after any decoding
decode_seconds = 0.0  # time spent turning base64 back into bytes
parse_seconds = 0.0  # time spent in json.loads, which a base64 payload inflates
base64_files = 0  # 'file' messages that arrived base64-encoded


def normalize(token):
    '''Convert a command-line spelling to its settings key: strip leading dashes, '-' becomes '_'.

    >>> normalize('--loop-count')
    'loop_count'
    >>> normalize('mfr')
    'mfr'
    '''
    return token.lstrip('-').replace('-', '_')


def assign(options, key, value):
    '''Set options[key], rejecting a second, conflicting assignment of the same key.

    A settings map cannot express a key twice, so one of the two would be silently dropped. Replay cannot catch
    that -- the surviving key is perfectly valid -- so it has to be caught here.
    '''
    if key in options and options[key] != value:
        raise ValueError(f"setting '{key}' given twice, as '{options[key]}' "
                         f"and '{value}'")
    options[key] = value


def settings_from_args(tokens):
    '''Build a settings dict from key=value tokens.

    Each token is read on its own, with no reference to its neighbours or its position:

      * 'key=value' sets key to value. Only the first '=' separates, so a value may contain more.
      * A bare 'key' is an option that takes no value, set to 'true'.

    Keys are normalized, so a replay option's leading dashes may be kept or dropped. What differs from a replay
    command line is the '=' joining an option to its value, and the capture file being named by its key rather
    than positional -- deliberately, since which options take a value is not knowable from the tokens alone.

    >>> settings_from_args(['paused', 'loop_count=3', 'capture_file=cap.gfxr']) == {
    ...     'paused': 'true', 'loop_count': '3', 'capture_file': 'cap.gfxr'}
    True
    >>> settings_from_args(['--paused', '--loop-count=3']) == {
    ...     'paused': 'true', 'loop_count': '3'}
    True
    >>> settings_from_args(['fwo=-10,-10', 'screenshot_dir=/my dir']) == {
    ...     'fwo': '-10,-10', 'screenshot_dir': '/my dir'}
    True
    >>> settings_from_args(['replay_event_plugin_params=a=b'])
    {'replay_event_plugin_params': 'a=b'}
    >>> settings_from_args(['gpu=0', 'gpu=1'])
    Traceback (most recent call last):
    ValueError: setting 'gpu' given twice, as '0' and '1'
    >>> settings_from_args(['=orphan'])
    Traceback (most recent call last):
    ValueError: '=orphan' has no setting name
    '''
    options = {}
    for token in tokens:
        key, separator, value = token.partition('=')
        key = normalize(key)
        if not key:
            raise ValueError(f"'{token}' has no setting name")
        assign(options, key, value if separator else 'true')
    return options


def collect_input_files(options):
    '''Split local input files out of a settings dict.

    Returns (options, files), where options has each local input file's value replaced by its bare name and files
    is a list of (name, contents) pairs to push during the handshake. A value that is not a file on this machine
    (a path on the replay device, or the --dump-resources 'submit,command,drawcall' form) passes through
    untouched.
    '''
    options = dict(options)
    files = []
    seen = {}
    for key in INPUT_FILE_OPTIONS:
        value = options.get(key)
        if value is None or not os.path.isfile(value):
            continue
        name = os.path.basename(value)
        if name in seen and seen[name] != value:
            print(
                f"Warning: '{name}' pushed from both {seen[name]} and {value}; "
                'replay will see only the last',
                file=sys.stderr)
        seen[name] = value
        with open(value, 'rb') as source:
            files.append((name, source.read()))
        options[key] = name
    return options, files


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
    global wire_bytes, step_bytes
    header = recv_exact(conn, 4)
    if header is None:
        return None
    (length, ) = struct.unpack('<I', header)
    wire_bytes += 4 + length
    step_bytes += 4 + length
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


def handle_session(conn,
                   options,
                   output_dir,
                   hello=None,
                   input_files=(),
                   use_base64=False):
    '''Run the handshake and process messages until replay reports done.

    options is the settings dict sent to replay.

    use_base64 encodes pushed input files as base64 inside the 'file' message. Inbound files are handled by whatever
    encoding each message declares, regardless of this flag.

    hello is replay's already-received greeting frame when the caller read it during connection setup
    (connect mode); when None (listen mode) it is read here.

    input_files is a list of (name, contents) pairs pushed before the settings message.
    '''
    # Handshake: replay greets us, we reply with settings, replay acknowledges.
    if hello is None:
        hello = recv_frame(conn)
    if hello is None:
        print('Replay disconnected before handshake', file=sys.stderr)
        return False
    hello = json.loads(hello)
    if hello.get('type') != 'hello':
        print(f'Unexpected first message: {hello}', file=sys.stderr)
        return False
    print(f"Connected to replay (protocol version {hello.get('version')})")

    # Input files must precede the settings message, which ends our opening turn.
    for name, blob in input_files:
        header = {'type': 'file', 'name': name, 'size': len(blob)}
        if use_base64:
            start = time.perf_counter()
            header['encoding'] = 'base64'
            header['data'] = base64.b64encode(blob).decode('ascii')
            encode_ms = (time.perf_counter() - start) * 1000
            send_json(conn, header)
            print(f'Sent input file: {name} ({len(blob)} bytes, base64 in '
                  f'{encode_ms:.3f}ms)')
        else:
            send_json(conn, header)
            send_frame(conn, blob)
            print(f'Sent input file: {name} ({len(blob)} bytes)')

    send_json(conn, {'type': 'settings', 'options': options})
    print('Sent settings:')
    for key in sorted(options):
        print(f'  {key}={options[key]}')

    ready = recv_frame(conn)
    if ready is None or json.loads(ready).get('type') != 'ready':
        print('Replay did not acknowledge settings', file=sys.stderr)
        return False

    commands = None
    if sys.stdin.isatty():
        commands = start_command_reader()
        print(
            'Commands: p=pause, r=resume, s=step, q=stop (press Enter after each)'
        )

    success = False
    prev_msg_type = None
    last_frame = None
    last_block = None
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

        global parse_seconds
        parse_start = time.perf_counter()
        msg = json.loads(frame)
        parse_seconds += time.perf_counter() - parse_start
        msg_type = msg.get('type')

        if msg_type == 'log':
            print(f"[{msg.get('level', '?'):7}] {msg.get('message', '')}")
        elif msg_type in ('progress', 'operation_progress'):
            # Frame-level 'progress' and bounded 'operation_progress' share one in-place status line.
            if msg_type == 'progress':
                last_frame = msg.get('frame')
                last_block = msg.get('block')
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
                frame_part = f"frame {last_frame}"
                if last_block is not None:
                    frame_part += f", block {last_block}"
                parts.append(frame_part)
            if last_current is not None:
                parts.append(f"{last_op} {last_current}/{last_total}")
            global last_prog, step_bytes, step_files
            cur_time = time.time()
            delta = cur_time - last_prog
            last_prog = cur_time
            rate = (step_bytes / delta / (1 << 20)) if delta > 0 else 0.0
            print(f"--- progress: {', '.join(parts)} "
                  f"(delta={delta*1000:.3f}ms, {step_bytes/1024:.1f}KiB in "
                  f"{step_files} files, {rate:.2f}MiB/s, "
                  f"total {wire_bytes/(1<<20):.1f}MiB) ---")
            step_bytes = 0
            step_files = 0
        elif msg_type == 'file':
            # The payload is either base64 inside this message or the raw binary frame that follows it.
            global payload_bytes, decode_seconds, base64_files
            step_files += 1
            name = msg.get('name', 'unnamed')
            expected = msg.get('size', 0)
            if msg.get('encoding') == 'base64':
                base64_files += 1
                start = time.perf_counter()
                blob = base64.b64decode(msg.get('data', ''))
                decode_seconds += time.perf_counter() - start
            else:
                blob = recv_frame(conn)
                blob = blob if blob is not None else b''
            payload_bytes += len(blob)
            save_file(output_dir, name, blob, expected)
        elif msg_type == 'done':
            success = bool(msg.get('success'))
            print(f'Replay finished (success={success})')
            break
        else:
            print(f'Unknown message: {msg}', file=sys.stderr)

        prev_msg_type = msg_type

    print_transfer_summary()

    return success


def print_transfer_summary():
    '''PROTOTYPE: report what the encoding cost on this side of the socket.'''
    if wire_bytes == 0:
        return
    expansion = (wire_bytes / payload_bytes) if payload_bytes else 0.0
    print(f'--- transfer: {payload_bytes / (1 << 20):.1f}MiB payload in '
          f'{wire_bytes / (1 << 20):.1f}MiB on the wire ({expansion:.3f}x), '
          f'{base64_files} base64 files, {decode_seconds * 1000:.1f}ms '
          f'base64 decode, {parse_seconds * 1000:.1f}ms json parse ---')


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


def connect_and_await_hello(host, port, timeout_seconds=30):
    '''Dial out to a listening replay and return (conn, hello_frame) once its hello arrives.

    Replay may still be coming up when we connect. Through `adb forward`, adb accepts the local
    connection immediately and only then dials the device-side socket, so a not-yet-listening replay
    shows up as a connection that closes right after connect rather than as connection-refused. Retry
    the whole connect-and-read until the hello arrives or the timeout expires; returns (None, None) on
    timeout.
    '''
    deadline = time.monotonic() + timeout_seconds
    while True:
        conn = None
        try:
            conn = socket.create_connection((host, port), timeout=5)
            conn.settimeout(5)
            hello = recv_frame(conn)
            if hello is not None:
                conn.settimeout(None)
                return conn, hello
            # Connected, but replay is not listening yet (e.g. adb forward with no device-side socket).
        except OSError:
            pass
        if conn is not None:
            conn.close()
        if time.monotonic() >= deadline:
            return None, None
        time.sleep(0.2)


def main():
    parser = argparse.ArgumentParser(
        description='Control gfxrecon-replay over its remote socket.',
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog='''\
Everything after -- becomes replay's settings, which travel over the socket as
key/value pairs rather than as a command line. Write each one as key=value, or
as a bare key for an option that takes no value:

    -- paused --loop-count=3 --dump-resources=dr.json capture_file=cap.gfxr

Leading dashes are optional, so options keep their familiar spelling. What
differs from a replay command line is the '=' joining an option to its value,
and the capture file being named by its key rather than positional. Replay
rejects any key it does not recognize, naming it in the error.''')
    parser.add_argument(
        '--listen',
        metavar='HOST:PORT',
        default='127.0.0.1:9001',
        help='Address to listen on for replay to connect (default: '
        '127.0.0.1:9001).')
    parser.add_argument(
        '--connect',
        metavar='HOST:PORT',
        help='Connect out to a replay that is listening (--remote-listen) '
        'instead of listening for replay to connect.')
    parser.add_argument(
        '--adb',
        action='store_true',
        help='Launch replay on an connected Android device via adb.')
    parser.add_argument(
        '--output-dir',
        default='remote_output',
        help=
        'Directory for files streamed back by replay (default: remote_output).'
    )
    parser.add_argument(
        '--base64',
        action='store_true',
        help='PROTOTYPE: base64-encode binary payloads in both directions '
        'instead of sending raw binary frames, to measure the cost of an '
        'all-JSON protocol. Encodes pushed input files and adds '
        'remote_base64=true to the settings so replay encodes what it streams '
        'back. Pass remote_base64 in the settings instead to encode only the '
        'replay-to-controller direction.')
    parser.add_argument('--self-test',
                        action='store_true',
                        help='Run this script\'s doctests and exit.')
    parser.add_argument(
        'replay_args',
        nargs=argparse.REMAINDER,
        help='Replay settings, e.g. -- --loop-count 3 capture.gfxr')
    args = parser.parse_args()

    if args.self_test:
        import doctest
        return 1 if doctest.testmod(verbose=False).failed else 0

    # Strip a leading '--' separator if argparse left it in the remainder.
    replay_args = args.replay_args
    if replay_args and replay_args[0] == '--':
        replay_args = replay_args[1:]
    if not replay_args:
        parser.error(
            'No replay args given. Pass them after --, e.g. -- capture.gfxr')

    try:
        options = settings_from_args(replay_args)
    except ValueError as e:
        parser.error(str(e))

    # Every path in the settings resolves on the replay device, so any input file that lives here must be pushed
    # over the socket and its option value rewritten to the name replay will know it by.
    options, input_files = collect_input_files(options)

    # One flag flips both directions: this side encodes what it pushes, replay encodes what it streams back.
    if args.base64:
        options.setdefault('remote_base64', 'true')

    os.makedirs(args.output_dir, exist_ok=True)

    def parse_host_port(flag, spec):
        host, _, port_str = spec.rpartition(':')
        if not host or not port_str:
            parser.error(f'{flag} expects HOST:PORT')
        try:
            return host, int(port_str)
        except ValueError:
            parser.error(f'{flag} expects a numeric port in HOST:PORT')

    LOCAL_ABSTRACT_NAME = 'gfxrecon'
    PACKAGE = 'com.lunarg.gfxreconstruct.replay'

    if args.connect:
        # Connect mode: dial out to a replay that is listening with --remote-listen.
        host, port = parse_host_port('--connect', args.connect)

        if args.adb:
            try:
                # A leftover 'adb reverse' from a prior listen-mode run keeps adbd bound to the abstract
                # socket, so replay's --remote-listen bind would fail with EADDRINUSE. Clear it first
                # (check=False: it errors when no such mapping exists).
                subprocess.run([
                    'adb', 'reverse', '--remove',
                    f'localabstract:{LOCAL_ABSTRACT_NAME}'
                ],
                               check=False)

                # Use adb forward so the PC-side connection reaches the device's abstract socket.
                subprocess.run([
                    'adb', 'forward', f'tcp:{port}',
                    f'localabstract:{LOCAL_ABSTRACT_NAME}'
                ],
                               check=True)
                print(
                    f"ADB forward set up: tcp:{port} -> localabstract:{LOCAL_ABSTRACT_NAME}"
                )

                # Stop any prior instance first; a lingering process keeps the abstract socket bound
                # (it is unlinkable) and the new instance would fail to listen with EADDRINUSE.
                subprocess.run(['adb', 'shell', 'am', 'force-stop', PACKAGE],
                               check=True)

                # Launch the replay activity on the device listening on the abstract socket.
                subprocess.run([
                    'adb', 'shell', 'am', 'start', '-n',
                    f'{PACKAGE}/.ReplayActivity', '-a',
                    'android.intent.action.MAIN', '-c',
                    'android.intent.category.LAUNCHER', '--es', 'args',
                    f'"--remote-listen unix:@{LOCAL_ABSTRACT_NAME}"'
                ],
                               check=True)

            except subprocess.CalledProcessError as e:
                print(f"Failed to set up adb remote: {e}", file=sys.stderr)
                return 1

        try:
            conn, hello = connect_and_await_hello(host, port)
        except KeyboardInterrupt:
            print('\nInterrupted while connecting', file=sys.stderr)
            return 1
        if conn is None:
            print(f'Timed out waiting for a listening replay at {host}:{port}',
                  file=sys.stderr)
            return 1

        print(f'Connected to replay at {host}:{port}')
        with conn:
            success = handle_session(conn, options, args.output_dir, hello,
                                     input_files, args.base64)

        return 0 if success else 1

    # Listen mode: this controller is the server and replay connects in with --remote-connect.
    host, port = parse_host_port('--listen', args.listen)

    if args.adb:
        # A leftover 'adb forward' from a prior connect-mode run keeps adb bound to the host port, so
        # our own bind below would fail with EADDRINUSE. Clear it first (check=False: it errors when no
        # such mapping exists).
        subprocess.run(['adb', 'forward', '--remove', f'tcp:{port}'],
                       check=False)

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if sys.platform == 'win32':
        # Not SO_REUSEADDR: on Windows that lets an unrelated process take over a port we have bound.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
    else:
        # Rebind a port left in TIME_WAIT by a previous run.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((host, port))
    server.listen(1)
    print(f'Listening on {host}:{port}')

    if args.adb:
        try:
            # Use adb reverse to forward the socket for Android replay.
            subprocess.run([
                'adb', 'reverse', f'localabstract:{LOCAL_ABSTRACT_NAME}',
                f'tcp:{port}'
            ],
                           check=True)
            print(
                f"ADB reverse set up: tcp:{port} -> localabstract:{LOCAL_ABSTRACT_NAME}"
            )

            # Stop any prior instance so a fresh process picks up this run's settings.
            subprocess.run(['adb', 'shell', 'am', 'force-stop', PACKAGE],
                           check=True)

            # Launch the replay activity on the device connecting to the abstract socket.
            subprocess.run([
                'adb', 'shell', 'am', 'start', '-n',
                f'{PACKAGE}/.ReplayActivity', '-a',
                'android.intent.action.MAIN', '-c',
                'android.intent.category.LAUNCHER', '--es', 'args',
                f'"--remote-connect unix:@{LOCAL_ABSTRACT_NAME}"'
            ],
                           check=True)

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
        success = handle_session(conn,
                                 options,
                                 args.output_dir,
                                 input_files=input_files,
                                 use_base64=args.base64)

    return 0 if success else 1


if __name__ == '__main__':
    sys.exit(main())
