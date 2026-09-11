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

When the zstandard package is installed, each direction of the socket is
negotiated into a single zstd stream carrying those frames (the framing itself
is unchanged); --no-compress declines it. The similarly-named zstd package
cannot decode a stream incrementally and is not a substitute.

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
    python3 scripts/replay_controller.py --connect localhost:9001 --launch-adb -- capture_file=/sdcard/capture.gfxr
    # sets up: adb forward tcp:9001 localabstract:gfxrecon
    # launches the replay activity with intent args: --remote-listen unix:@gfxrecon

Backpressure testing (a slow controller against replay's bounded send queue):
    python3 scripts/replay_controller.py --listen 127.0.0.1:9001 --slow-recv 8 -- \\
        dump_resources=dr.json capture_file=capture.gfxr
'''

import argparse
import json
import os
import queue
import select
import shlex
import socket
import struct
import subprocess
import sys
import threading
import time

try:
    import zstandard
except ImportError:
    zstandard = None

# Mirrors RemoteChannel::StartCompression. The window must span more than one dump's payload for cross-draw
# matching, and at level 1 long-distance matching is what finds those matches; see docs/remote_protocol.md.
ZSTD_LEVEL = 1
ZSTD_WINDOW_LOG = 25

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


recv_rate = 0.0  # --slow-recv byte rate; 0 leaves reads unthrottled
recv_sleep_seconds = 0.0  # time this side spent deliberately not reading
wire_bytes = 0  # bytes read off the socket, before any decompression
stream_bytes = 0  # framed bytes handed to the session, after any decompression


def note_recv(count):
    '''Record count bytes taken off the socket, and pace reads when --slow-recv is set.

    Every socket read funnels through here, so wire_bytes is the transmitted total no matter which direction
    dialed or whether the stream is compressed.

    Sleeping after the read rather than before it is the point: the kernel keeps filling the receive buffer while
    we are idle, so once that buffer is full the stall propagates back to replay as a blocked send.
    '''
    global recv_sleep_seconds, wire_bytes
    wire_bytes += count
    if recv_rate <= 0:
        return
    delay = count / recv_rate
    recv_sleep_seconds += delay
    time.sleep(delay)


def human_bytes(count):
    '''Format a byte count in the largest unit that keeps it readable.

    >>> [human_bytes(n) for n in (512, 2048, 5 << 20, 3 << 30)]
    ['512 B', '2.0 KiB', '5.0 MiB', '3.00 GiB']
    '''
    for unit, scale, digits in (('GiB', 1 << 30, 2), ('MiB', 1 << 20, 1),
                                ('KiB', 1 << 10, 1)):
        if count >= scale:
            return f'{count / scale:.{digits}f} {unit}'
    return f'{count} B'


def print_wire_summary():
    '''Report transmitted bytes, and what they expanded to once decoded.'''
    if wire_bytes == 0:
        return
    parts = [f'{human_bytes(wire_bytes)} on the wire']
    if stream_bytes != wire_bytes:
        parts.append(f'{human_bytes(stream_bytes)} decoded '
                     f'({stream_bytes / wire_bytes:.2f}x)')
    if recv_rate > 0:
        parts.append(f'{recv_sleep_seconds:.1f}s throttled')
    print(f"--- received: {', '.join(parts)} ---")


def apply_recv_throttle(conn, mib_per_second):
    '''Slow this side's reads to mib_per_second, to exercise replay's send queue bound.'''
    global recv_rate
    if mib_per_second <= 0:
        return
    recv_rate = mib_per_second * (1 << 20)

    # Shrink the receive buffer so the stall reaches replay promptly instead of after the kernel has quietly
    # absorbed several MiB. Advisory: the window may already have been negotiated larger.
    try:
        conn.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, 256 * 1024)
    except OSError as e:
        print(f'Warning: could not shrink the receive buffer: {e}',
              file=sys.stderr)

    print(f'Throttling reads to {mib_per_second:.1f} MiB/s')


def recv_exact(conn, length):
    '''Read exactly length bytes, or return None if the peer closes early.'''
    global stream_bytes
    chunks = []
    remaining = length
    while remaining > 0:
        chunk = conn.recv(remaining)
        if not chunk:
            return None
        chunks.append(chunk)
        remaining -= len(chunk)
        note_recv(len(chunk))
    stream_bytes += length  # Plaintext here, so these bytes are both transmitted and decoded.
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


class Channel:
    '''Framed connection over a socket; either direction may become a zstd stream after negotiation.

    Compression sits below the framing: enable_send_compression() and enable_recv_compression() change only
    how frame bytes reach and leave the socket, so callers keep sending and receiving whole frames.
    '''

    def __init__(self, conn):
        self.conn = conn
        self._compressor = None
        self._decompressor = None
        self._decoded = bytearray(
        )  # Decompressed bytes received but not yet consumed.

    def enable_send_compression(self):
        params = zstandard.ZstdCompressionParameters.from_level(
            ZSTD_LEVEL, window_log=ZSTD_WINDOW_LOG, enable_ldm=True)
        self._compressor = zstandard.ZstdCompressor(
            compression_params=params).compressobj()

    def enable_recv_compression(self):
        self._decompressor = zstandard.ZstdDecompressor().decompressobj()

    def has_buffered_data(self):
        '''True when decoded bytes are waiting, so the socket may be silent while a frame is readable.'''
        return bool(self._decoded)

    def send_frame(self, payload):
        data = struct.pack('<I', len(payload)) + payload
        if self._compressor is not None:
            # Flush per message so a trigger never sits in the compressor waiting for a block to fill.
            data = self._compressor.compress(data) + self._compressor.flush(
                zstandard.COMPRESSOBJ_FLUSH_BLOCK)
        self.conn.sendall(data)

    def send_json(self, obj):
        self.send_frame(json.dumps(obj).encode('utf-8'))

    def recv_exact(self, length):
        global stream_bytes
        if self._decompressor is None:
            return recv_exact(self.conn, length)  # Accounts for itself.
        while len(self._decoded) < length:
            chunk = self.conn.recv(65536)
            if not chunk:
                return None
            self._decoded += self._decompressor.decompress(chunk)
            note_recv(len(chunk))
        result = bytes(self._decoded[:length])
        del self._decoded[:length]
        stream_bytes += len(result)
        return result

    def recv_frame(self):
        header = self.recv_exact(4)
        if header is None:
            return None
        (length, ) = struct.unpack('<I', header)
        if length == 0:
            return b''
        return self.recv_exact(length)


def negotiate_features(chan, hello, allow_compression):
    '''Answer hello with welcome, selecting from the advertised features.

    Selects stream compression for each direction the replay build advertised, when the zstandard package
    is available and --no-compress was not given. Each direction switches immediately after welcome.
    '''
    advertised = hello.get('features') or {}
    selected = {}
    if allow_compression and zstandard is not None:
        for key in ('compress_output', 'compress_input'):
            if advertised.get(key) is True:
                selected[key] = True
    welcome = {'type': 'welcome'}
    if selected:
        welcome['features'] = selected
    chan.send_json(welcome)

    if selected.get('compress_output'):
        chan.enable_recv_compression()
    if selected.get('compress_input'):
        chan.enable_send_compression()
    if selected:
        print(
            f"Stream compression enabled ({' and '.join(sorted(selected))}): "
            f'zstd level {ZSTD_LEVEL}, window log {ZSTD_WINDOW_LOG}, '
            'long-distance matching')
    elif allow_compression and zstandard is None and advertised:
        print('zstandard package not installed; streams stay uncompressed')


def send_command(chan, line):
    '''Send the trigger matching one line of command input.'''
    line = line.strip().lower()
    if not line:
        return
    action = TRIGGER_COMMANDS.get(line)
    if action is None:
        print(f"Unknown command '{line}' (p=pause, r=resume, s=step, q=stop)")
        return
    chan.send_json({'type': 'trigger', 'action': action})


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
                   no_compress=False):
    '''Run the handshake and process messages until replay reports done.

    options is the settings dict sent to replay.

    hello is replay's already-received greeting frame when the caller read it during connection setup
    (connect mode); when None (listen mode) it is read here.

    input_files is a list of (name, contents) pairs pushed before the settings message.
    '''
    # Handshake: replay greets us, we answer with welcome, input files, and settings; replay acknowledges.
    # hello and welcome are always uncompressed; the negotiated encoding covers everything after.
    if hello is None:
        hello = recv_frame(conn)
    if hello is None:
        print('Replay disconnected before handshake', file=sys.stderr)
        return False
    hello = json.loads(hello)
    if hello.get('type') != 'hello':
        print(f'Unexpected first message: {hello}', file=sys.stderr)
        return False
    if hello.get('role') != 'replay':
        print(f"Unsupported peer role '{hello.get('role')}'", file=sys.stderr)
        return False
    if hello.get('version') != '1':
        print(f"Unsupported protocol version '{hello.get('version')}'",
              file=sys.stderr)
        return False
    print(f"Connected to replay (protocol version {hello.get('version')})")

    chan = Channel(conn)
    negotiate_features(chan, hello, not no_compress)

    # Input files must precede the settings message, which ends our opening turn.
    for name, blob in input_files:
        chan.send_json({'type': 'file', 'name': name, 'size': len(blob)})
        chan.send_frame(blob)
        print(f'Sent input file: {name} ({len(blob)} bytes)')

    chan.send_json({'type': 'settings', 'options': options})
    print('Sent settings:')
    for key in sorted(options):
        print(f'  {key}={options[key]}')

    ready = chan.recv_frame()
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
                send_command(chan, commands.get_nowait())
            # One socket read can decode to several frames, so a silent socket is not an empty channel.
            if conn not in readable and not chan.has_buffered_data():
                continue

        frame = chan.recv_frame()
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
            print(f"--- progress: {', '.join(parts)}")
        elif msg_type == 'file':
            # A "file" message is always followed by a raw binary frame.
            name = msg.get('name', 'unnamed')
            expected = msg.get('size', 0)
            blob = chan.recv_frame()
            blob = blob if blob is not None else b''
            save_file(output_dir, name, blob, expected)
        elif msg_type == 'done':
            success = bool(msg.get('success'))
            print(f'Replay finished (success={success})')
            break
        else:
            print(f'Unknown message: {msg}', file=sys.stderr)

        prev_msg_type = msg_type

    print_wire_summary()

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


# --- Session driving -----------------------------------------------------------------------------------
#
# Everything below is importable without argparse, so another harness can drive a replay session without
# duplicating the handshake or shelling out to this script.

ABSTRACT_SOCKET_NAME = 'gfxrecon'
REPLAY_PACKAGE = 'com.lunarg.gfxreconstruct.replay'


class ControllerError(Exception):
    '''A setup failure worth reporting to the user rather than tracing back.

    Raised for the things that go wrong before a session exists: an unusable --launch command, a port we
    cannot bind, or an adb step that fails. Session outcomes are reported by the return value instead.
    '''


def launch_replay(command, remote_option, address):
    '''Start a replay process for this session, appending the remote option it should use.

    command is a command line, so extra arguments and a wrapper both work ("./gfxrecon-replay",
    "wine gfxrecon-replay.exe"). Returns the Popen object.
    '''
    if not command.strip():
        raise ControllerError('--launch was given an empty command')

    if os.name == 'nt':
        # Hand Windows the command line unsplit: CreateProcess does its own parsing, and splitting it
        # here would eat the backslashes in a path like C:\build\bin\gfxrecon-replay.exe.
        argv = f'{command} {remote_option} {address}'
        printable = argv
    else:
        argv = shlex.split(command) + [remote_option, address]
        printable = ' '.join(argv)

    print('Launching replay: ' + printable)
    try:
        return subprocess.Popen(argv)
    except OSError as e:
        raise ControllerError(
            f'could not start replay "{command}": {e}') from e


def reap_replay(proc, timeout_seconds=60):
    '''Wait for a launched replay to exit, escalating to terminate/kill so no process is left behind.

    Returns its exit code, or None when nothing was launched.
    '''
    if proc is None:
        return None
    try:
        return proc.wait(timeout=timeout_seconds)
    except subprocess.TimeoutExpired:
        print('Replay did not exit; terminating', file=sys.stderr)
        proc.terminate()
    try:
        return proc.wait(timeout=5)
    except subprocess.TimeoutExpired:
        proc.kill()
        return proc.wait()


def open_listen_socket(host, port):
    '''Bind and listen for one replay. Returns (server, port); port 0 binds an ephemeral port.

    The bound port is read back so a caller that passed 0 knows what to tell replay to connect to.
    '''
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if sys.platform == 'win32':
        # Not SO_REUSEADDR: on Windows that lets an unrelated process take over a port we have bound.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_EXCLUSIVEADDRUSE, 1)
    else:
        # Rebind a port left in TIME_WAIT by a previous run.
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        server.bind((host, port))
        server.listen(1)
    except OSError as e:
        server.close()
        raise ControllerError(f'could not listen on {host}:{port}: {e}') from e
    return server, server.getsockname()[1]


def adb_prepare(mode, port):
    '''Point an Android replay at this controller and start it.

    Each mode clears the opposite mapping first: an `adb reverse` makes adbd itself bind the abstract
    name and that outlives both the replay process and a force-stop, so a leftover one from the other
    mode makes this run fail to bind with EADDRINUSE.
    '''
    try:
        if mode == 'connect':
            # This controller dials out, so adb must forward our local port to the device's socket.
            subprocess.run([
                'adb', 'reverse', '--remove',
                f'localabstract:{ABSTRACT_SOCKET_NAME}'
            ],
                           check=False)
            subprocess.run([
                'adb', 'forward', f'tcp:{port}',
                f'localabstract:{ABSTRACT_SOCKET_NAME}'
            ],
                           check=True)
            print(
                f'ADB forward set up: tcp:{port} -> localabstract:{ABSTRACT_SOCKET_NAME}'
            )
            replay_option = '--remote-listen'
        else:
            subprocess.run(['adb', 'forward', '--remove', f'tcp:{port}'],
                           check=False)
            subprocess.run([
                'adb', 'reverse', f'localabstract:{ABSTRACT_SOCKET_NAME}',
                f'tcp:{port}'
            ],
                           check=True)
            print(
                f'ADB reverse set up: tcp:{port} -> localabstract:{ABSTRACT_SOCKET_NAME}'
            )
            replay_option = '--remote-connect'

        # A lingering instance keeps the abstract socket bound, so clear it before starting a fresh one.
        subprocess.run(['adb', 'shell', 'am', 'force-stop', REPLAY_PACKAGE],
                       check=True)
        subprocess.run([
            'adb', 'shell', 'am', 'start', '-n',
            f'{REPLAY_PACKAGE}/.ReplayActivity', '-a',
            'android.intent.action.MAIN', '-c',
            'android.intent.category.LAUNCHER', '--es', 'args',
            f'"{replay_option} unix:@{ABSTRACT_SOCKET_NAME}"'
        ],
                       check=True)
    except subprocess.CalledProcessError as e:
        raise ControllerError(f'failed to set up adb remote: {e}') from e


def run_session(conn,
                options,
                output_dir,
                hello=None,
                input_files=(),
                no_compress=False,
                slow_recv=0.0):
    '''Drive one replay session over an already-connected socket. Returns True on success.'''
    apply_recv_throttle(conn, slow_recv)
    with conn:
        return handle_session(conn, options, output_dir, hello, input_files,
                              no_compress)


def run_replay(options,
               output_dir,
               mode='listen',
               host='127.0.0.1',
               port=9001,
               input_files=(),
               no_compress=False,
               slow_recv=0.0,
               launch=None,
               launch_adb=False):
    '''Set up the transport, optionally start replay, and drive one session.

    mode selects who dials: 'listen' waits for replay to connect (replay uses --remote-connect),
    'connect' dials out to a replay that is listening (replay uses --remote-listen). In listen mode a
    port of 0 binds an ephemeral port, which is what a launched or parallel run should use.

    Returns True only when replay reported success and any process we launched exited cleanly.
    '''
    if launch_adb and launch is not None:
        raise ControllerError(
            'use either --launch-adb or --launch, not both; each starts a replay for this session'
        )
    if mode == 'connect' and port == 0:
        # Nothing to dial: port 0 only means "pick one" to the side that binds.
        raise ControllerError(
            'connect mode needs a real port; port 0 is only valid when listening'
        )

    os.makedirs(output_dir, exist_ok=True)
    proc = None

    if mode == 'connect':
        if launch_adb:
            adb_prepare('connect', port)
        if launch is not None:
            proc = launch_replay(launch, '--remote-listen',
                                 f'tcp:{host}:{port}')

        conn, hello = connect_and_await_hello(host, port)
        if conn is None:
            print(f'Timed out waiting for a listening replay at {host}:{port}',
                  file=sys.stderr)
            reap_replay(proc)
            return False
        print(f'Connected to replay at {host}:{port}')
        success = run_session(conn, options, output_dir, hello, input_files,
                              no_compress, slow_recv)
    else:
        server, port = open_listen_socket(host, port)
        print(f'Listening on {host}:{port}')
        with server:
            # Started only once the port is known and bound, so a launched replay cannot dial too early.
            if launch_adb:
                adb_prepare('listen', port)
            if launch is not None:
                proc = launch_replay(launch, '--remote-connect',
                                     f'tcp:{host}:{port}')

            conn, peer = server.accept()
            print(f'Replay connected from {peer[0]}:{peer[1]}')
        success = run_session(conn, options, output_dir, None, input_files,
                              no_compress, slow_recv)

    returncode = reap_replay(proc)
    if returncode:
        print(f'Launched replay exited with {returncode}', file=sys.stderr)
        success = False
    return success


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
        '--launch-adb',
        action='store_true',
        help='Launch replay on an connected Android device via adb.')
    parser.add_argument(
        '--launch',
        metavar='COMMAND',
        help='Start replay locally with this command, appending the matching '
        '--remote-connect/--remote-listen option and this controller\'s '
        'address. Use with --listen 127.0.0.1:0 to pick a free port.')
    parser.add_argument(
        '--output-dir',
        default='remote_output',
        help=
        'Directory for files streamed back by replay (default: remote_output).'
    )
    parser.add_argument(
        '--no-compress',
        action='store_true',
        help='Do not enable stream compression, even when replay and the '
        'zstandard package support it.')
    parser.add_argument(
        '--slow-recv',
        type=float,
        default=0.0,
        metavar='MIB_PER_S',
        help='Read at roughly this rate instead of as fast as possible, to '
        'exercise replay\'s bounded send queue. Also shrinks this side\'s '
        'receive buffer so the stall reaches replay promptly. 0 (the default) '
        'leaves reads unthrottled.')
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

    # Every path in the settings resolves on the replay device, so any input file that lives here must be
    # pushed over the socket and its option value rewritten to the name replay will know it by.
    options, input_files = collect_input_files(options)

    def parse_host_port(flag, spec):
        host, _, port_str = spec.rpartition(':')
        if not host or not port_str:
            parser.error(f'{flag} expects HOST:PORT')
        try:
            return host, int(port_str)
        except ValueError:
            parser.error(f'{flag} expects a numeric port in HOST:PORT')

    if args.connect:
        mode = 'connect'
        host, port = parse_host_port('--connect', args.connect)
    else:
        mode = 'listen'
        host, port = parse_host_port('--listen', args.listen)

    try:
        success = run_replay(options,
                             args.output_dir,
                             mode=mode,
                             host=host,
                             port=port,
                             input_files=input_files,
                             no_compress=args.no_compress,
                             slow_recv=args.slow_recv,
                             launch=args.launch,
                             launch_adb=args.launch_adb)
    except KeyboardInterrupt:
        print('\nInterrupted', file=sys.stderr)
        return 1
    except ControllerError as e:
        print(f'Error: {e}', file=sys.stderr)
        return 1

    return 0 if success else 1


if __name__ == '__main__':
    sys.exit(main())
