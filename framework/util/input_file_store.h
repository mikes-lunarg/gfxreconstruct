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

#ifndef GFXRECON_UTIL_INPUT_FILE_STORE_H
#define GFXRECON_UTIL_INPUT_FILE_STORE_H

#include "util/defines.h"

#include <cstdint>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Holds the input files a remote controller pushes during the handshake, in a per-process scratch directory, so that
// read sites downstream open an ordinary path and need no knowledge of the remote channel.
//
// Written only during the handshake, read-only afterwards, so no locking is needed.
class InputFileStore
{
  public:
    // Root to create the scratch directory under. Android must set this; desktop defaults to the temp directory.
    static void SetScratchRoot(const std::string& root);

    // Writes name's contents into the scratch directory, using only its basename so a controller cannot direct the
    // write elsewhere. Returns false on failure, which fails the handshake. Also reaps directories abandoned by runs
    // that never reached Cleanup().
    static bool Add(const std::string& name, const std::vector<uint8_t>& data);

    // Path to a previously added file, or nullptr when name was not supplied by the controller.
    static const std::string* Resolve(const std::string& name);

    // Removes the scratch directory and everything in it.
    static void Cleanup();
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_INPUT_FILE_STORE_H
