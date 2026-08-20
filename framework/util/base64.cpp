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

#include "util/base64.h"

#include <array>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

static constexpr char kEncodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

constexpr uint8_t kInvalid = 0xff;

// 0xff for anything that is not a base64 digit; '=' is handled by the caller, not the table.
static constexpr std::array<uint8_t, 256> BuildDecodeTable()
{
    std::array<uint8_t, 256> table{};
    for (size_t i = 0; i < table.size(); ++i)
    {
        table[i] = kInvalid;
    }
    for (uint8_t i = 0; i < 64; ++i)
    {
        table[static_cast<uint8_t>(kEncodeTable[i])] = i;
    }
    return table;
}

static constexpr std::array<uint8_t, 256> kDecodeTable = BuildDecodeTable();

std::string Base64Encode(const void* data, size_t size)
{
    std::string out;
    out.resize(Base64EncodedSize(size));
    Base64EncodeTo(out.data(), data, size);
    return out;
}

void Base64EncodeTo(char* dst, const void* data, size_t size)
{
    const auto* bytes = static_cast<const uint8_t*>(data);

    size_t left = size;

    while (left >= 3)
    {
        const uint32_t triple = (static_cast<uint32_t>(bytes[0]) << 16) | (static_cast<uint32_t>(bytes[1]) << 8) |
                                static_cast<uint32_t>(bytes[2]);
        dst[0] = kEncodeTable[(triple >> 18) & 0x3f];
        dst[1] = kEncodeTable[(triple >> 12) & 0x3f];
        dst[2] = kEncodeTable[(triple >> 6) & 0x3f];
        dst[3] = kEncodeTable[triple & 0x3f];
        bytes += 3;
        dst += 4;
        left -= 3;
    }

    if (left == 1)
    {
        const uint32_t triple = static_cast<uint32_t>(bytes[0]) << 16;
        dst[0]                = kEncodeTable[(triple >> 18) & 0x3f];
        dst[1]                = kEncodeTable[(triple >> 12) & 0x3f];
        dst[2]                = '=';
        dst[3]                = '=';
    }
    else if (left == 2)
    {
        const uint32_t triple = (static_cast<uint32_t>(bytes[0]) << 16) | (static_cast<uint32_t>(bytes[1]) << 8);
        dst[0]                = kEncodeTable[(triple >> 18) & 0x3f];
        dst[1]                = kEncodeTable[(triple >> 12) & 0x3f];
        dst[2]                = kEncodeTable[(triple >> 6) & 0x3f];
        dst[3]                = '=';
    }
}

bool Base64Decode(const char* text, size_t length, std::vector<uint8_t>& out)
{
    out.clear();

    if ((length % 4) != 0)
    {
        return false;
    }
    if (length == 0)
    {
        return true;
    }

    size_t padding = 0;
    if (text[length - 1] == '=')
    {
        ++padding;
        if (text[length - 2] == '=')
        {
            ++padding;
        }
    }

    out.resize(((length / 4) * 3) - padding);

    uint8_t*     dst   = out.data();
    uint8_t*     end   = dst + out.size();
    const size_t quads = length / 4;

    for (size_t quad = 0; quad < quads; ++quad)
    {
        const char* src = text + (quad * 4);

        uint32_t group = 0;
        for (int i = 0; i < 4; ++i)
        {
            const uint8_t decoded = kDecodeTable[static_cast<uint8_t>(src[i])];
            if (decoded == kInvalid)
            {
                // Padding is only legal in the final quad, and only in its last two positions.
                if ((src[i] == '=') && (quad == (quads - 1)) && (i >= 2))
                {
                    group <<= 6;
                    continue;
                }
                out.clear();
                return false;
            }
            group = (group << 6) | decoded;
        }

        // The tail quad writes 1 or 2 bytes rather than 3; the bits under the padding are discarded.
        const uint8_t triple[3] = { static_cast<uint8_t>((group >> 16) & 0xff),
                                    static_cast<uint8_t>((group >> 8) & 0xff),
                                    static_cast<uint8_t>(group & 0xff) };
        for (int i = 0; (i < 3) && (dst < end); ++i)
        {
            *dst++ = triple[i];
        }
    }

    return true;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
