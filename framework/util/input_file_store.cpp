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

#include "util/input_file_store.h"

#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cerrno>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

namespace
{
// Prefix shared by every run's scratch directory; the process id follows it.
constexpr const char* kScratchPrefix = "gfxrecon-remote-";

// Function-local statics avoid static initialization order problems and are initialized thread-safely.
std::string& ScratchRoot()
{
    static std::string root;
    return root;
}

std::string& ScratchDir()
{
    static std::string dir;
    return dir;
}

std::unordered_map<std::string, std::string>& Files()
{
    static std::unordered_map<std::string, std::string> files;
    return files;
}

// Removes directories abandoned by runs that never reached Cleanup() (hard kill, crash, am force-stop). Skipping live
// pids is what makes this safe to run while other replays are in flight.
void ReapStaleDirectories(const std::filesystem::path& root)
{
    const auto self = platform::GetCurrentProcessId();

    std::error_code error;
    for (const auto& entry : std::filesystem::directory_iterator(root, error))
    {
        const std::string name = entry.path().filename().string();
        if (name.compare(0, strlen(kScratchPrefix), kScratchPrefix) != 0)
        {
            continue;
        }

        const std::string suffix = name.substr(strlen(kScratchPrefix));
        if (suffix.empty() || (suffix.find_first_not_of("0123456789") != std::string::npos))
        {
            continue;
        }

        const auto pid = static_cast<decltype(self)>(strtoull(suffix.c_str(), nullptr, 10));
        if ((pid == self) || platform::IsProcessRunning(pid))
        {
            continue;
        }

        std::error_code remove_error;
        std::filesystem::remove_all(entry.path(), remove_error);
        if (!remove_error)
        {
            GFXRECON_LOG_INFO("Input file store: removed input files left behind by process %" PRIu64,
                              static_cast<uint64_t>(pid));
        }
    }

    // An unreadable root is not an error; this run's own directory may still be creatable.
    GFXRECON_UNREFERENCED_PARAMETER(error);
}

// Create the scratch directory on first use, returning its path or an empty string on failure.
const std::string& EnsureScratchDir()
{
    std::string& dir = ScratchDir();
    if (!dir.empty())
    {
        return dir;
    }

    std::error_code       error;
    std::filesystem::path root = ScratchRoot();
    if (root.empty())
    {
        root = std::filesystem::temp_directory_path(error);
        if (error)
        {
            GFXRECON_LOG_ERROR("Input file store: could not determine a temporary directory (%s)",
                               error.message().c_str());
            return dir;
        }
    }

    ReapStaleDirectories(root);

    // The pid keeps concurrent replays from colliding and makes an abandoned directory attributable.
    const std::string candidate =
        filepath::Join(root.string(), kScratchPrefix + std::to_string(platform::GetCurrentProcessId()));

    // Not filepath::MakeDirectory: it fails when the directory exists, as it does when a pid is recycled.
    std::filesystem::create_directories(candidate, error);
    if (error)
    {
        GFXRECON_LOG_ERROR(
            "Input file store: could not create directory %s (%s)", candidate.c_str(), error.message().c_str());
        return dir;
    }

    dir = candidate;
    return dir;
}
} // namespace

void InputFileStore::SetScratchRoot(const std::string& root)
{
    ScratchRoot() = root;
}

bool InputFileStore::Add(const std::string& name, const std::vector<uint8_t>& data)
{
    // Using only the basename makes traversal impossible rather than merely mitigated. The extension must survive:
    // --dump-resources selects the Vulkan parser on a ".json" suffix.
    const std::string base = filepath::GetFilename(name);
    if (base.empty() || (base == ".") || (base == ".."))
    {
        GFXRECON_LOG_ERROR("Input file store: \"%s\" is not a usable file name", name.c_str());
        return false;
    }

    const std::string& dir = EnsureScratchDir();
    if (dir.empty())
    {
        return false;
    }

    const std::string path = filepath::Join(dir, base);

    // Not buffer_writer::WriteBuffer: with a channel active it would send the file back to the controller.
    FILE* file = nullptr;
    if ((platform::FileOpen(&file, path.c_str(), "wb") != 0) || (file == nullptr))
    {
        GFXRECON_LOG_ERROR("Input file store: could not open %s for writing (%s)", path.c_str(), strerror(errno));
        return false;
    }

    const bool written = data.empty() || platform::FileWrite(data.data(), data.size(), file);
    platform::FileClose(file);

    if (!written)
    {
        GFXRECON_LOG_ERROR("Input file store: could not write %s", path.c_str());
        return false;
    }

    Files()[name] = path;
    return true;
}

const std::string* InputFileStore::Resolve(const std::string& name)
{
    const auto entry = Files().find(name);
    return (entry != Files().end()) ? &entry->second : nullptr;
}

void InputFileStore::Cleanup()
{
    std::string& dir = ScratchDir();
    if (!dir.empty())
    {
        std::error_code error;
        std::filesystem::remove_all(dir, error);
        if (error)
        {
            GFXRECON_LOG_WARNING(
                "Input file store: could not remove directory %s (%s)", dir.c_str(), error.message().c_str());
        }
        dir.clear();
    }

    Files().clear();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
