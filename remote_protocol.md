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
| Desktop | TCP | `tcp:localhost:9001` |
| Android / Linux | Abstract Unix domain socket | `unix:@gfxrecon` |
| Linux | Filesystem Unix domain socket | `unix:/tmp/gfxrecon.sock` |

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

## Startup Handshake

```
replay     → controller:  {"type":"hello","version":"1"}
controller → replay:      {"type":"settings","args":"--loop-count 3 /sdcard/capture.gfxr"}
replay     → controller:  {"type":"ready"}
[replay runs]
```

- Replay sends `hello` first regardless of which side dialed.
- `args` is a complete CLI-style argument string, from which replay rebuilds its
  `ArgumentParser`. This list completely replaces the traditional command-line arguments
- A 5-second receive timeout applies during the handshake, and is cleared once
  the handshake succeeds.

## Message Schema

### Controller → replay

```json
{"type":"settings","args":"<full cli args string>"}
{"type":"trigger","action":"pause"}   // "pause" | "resume" | "step" | "stop"
```

### Replay → controller

```json
{"type":"log","level":"info","message":"..."}
{"type":"progress","frame":42,"block":1234}
{"type":"operation_progress","operation":"dump_resources","current":37,"total":90}
{"type":"file","name":"dump/frame_0042.png","size":204800}
<204800 raw bytes — separate binary frame, no encoding>
{"type":"done","success":true}
```

`done` is the final message; replay disconnects after sending it.

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

## File Streaming

When a channel is active (`RemoteChannel::IsActive()`), file writers stream their
output over the socket instead of writing to disk, using process-wide statics
(`SetActiveChannel` / `SendActiveFile`):

- Screenshots — `image_writer.cpp` (`WriteBmpImage` via `open_memstream`,
  `WritePngImage` via `stbi_write_png_to_func`).
- Dump-resources buffers — `buffer_writer.cpp` (`WriteBuffer`).
- Dump-resources JSON — `vulkan_replay_dump_resources_json.cpp` (via
  `open_memstream`).

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
- All other replay arguments after `--` are forwarded to the remote replay application
- Reads `p` / `r` / `s` / `q` from stdin to send pause/resume/step/stop triggers.

```
python scripts/replay_controller.py --connect localhost:9000 --adb -- /sdcard/capture.gfxr --dump-resources /sdcard/dr.json
```

## CLI Reference

```
--remote-connect <address>   Connect out to a listening controller.
--remote-listen  <address>   Listen for and accept one controller (30 s timeout).

  <address> forms:
    tcp:host:port    TCP (desktop)
    unix:@name       abstract Unix socket (Linux/Android)
    unix:/path       filesystem Unix socket
```
