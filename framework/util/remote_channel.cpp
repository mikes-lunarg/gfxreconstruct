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

#include "util/remote_channel.h"

#include "util/logging.h"

#if !defined(_WIN32)
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#include <cerrno>
#include <cstddef>
#include <cstring>

// macOS does not define MSG_NOSIGNAL; it uses the SO_NOSIGPIPE socket option instead (set in SetNoSigPipe below).
#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

#if !defined(_WIN32)

namespace
{
// Suppress SIGPIPE on platforms that signal it instead of honoring MSG_NOSIGNAL (e.g. macOS).
void SetNoSigPipe(int fd)
{
#ifdef SO_NOSIGPIPE
    int on = 1;
    setsockopt(fd, SOL_SOCKET, SO_NOSIGPIPE, &on, sizeof(on));
#else
    GFXRECON_UNREFERENCED_PARAMETER(fd);
#endif
}

// Convert a LoggingSeverity to the lowercase level string used in the wire protocol.
const char* SeverityToLevelString(LoggingSeverity severity)
{
    switch (severity)
    {
        case LoggingSeverity::kVerbose:
            return "verbose";
        case LoggingSeverity::kDebug:
            return "debug";
        case LoggingSeverity::kInfo:
            return "info";
        case LoggingSeverity::kWarning:
            return "warning";
        case LoggingSeverity::kError:
            return "error";
        case LoggingSeverity::kFatal:
            return "fatal";
        default:
            return "info";
    }
}

// Connect a TCP socket described by "host:port". Returns a connected fd, or -1 on failure.
int ConnectTcp(const std::string& host_port)
{
    size_t colon = host_port.find_last_of(':');
    if (colon == std::string::npos)
    {
        GFXRECON_LOG_ERROR("Remote channel: invalid TCP address '%s' (expected host:port)", host_port.c_str());
        return -1;
    }

    std::string host = host_port.substr(0, colon);
    std::string port = host_port.substr(colon + 1);

    addrinfo hints    = {};
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    addrinfo* results = nullptr;
    int       err     = getaddrinfo(host.c_str(), port.c_str(), &hints, &results);
    if (err != 0)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to resolve '%s': %s", host_port.c_str(), gai_strerror(err));
        return -1;
    }

    int fd = -1;
    for (addrinfo* ai = results; ai != nullptr; ai = ai->ai_next)
    {
        fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
        if (fd == -1)
        {
            continue;
        }
        if (connect(fd, ai->ai_addr, ai->ai_addrlen) == 0)
        {
            SetNoSigPipe(fd);
            break;
        }
        close(fd);
        fd = -1;
    }

    freeaddrinfo(results);

    if (fd == -1)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to connect to '%s'", host_port.c_str());
    }
    return fd;
}

// Connect a Unix domain socket. A leading '@' in name selects the abstract namespace. Returns a connected fd, or -1 on
// failure.
int ConnectUnix(const std::string& name)
{
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to create Unix socket: %s", strerror(errno));
        return -1;
    }

    sockaddr_un addr = {};
    addr.sun_family  = AF_UNIX;

    socklen_t addrlen = 0;
    if (!name.empty() && name[0] == '@')
    {
        // Abstract socket: leading null byte, name starts at sun_path[1], no trailing null.
        std::string abstract_name = name.substr(1);
        if (abstract_name.size() + 1 > sizeof(addr.sun_path))
        {
            GFXRECON_LOG_ERROR("Remote channel: abstract socket name '%s' is too long", name.c_str());
            close(fd);
            return -1;
        }
        addr.sun_path[0] = '\0';
        memcpy(addr.sun_path + 1, abstract_name.data(), abstract_name.size());
        addrlen = static_cast<socklen_t>(offsetof(sockaddr_un, sun_path) + 1 + abstract_name.size());
    }
    else
    {
        if (name.size() + 1 > sizeof(addr.sun_path))
        {
            GFXRECON_LOG_ERROR("Remote channel: Unix socket path '%s' is too long", name.c_str());
            close(fd);
            return -1;
        }
        memcpy(addr.sun_path, name.data(), name.size());
        addrlen = static_cast<socklen_t>(offsetof(sockaddr_un, sun_path) + name.size() + 1);
    }

    if (connect(fd, reinterpret_cast<sockaddr*>(&addr), addrlen) != 0)
    {
        GFXRECON_LOG_ERROR("Remote channel: failed to connect to Unix socket '%s': %s", name.c_str(), strerror(errno));
        close(fd);
        return -1;
    }

    SetNoSigPipe(fd);
    return fd;
}
} // namespace

bool RemoteChannel::Connect(const std::string& address)
{
    Disconnect();

    constexpr const char kTcpPrefix[]  = "tcp:";
    constexpr const char kUnixPrefix[] = "unix:";

    if (address.rfind(kTcpPrefix, 0) == 0)
    {
        fd_ = ConnectTcp(address.substr(sizeof(kTcpPrefix) - 1));
    }
    else if (address.rfind(kUnixPrefix, 0) == 0)
    {
        fd_ = ConnectUnix(address.substr(sizeof(kUnixPrefix) - 1));
    }
    else
    {
        GFXRECON_LOG_ERROR("Remote channel: unrecognized address '%s' (expected tcp: or unix: prefix)",
                           address.c_str());
        return false;
    }

    if (fd_ == -1)
    {
        return false;
    }

    sender_thread_ = std::thread(&RemoteChannel::SenderThread, this);
    return true;
}

bool RemoteChannel::IsConnected() const
{
    return (fd_ != -1) && !send_failed_;
}

void RemoteChannel::Disconnect()
{
    if (sender_thread_.joinable())
    {
        // Flush: the sender thread drains the queue before honoring the stop request.
        {
            const std::lock_guard<std::mutex> lock(queue_mutex_);
            stop_requested_ = true;
        }
        queue_cv_.notify_one();
        sender_thread_.join();
    }

    if (fd_ != -1)
    {
        // Wake the receiver thread out of a blocking recv before closing the descriptor.
        shutdown(fd_, SHUT_RDWR);
    }
    if (receiver_thread_.joinable())
    {
        receiver_thread_.join();
    }

    if (fd_ != -1)
    {
        close(fd_);
        fd_ = -1;
    }

    send_queue_.clear();
    trigger_queue_.clear();
    stop_requested_ = false;
    send_failed_    = false;
}

std::string RemoteChannel::Handshake()
{
    if (fd_ == -1)
    {
        return "";
    }

    SendJson({ { "type", "hello" }, { "version", "1" } });

    // Bound the handshake receive so a missing/unresponsive controller does not hang startup.
    timeval timeout = {};
    timeout.tv_sec  = 5;
    setsockopt(fd_, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    std::vector<uint8_t> frame;
    if (!RecvFrame(frame))
    {
        GFXRECON_LOG_ERROR("Remote channel: handshake failed waiting for settings");
        return "";
    }

    std::string    args;
    nlohmann::json msg = nlohmann::json::parse(frame.begin(), frame.end(), nullptr, false);
    if (msg.is_discarded() || !msg.contains("type") || msg["type"] != "settings")
    {
        GFXRECON_LOG_ERROR("Remote channel: handshake received unexpected message");
        return "";
    }
    args = msg.value("args", std::string());
    if (args.empty())
    {
        GFXRECON_LOG_ERROR("Remote channel: controller provided empty settings args");
        return "";
    }

    SendJson({ { "type", "ready" } });

    // Restore blocking receives for the receiver thread, which queues trigger messages from the controller.
    timeout = {};
    setsockopt(fd_, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    receiver_thread_ = std::thread(&RemoteChannel::ReceiverThread, this);

    return args;
}

bool RemoteChannel::TryPopTrigger(std::string* action)
{
    GFXRECON_ASSERT(action != nullptr);

    const std::lock_guard<std::mutex> lock(trigger_mutex_);
    if (trigger_queue_.empty())
    {
        return false;
    }
    *action = std::move(trigger_queue_.front());
    trigger_queue_.pop_front();
    return true;
}

bool RemoteChannel::WaitPopTrigger(std::string* action, std::chrono::milliseconds timeout)
{
    GFXRECON_ASSERT(action != nullptr);

    std::unique_lock<std::mutex> lock(trigger_mutex_);
    if (!trigger_cv_.wait_for(lock, timeout, [this] { return !trigger_queue_.empty(); }))
    {
        return false;
    }
    *action = std::move(trigger_queue_.front());
    trigger_queue_.pop_front();
    return true;
}

void RemoteChannel::SendJson(const nlohmann::json& msg)
{
    if (!IsConnected())
    {
        return;
    }

    std::string          payload = msg.dump();
    std::vector<uint8_t> buffer;
    buffer.reserve(sizeof(uint32_t) + payload.size());
    AppendFrame(buffer, payload.data(), static_cast<uint32_t>(payload.size()));
    EnqueueFrames(std::move(buffer));
}

void RemoteChannel::SendFile(const std::string& name, const void* data, size_t size)
{
    if (!IsConnected())
    {
        return;
    }

    nlohmann::json header  = { { "type", "file" }, { "name", name }, { "size", size } };
    std::string    payload = header.dump();

    // Queue both frames as one buffer so the JSON header and binary data are never interleaved with other senders.
    std::vector<uint8_t> buffer;
    buffer.reserve((2 * sizeof(uint32_t)) + payload.size() + size);
    AppendFrame(buffer, payload.data(), static_cast<uint32_t>(payload.size()));
    AppendFrame(buffer, data, static_cast<uint32_t>(size));
    EnqueueFrames(std::move(buffer));
}

void RemoteChannel::SendLog(LoggingSeverity severity, const std::string& message)
{
    SendJson({ { "type", "log" }, { "level", SeverityToLevelString(severity) }, { "message", message } });
}

void RemoteChannel::SendProgress(uint64_t frame)
{
    SendJson({ { "type", "progress" }, { "frame", frame } });
}

void RemoteChannel::SendDone(bool success)
{
    SendJson({ { "type", "done" }, { "success", success } });
    Disconnect();
}

void RemoteChannel::AppendFrame(std::vector<uint8_t>& buffer, const void* data, uint32_t size)
{
    uint32_t length = size; // All target devices are little-endian; no byte-swap needed.
    const auto* length_bytes = reinterpret_cast<const uint8_t*>(&length);
    buffer.insert(buffer.end(), length_bytes, length_bytes + sizeof(length));
    const auto* data_bytes = static_cast<const uint8_t*>(data);
    buffer.insert(buffer.end(), data_bytes, data_bytes + size);
}

void RemoteChannel::EnqueueFrames(std::vector<uint8_t>&& buffer)
{
    {
        const std::lock_guard<std::mutex> lock(queue_mutex_);
        if (stop_requested_ || send_failed_)
        {
            return;
        }
        send_queue_.push_back(std::move(buffer));
    }
    queue_cv_.notify_one();
}

void RemoteChannel::ReceiverThread()
{
    std::vector<uint8_t> frame;
    while (RecvFrame(frame))
    {
        nlohmann::json msg = nlohmann::json::parse(frame.begin(), frame.end(), nullptr, false);
        if (msg.is_discarded() || !msg.contains("type"))
        {
            GFXRECON_LOG_WARNING("Remote channel: ignoring malformed message from controller");
            continue;
        }

        if (msg["type"] == "trigger")
        {
            std::string action = msg.value("action", std::string());
            if (action.empty())
            {
                GFXRECON_LOG_WARNING("Remote channel: ignoring trigger message without an action");
                continue;
            }
            {
                const std::lock_guard<std::mutex> lock(trigger_mutex_);
                trigger_queue_.push_back(std::move(action));
            }
            trigger_cv_.notify_one();
        }
        else
        {
            GFXRECON_LOG_WARNING("Remote channel: ignoring unexpected message type '%s'", msg["type"].dump().c_str());
        }
    }

    // The controller disconnected or Disconnect() shut the socket down.
}

void RemoteChannel::SenderThread()
{
    for (;;)
    {
        std::vector<uint8_t> buffer;
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            queue_cv_.wait(lock, [this] { return stop_requested_ || !send_queue_.empty(); });
            if (send_queue_.empty())
            {
                return; // Stop requested and queue drained.
            }
            buffer = std::move(send_queue_.front());
            send_queue_.pop_front();
        }

        if (!SendAll(buffer.data(), buffer.size()))
        {
            // The controller went away; drop queued messages and report the channel as disconnected.
            send_failed_ = true;
            const std::lock_guard<std::mutex> lock(queue_mutex_);
            send_queue_.clear();
            return;
        }
    }
}

bool RemoteChannel::RecvFrame(std::vector<uint8_t>& out)
{
    uint32_t length = 0;
    if (!RecvExact(&length, sizeof(length)))
    {
        return false;
    }

    out.resize(length);
    if (length == 0)
    {
        return true;
    }
    return RecvExact(out.data(), length);
}

bool RemoteChannel::SendAll(const void* buf, size_t size)
{
    const uint8_t* ptr       = static_cast<const uint8_t*>(buf);
    size_t         remaining = size;
    while (remaining > 0)
    {
        ssize_t sent = send(fd_, ptr, remaining, MSG_NOSIGNAL);
        if (sent <= 0)
        {
            if (sent < 0 && errno == EINTR)
            {
                continue;
            }
            return false;
        }
        ptr += sent;
        remaining -= static_cast<size_t>(sent);
    }
    return true;
}

bool RemoteChannel::RecvExact(void* buf, size_t size)
{
    uint8_t* ptr       = static_cast<uint8_t*>(buf);
    size_t   remaining = size;
    while (remaining > 0)
    {
        ssize_t received = recv(fd_, ptr, remaining, 0);
        if (received <= 0)
        {
            if (received < 0 && errno == EINTR)
            {
                continue;
            }
            return false;
        }
        ptr += received;
        remaining -= static_cast<size_t>(received);
    }
    return true;
}

#else // WIN32: socket transport is not supported; all methods are no-ops.

bool RemoteChannel::Connect(const std::string& address)
{
    GFXRECON_UNREFERENCED_PARAMETER(address);
    return false;
}

bool RemoteChannel::IsConnected() const
{
    return false;
}

void RemoteChannel::Disconnect() {}

std::string RemoteChannel::Handshake()
{
    return "";
}

bool RemoteChannel::TryPopTrigger(std::string* action)
{
    GFXRECON_UNREFERENCED_PARAMETER(action);
    return false;
}

bool RemoteChannel::WaitPopTrigger(std::string* action, std::chrono::milliseconds timeout)
{
    GFXRECON_UNREFERENCED_PARAMETER(action);
    GFXRECON_UNREFERENCED_PARAMETER(timeout);
    return false;
}

void RemoteChannel::SendJson(const nlohmann::json& msg)
{
    GFXRECON_UNREFERENCED_PARAMETER(msg);
}

void RemoteChannel::SendFile(const std::string& name, const void* data, size_t size)
{
    GFXRECON_UNREFERENCED_PARAMETER(name);
    GFXRECON_UNREFERENCED_PARAMETER(data);
    GFXRECON_UNREFERENCED_PARAMETER(size);
}

void RemoteChannel::SendLog(LoggingSeverity severity, const std::string& message)
{
    GFXRECON_UNREFERENCED_PARAMETER(severity);
    GFXRECON_UNREFERENCED_PARAMETER(message);
}

void RemoteChannel::SendProgress(uint64_t frame)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame);
}

void RemoteChannel::SendDone(bool success)
{
    GFXRECON_UNREFERENCED_PARAMETER(success);
}

bool RemoteChannel::RecvFrame(std::vector<uint8_t>& out)
{
    GFXRECON_UNREFERENCED_PARAMETER(out);
    return false;
}

bool RemoteChannel::SendAll(const void* buf, size_t size)
{
    GFXRECON_UNREFERENCED_PARAMETER(buf);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    return false;
}

bool RemoteChannel::RecvExact(void* buf, size_t size)
{
    GFXRECON_UNREFERENCED_PARAMETER(buf);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    return false;
}

#endif // !defined(_WIN32)

// The active-channel registry is platform-independent; IsActive() / SendActiveFile() are compiled everywhere.
// SendFile() is a no-op on Windows stubs, so the channel-active path is reachable but harmless there.
RemoteChannel* RemoteChannel::active_channel_ = nullptr;

void RemoteChannel::SetActiveChannel(RemoteChannel* channel)
{
    active_channel_ = channel;
}

bool RemoteChannel::IsActive()
{
    return active_channel_ != nullptr && active_channel_->IsConnected();
}

void RemoteChannel::SendActiveFile(const std::string& name, const void* data, size_t size)
{
    RemoteChannel* channel = active_channel_;
    if (channel != nullptr && channel->IsConnected())
    {
        channel->SendFile(name, data, size);
    }
}

void RemoteChannel::SendActiveProgress(const char* operation, uint64_t current, uint64_t total)
{
    RemoteChannel* channel = active_channel_;
    if (channel != nullptr && channel->IsConnected())
    {
        channel->SendJson({ { "type", "operation_progress" },
                            { "operation", operation },
                            { "current", current },
                            { "total", total } });
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
