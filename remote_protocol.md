# Remote Replay Protocol

> This protocol is in development and not yet stable; message types, field
> names, and CLI options may still change.

## Overview

`gfxrecon-replay` can connect to a controller process over a socket for
bidirectional I/O. The controller supplies replay settings and drives playback
(pause/resume/step/stop); replay streams back log messages, progress,
screenshots, and dump-resources files.

The core abstraction is `util::RemoteChannel`
([framework/util/remote_channel.h](framework/util/remote_channel.h)).

## Transport

| Environment | Transport | Example address |
|---|---|---|
| Any (Windows, Linux, macOS, Android) | TCP | `tcp:localhost:9001` |
| Android / Linux | Abstract Unix domain socket | `unix:@gfxrecon` |
| Linux / macOS | Filesystem Unix domain socket | `unix:/tmp/gfxrecon.sock` |

Windows targets speak TCP only: there is no abstract namespace, and the
controller has no `AF_UNIX` support there either. A `unix:` address on Windows
is rejected with an error rather than silently falling back.

Replay can establish the socket in either direction; the wire protocol is
identical once the socket exists:

- **`--remote-connect <address>`** — replay is the client, dialing out to a
  listening controller.
- **`--remote-listen <address>`** — replay is the server, accepting one
  controller that dials in. Waits up to 30 seconds for the connection.

The two options are mutually exclusive (specifying both is a fatal error). If a
remote option is set but the channel cannot be established (connection failure or
accept timeout), replay exits with failure and does not fall back to local
playback. Local CLI args are used only when neither remote option is present.

On Android these are bridged to the PC over adb:

- Listen mode: `adb reverse localabstract:gfxrecon tcp:<port>` (adbd binds the
  abstract name on the device).
- Connect mode: `adb forward tcp:<port> localabstract:gfxrecon` (adbd only
  connects to the name).

## Wire Format

Every frame is a length-prefixed byte string:

```
[uint32_t little-endian length][payload bytes]
```

- All target devices are little-endian; no byte-swapping is performed.
- No maximum frame size is enforced.
- The replay thread applies queued actions between blocks. While paused with a
  remote attached, it waits up to 10 ms on the trigger queue rather than blocking
  on window events (Android has no keyboard).
- Structured messages are UTF-8 JSON payloads. These could be migrated to a binary format such as protobuf or even GFXR's own encode/decode machinery.
- Binary file payloads are sent as a JSON `"file"` metadata frame **immediately
  followed** by a separate raw binary frame (no base64). After a `"file"`
  message the receiver treats the next frame as raw bytes.
- When [stream compression](#stream-compression) is negotiated, these frames are
  the uncompressed content of a single zstd stream. Framing is unchanged.

## Startup Handshake

```
replay     → controller:  {"type":"hello","version":"1","role":"replay",
                           "features":{"compress_input":true,
                                       "compress_output":true}}
controller → replay:      {"type":"welcome",
                           "features":{"compress_output":true}}
controller → replay:      {"type":"file","name":"dr.json","size":812}   (0..N, optional)
                          <812 raw bytes — separate binary frame, no encoding>
controller → replay:      {"type":"settings","options":{
                            "dump_resources":"dr.json",
                            "capture_file":"/sdcard/capture.gfxr"}}
replay     → controller:  {"type":"ready"}
[replay runs]
```

- Replay sends `hello` first regardless of which side dialed. `role` names the
  tool that is speaking — `replay` today, `capture` planned — and selects which
  settings schema applies. A controller that does not support the role rejects
  the connection.
- `welcome` answers `hello` and closes feature negotiation. It must be the
  controller's first message; replay fails the handshake on anything else. A
  controller rejects a connection (unsupported role or version) by disconnecting
  instead of sending `welcome`. See [Stream Compression](#stream-compression).
- `options` is a set of replay settings, from which replay rebuilds its
  `ArgumentParser`. It completely replaces the traditional command-line
  arguments. See [Settings Keys](#settings-keys).
- `settings` ends the controller's opening turn, so any `file` messages must
  precede it. Replay reads frames until `settings` arrives, which is why the
  protocol needs neither a file count nor a terminator: a controller that pushes
  no files sends nothing extra. See [Input Files](#input-files).
- A 5-second receive timeout applies during the handshake, and is cleared once
  the handshake succeeds.

## Stream Compression

Either direction may carry a compressed stream, negotiated during the handshake.
When enabled, the length-prefixed frames described above are the uncompressed
content of a single zstd stream.

### Direction naming

`compress_input` and `compress_output` are always from the tool's perspective —
the peer that sends `hello` — regardless of which end sent the message they
appear in.

| Key | Direction | Carries |
|---|---|---|
| `compress_output` | tool → controller | dumped files, screenshots, logs, progress |
| `compress_input` | controller → tool | settings, input files, triggers |

### Negotiation

`features` is a map of feature name to value. In `hello` the value states the
domain the tool accepts; in `welcome` it states the selection. For a boolean
option the domain is `true`, meaning the tool supports it.

**A key absent from `features` is off**: unsupported in `hello`, not enabled in
`welcome`. A tool advertises only the options it can perform, and the controller
selects only from the keys the tool advertised. In `welcome`, `features` itself
is optional — the message alone acknowledges `hello`, and a controller selecting
nothing omits the map.

Replay advertises neither compression key when built without
`GFXRECON_ENABLE_ZSTD_COMPRESSION`. A controller without the `zstandard` Python
package selects neither key; `--no-compress` suppresses them the same way.

Compression is zstd. It is not otherwise negotiable — see
[zstd parameters](#zstd-parameters).

### When it starts

Each direction switches immediately after `welcome`: the controller begins
decoding the tool's stream once it has sent `welcome`, and the tool begins
encoding once it has received it. `hello` and `welcome` are always uncompressed.
Everything after — `ready`, input files, and every message for the rest of the
run — uses the negotiated encoding.

Between `hello` and receiving `welcome` the tool sends nothing: the controller
arms its decoder the moment it sends `welcome`, so a frame the tool emitted
before receiving it would arrive mid-switch and desync the stream.

### zstd parameters

Fixed, not negotiated. Both ends log them at startup.

| Parameter | Value |
|---|---|
| Compression level | 1 |
| Window log | 25 (32 MiB) |
| Long-distance matching | enabled |

The stream is flushed (`ZSTD_e_flush`) after every message; no message is left
buffered in the compressor waiting for a block to fill.

The window is not negotiated. Each zstd frame header declares its own window and
the receiver adapts, bounded by zstd's default 2^27 decoder limit. The encoder
may change the window mid-run by ending the frame and starting a new one.

### Interaction with per-file compression

When `compress_output` is enabled, dump-resources per-file compression
(`BinaryFileCompressionType`) must be `none`.

## Message Schema

### Controller → replay

```json
{"type":"welcome","features":{"compress_output":true}}
{"type":"file","name":"dr.json","size":812}   // handshake only, before "settings"
<812 raw bytes — separate binary frame, no encoding>
{"type":"settings","options":{"<key>":"<value>", ...}}
{"type":"trigger","action":"pause"}   // "pause" | "resume" | "step" | "stop"
```

### Replay → controller

```json
{"type":"hello","version":"1","role":"replay","features":{...}}
{"type":"log","level":"info","message":"..."}
{"type":"progress","frame":42,"block":1234}
{"type":"operation_progress","operation":"dump_resources","current":37,"total":90}
{"type":"file","name":"dump/frame_0042.png","size":204800}
<204800 raw bytes — separate binary frame, no encoding>
{"type":"done","success":true}
```

`done` is the final message; replay disconnects after sending it.

## Compatibility

Rules for how the protocol evolves and what a peer does with what it does not
recognize:

- **Unknown JSON fields are ignored.** Adding a field to an existing message is
  always a compatible change.
- **Unknown message types during the handshake are fatal.** The handshake is
  strict lockstep; a new handshake message needs a `features` key so
  it is only sent to a peer that advertised it.
- **Unknown message types after the handshake are warned about and ignored**, in
  both directions. Adding a post-handshake message type is a compatible change,
  but the sender cannot assume it was acted on.
- **Unknown trigger actions are warned about and ignored.**
- **`version` names the handshake structure itself** — the framing and the
  hello/welcome/settings/ready sequence. New behavior rides `features` keys and
  new message types, never version bumps. A controller that does not recognize the
  version rejects the connection.

## Settings Keys

The `settings` message carries option name/value pairs rather than a command
line, so a value containing spaces needs no escaping.

**Keys derive from replay's option spellings**: strip the leading dashes and
replace `-` with `_`. There is no mapping table to maintain.

| Command line | Key |
|---|---|
| `--loop-count` | `loop_count` |
| `--mfr`, `--measurement-frame-range` | `mfr`, `measurement_frame_range` |

Any alias works; the long form is canonical. Derived spellings are not accepted
on the command line — `--log_level` is still an error there.

**The capture file** has no spelling to derive, so it takes the key
`capture_file`. Replay accepts exactly one.

**Values are always strings**, never coerced; a non-string JSON value fails the
handshake. `--cpu-mask 0011` sent as a number would arrive as a different mask.

**Options taking no command-line value** use `"true"` / `"false"`. Accepted
spellings are those `util::ParseBoolString` recognizes — `true` / `false` in any
case, or an integer string. Anything else is an error naming the key.

An unknown key is also an error naming the key, reported as received rather than
re-normalized, and fails the handshake instead of printing usage text.

The same payload shape will carry capture-side settings, whose native model is
already a `<string, string>` map. The key sets are disjoint; the shape is not.

## Progress Messages

- **Frame-level** — `{"type":"progress","frame":N,"block":B}`, emitted per replayed
  frame. Both `frame` and `block` are monotonic positions, not fractions: the
  capture file carries no total frame or block count, so no percentage is
  reported. A percentage would require a total stamped at capture time (a future
  capture-side addition) or a full pre-scan, which is impossible for a streamed
  capture. Use `block` for a finer-grained position and rate than `frame` alone.
- **Operation-level** — `{"type":"operation_progress","operation":<op>,"current":X,"total":Y}`,
  a bounded-progress message with a running total. Used by dump-resources, where
  `total` is the sum of all targeted commands (draw + dispatch + trace-rays +
  transfer).

## Playback Triggers

Triggers (`pause` / `resume` / `step` / `stop`) are received on replay's
receiver thread and queued separately from block processing. The replay thread
applies queued actions between blocks. While paused with a remote attached, it
waits up to 10 ms on the trigger queue rather than blocking on window events.

## Input Files

Every path in the `settings` options resolves on the **replay device's**
filesystem, so a file the run needs as input is unreachable when it only exists
on the controller's machine. The controller can instead push it during the
handshake and name it by the value of the matching option.

Covered options — the value is a name the controller supplied, not a device path:

| Setting | Contents |
|---|---|
| `dump_resources` | dump-resources JSON |
| `frame_warm_up_spirv` | SPIR-V module |
| `load_pipeline_cache` | pipeline cache blob |

Rules:

- A `file` message is valid only during the handshake, before `settings`.
  Replay rejects one at any other point.
- The binary frame's own length prefix is authoritative. The header's `size` is
  cross-checked against it and a mismatch fails the handshake, catching a
  controller that framed the transfer wrongly instead of letting it surface much
  later as a corrupt input file.
- `name` is a lookup key, not a path: it must be a bare filename, and it is
  matched literally against the option's value in the settings. Keep the
  extension — `--dump-resources` selects its parser by the `.json` suffix.
- A supplied file takes precedence over a same-named file on the target. An
  option value that was not supplied is left alone, so a file already staged on
  the device still works.
- Any malformed transfer fails the handshake rather than falling back, matching
  the rest of the remote feature.

What replay does with the bytes is deliberately unspecified — a controller must
not depend on where, or whether, they land on the target's filesystem.

Out of scope: `--replace-shaders` (a directory), `--replay-event-plugin-path` (a
shared library needing a real path and matching ABI), and the capture file
itself.

## File Streaming

When a channel is active (`RemoteChannel::IsActive()`), file writers stream their
output over the socket instead of writing to disk, using process-wide statics
(`SetActiveChannel` / `SendActiveFile`):

- Screenshots — `image_writer.cpp` (`WriteBmpImage` writes through a
  `MemoryOutputStream` in place of the usual `FileOutputStream`; `WritePngImage`
  collects bytes via `stbi_write_png_to_func`).
- Dump-resources buffers — `buffer_writer.cpp` (`WriteBuffer`).
- Dump-resources JSON — `vulkan_replay_dump_resources_json.cpp` (same
  `MemoryOutputStream` substitution, sent on `Close()`).

If a send fails, `IsActive()` / `IsConnected()` become false and writers fall
back to disk.

## Threading Model

`RemoteChannel` runs a sender thread and a receiver thread:

- All `Send*` calls serialize their message into a single buffer and enqueue it;
  the sender thread drains the queue in order. `SendFile` packs the JSON header
  and binary data into one buffer so they are never interleaved with another
  message.
- The receiver thread demultiplexes incoming frames into the trigger queue.
- `Disconnect()` drains and joins the sender (flushing queued messages), then
  `shutdown()`s the socket to wake the receiver, joins it, and closes.

## Reference Controller

[scripts/replay_controller.py](scripts/replay_controller.py) is a reference
controller implementation:

- `--listen HOST:PORT` — accept a connection from a `--remote-connect` replay.
- `--connect HOST:PORT` — dial out to a `--remote-listen` replay (retries a
  refused connection for up to 30 s to cover launch races).
- `--adb` — set up the appropriate adb mapping and launch the replay activity on
  a connected Android device.
- Replay settings are given after `--` as `key=value`, or as a bare key for an
  option that takes no value. Leading dashes are optional, so options keep their
  familiar spelling. Deliberately *not* a replay command line: which options take
  a value is not knowable from the tokens alone, so requiring `=` removes the
  guesswork rather than inferring it.
- Pushes local input files: when the value of an [input file option](#input-files)
  names a file on the controller's machine, it is sent during the handshake and
  the option value is rewritten to the bare filename.
- Reads `p` / `r` / `s` / `q` from stdin to send pause/resume/step/stop triggers.
- `--self-test` runs the script's doctests.

```
python scripts/replay_controller.py --connect localhost:9000 --adb -- --dump-resources=dr.json capture_file=/sdcard/capture.gfxr
```

Only the capture file has to exist on the device; `dr.json` is read from the
controller's working directory and pushed.

## Security

The protocol is unauthenticated and unencrypted, intended for trusted links:
loopback, adb-forwarded sockets, or an ssh tunnel. Do not expose either end on
an untrusted network.

- `--remote-listen` accepts the first connection from anyone who can reach the
  address; prefer loopback or adb/ssh forwarding over binding a routable
  interface.
- A connected controller fully drives replay: it chooses the settings, pushes
  input files, and receives every streamed output. Connecting is equivalent to
  running replay as that user.
- The reference controller anchors received files under `--output-dir` and
  strips path components that would escape it.

## CLI Reference

```
--remote-connect <address>   Connect out to a listening controller.
--remote-listen  <address>   Listen for and accept one controller (30 s timeout).

  <address> forms:
    tcp:host:port    TCP (all platforms)
    unix:@name       abstract Unix socket (Linux/Android)
    unix:/path       filesystem Unix socket (POSIX)
```
