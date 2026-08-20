/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_UTIL_REMOTE_CHANNEL_H
#define GFXRECON_UTIL_REMOTE_CHANNEL_H

#include "util/defines.h"
#include "util/logging_common.h"

#include "nlohmann/json.hpp"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <map>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Winsock's SOCKET is unsigned and pointer-sized; POSIX uses an int descriptor. Aliased to keep winsock2.h out of
// this header.
#if defined(_WIN32)
using SocketHandle = uintptr_t;
#else
using SocketHandle = int;
#endif

constexpr SocketHandle kInvalidSocket = static_cast<SocketHandle>(-1); // Also Winsock's INVALID_SOCKET.

// RemoteChannel links gfxrecon-replay to a controller process over a socket for bidirectional I/O. The controller
// sends replay settings; replay sends back log messages, progress, screenshots, and dump-resources files. Replay can
// establish the socket either as the client (Connect(), dialing out to a listening controller) or as the server
// (Listen(), accepting a controller that dials in). Once the socket exists, everything downstream is identical.
//
// Wire format: each frame is a little-endian uint32_t length prefix followed by that many payload bytes. Structured
// messages are JSON frames. A binary file payload is sent as a JSON "file" metadata frame immediately followed by a raw
// binary frame.
class RemoteChannel
{
  public:
    RemoteChannel() = default;
    ~RemoteChannel() { Disconnect(); }

    RemoteChannel(const RemoteChannel&)            = delete;
    RemoteChannel& operator=(const RemoteChannel&) = delete;

    // Connect to the controller. Address forms:
    //   "tcp:host:port"  - TCP connection (all platforms)
    //   "unix:@name"     - abstract Unix domain socket (Linux/Android)
    //   "unix:/path"     - filesystem-backed Unix domain socket (POSIX)
    // Returns true on success.
    bool Connect(const std::string& address);

    // Listen for a controller instead of dialing out. Binds and listens on address (same forms as Connect), then
    // accepts a single controller connection, waiting up to a bounded timeout. On success fd_ holds the accepted
    // socket and downstream use is identical to Connect(). Returns false on bind/listen failure or accept timeout.
    bool Listen(const std::string& address);

    bool IsConnected() const;
    void Disconnect();

    // Perform the startup handshake. Sends "hello", waits for a "settings" message, then sends "ready". On success
    // fills settings with the controller-supplied option name/value pairs (keys as described by ArgumentParser's
    // settings-map constructor, values always strings) and starts a receiver thread that queues incoming "trigger"
    // messages for retrieval with TryPopTrigger() / WaitPopTrigger().
    bool Handshake(std::map<std::string, std::string>& settings);

    // Pop the next controller-requested trigger action ("pause", "resume", "step", "stop", ...), if any. Thread-safe.
    // WaitPopTrigger blocks for up to timeout waiting for an action to arrive.
    bool TryPopTrigger(std::string* action);
    bool WaitPopTrigger(std::string* action, std::chrono::milliseconds timeout);

    // The following are thread-safe, non-blocking, and no-ops when disconnected. Messages are queued and delivered
    // in order by a background sender thread; if a send fails, queued messages are dropped and the channel reports
    // disconnected. Disconnect() flushes any queued messages before closing the socket.
    void SendJson(const nlohmann::json& msg);
    void SendFile(const std::string& name, const void* data, size_t size);
    void SendLog(LoggingSeverity severity, const std::string& message);
    void SendProgress(uint64_t frame, uint64_t block);
    void SendDone(bool success); // Also calls Disconnect().

    // PROTOTYPE: when enabled, SendFile carries its payload as a base64 string inside the JSON "file" message instead
    // of as a following raw binary frame. Set from --remote-base64 after the handshake, which is before any file is
    // streamed. Inbound files are self-describing (each "file" message names its own encoding), so receiving does not
    // depend on this flag.
    void SetBase64Files(bool enable) { base64_files_ = enable; }

    // PROTOTYPE: log the accumulated file-transfer cost (payload vs. wire bytes, base64 and packing time). Call before
    // SendDone so the summary still reaches the controller.
    void LogFileTransferStats() const;

    // Register (or clear, with nullptr) the process-wide channel. Called once during remote setup and cleared during
    // shutdown, both on the main thread.
    static void SetActiveChannel(RemoteChannel* channel);

    // Returns true when a connected channel is registered. File writers check this before deciding to skip disk I/O.
    static bool IsActive();

    // Send data to the active channel as a "file" message; a no-op when no channel is registered or connected. Lets
    // file writers (screenshots, dump-resources) stream their output without threading a channel pointer through the
    // decode layer.
    static void SendActiveFile(const std::string& name, const void* data, size_t size);

    // Report progress of a bounded operation (with a total, unlike frame-level SendProgress) on the active channel; a
    // no-op when no channel is connected. Emits {"type":"operation_progress","operation":<op>,"current":X,"total":Y}.
    static void SendActiveProgress(const char* operation, uint64_t current, uint64_t total);

    // Relay a log message to the active channel; a no-op when no channel is registered or connected. Lets the logging
    // module's remote target reach the channel without holding a pointer to it. Safe to call from any thread, and from
    // within a log call: the send path never logs, so it cannot re-enter logging.
    static void SendActiveLog(LoggingSeverity severity, const std::string& message);

  private:
    // Append a length-prefixed frame to buffer.
    static void AppendFrame(std::vector<uint8_t>& buffer, const void* data, uint32_t size);

    // Queue a pre-framed buffer for the sender thread; drops the buffer when disconnected or after a send failure.
    void EnqueueFrames(std::vector<uint8_t>&& buffer);

    // Sender thread entry point: sends queued buffers in order until stopped or a send fails.
    void SenderThread();

    // Receiver thread entry point: queues incoming trigger actions until the controller disconnects.
    void ReceiverThread();

    // Handle a handshake "file" message: receive the binary frame that follows header and hand it to the input file
    // store. Returns false on a malformed transfer, which fails the handshake.
    bool ReceiveInputFile(const nlohmann::json& header);

    bool RecvFrame(std::vector<uint8_t>& out);
    bool SendAll(const void* buf, size_t size);
    bool RecvExact(void* buf, size_t size);

    SocketHandle fd_{ kInvalidSocket };
    SocketHandle listen_fd_{ kInvalidSocket }; // Closed once a connection is accepted.

    std::thread                      sender_thread_;
    std::mutex                       queue_mutex_;
    std::condition_variable          queue_cv_;
    std::deque<std::vector<uint8_t>> send_queue_;              // Guarded by queue_mutex_.
    bool                             stop_requested_{ false }; // Guarded by queue_mutex_.
    std::atomic<bool>                send_failed_{ false };

    // PROTOTYPE: base64 file payloads, and the cost of producing them. Counters are written from whichever thread
    // calls SendFile, so they are atomic.
    bool                  base64_files_{ false };
    std::atomic<uint64_t> stat_files_{ 0 };
    std::atomic<uint64_t> stat_payload_bytes_{ 0 }; // File contents before any encoding.
    std::atomic<uint64_t> stat_wire_bytes_{ 0 };    // Framed bytes queued for the socket.
    std::atomic<uint64_t> stat_encode_ns_{ 0 };     // Base64 conversion only.
    std::atomic<uint64_t> stat_pack_ns_{ 0 };       // All of SendFile: encode, JSON dump, and buffer copies.

    std::thread             receiver_thread_;
    std::mutex              trigger_mutex_;
    std::condition_variable trigger_cv_;
    std::deque<std::string> trigger_queue_; // Guarded by trigger_mutex_.

    // Process-wide channel used by the static SendActive*() helpers. Only one controller connection exists per
    // process.
    static RemoteChannel* active_channel_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_REMOTE_CHANNEL_H
