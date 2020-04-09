
/*
** Copyright (c) 2020 Valve Corporation
** Copyright (c) 2020 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_UTIL_KEYBOARD_H
#define GFXRECON_UTIL_KEYBOARD_H

#include "util/defines.h"

#include <string>

#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb_keysyms.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

class Keyboard
{
  public:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    void Initialize(xcb_connection_t* connection);
#endif
    bool GetKeyState(const std::string& key);

    Keyboard()
    {
#if defined(VK_USE_PLATFORM_XCB_KHR)
        xcb_connection_ = nullptr;
#endif
    }

  private:
#if defined(VK_USE_PLATFORM_XCB_KHR)
    xcb_connection_t* xcb_connection_;
#endif
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_KEYBOARD_H
