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

#ifndef GFXRECON_UTIL_BASE64_H
#define GFXRECON_UTIL_BASE64_H

#include "util/defines.h"

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// Standard base64 (RFC 4648) with '=' padding, no line breaks.

// Exact encoded length of size input bytes, padding included.
constexpr size_t Base64EncodedSize(size_t size)
{
    return ((size + 2) / 3) * 4;
}

std::string Base64Encode(const void* data, size_t size);

// Encodes directly into dst, which must have room for Base64EncodedSize(size) characters. Lets a caller encode into a
// buffer it already owns instead of through a temporary string.
void Base64EncodeTo(char* dst, const void* data, size_t size);

// Decodes text into out, replacing its contents. Returns false on a length or character that cannot be valid base64.
bool Base64Decode(const char* text, size_t length, std::vector<uint8_t>& out);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_BASE64_H
