/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "application/null_window.h"

#include "util/logging.h"

#include <cassert>
#include <cstdlib>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

NullWindow::NullWindow(NullApplication* application) :
    null_application_(application)
{
    assert((application != nullptr));
}

bool NullWindow::GetNativeHandle(uint32_t id, void** handle)
{
    assert(handle != nullptr);
    *handle = reinterpret_cast<void*>(this);
    return true;
}

VkResult NullWindow::CreateSurface(const encode::InstanceTable* table,
                                      VkInstance                   instance,
                                      VkFlags                      flags,
                                      VkSurfaceKHR*                pSurface)
{
    return VK_ERROR_OUT_OF_HOST_MEMORY;
}

NullWindowFactory::NullWindowFactory(NullApplication* application) : null_application_(application)
{
    assert(application != nullptr);
}

NullWindowFactory::~NullWindowFactory() {}

decode::Window*
NullWindowFactory::Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    GFXRECON_UNREFERENCED_PARAMETER(x);
    GFXRECON_UNREFERENCED_PARAMETER(y);
    GFXRECON_UNREFERENCED_PARAMETER(width);
    GFXRECON_UNREFERENCED_PARAMETER(height);

    return nullptr;
}

void NullWindowFactory::Destroy(decode::Window* window)
{
    GFXRECON_UNREFERENCED_PARAMETER(window);
}

VkBool32 NullWindowFactory::GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                                    VkPhysicalDevice             physical_device,
                                                                    uint32_t                     queue_family_index)
{
    GFXRECON_UNREFERENCED_PARAMETER(table);
    GFXRECON_UNREFERENCED_PARAMETER(physical_device);
    GFXRECON_UNREFERENCED_PARAMETER(queue_family_index);

    return VK_TRUE;
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
