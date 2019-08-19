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

#ifndef GFXRECON_APPLICATION_NULL_WINDOW_H
#define GFXRECON_APPLICATION_NULL_WINDOW_H

#include "application/null_application.h"
#include "decode/window.h"
#include "util/defines.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

class NullWindow : public decode::Window
{
  public:
    NullWindow(NullApplication* application);

    virtual ~NullWindow() override {}

    virtual bool Create(const std::string&, const int32_t, const int32_t, const uint32_t, const uint32_t) override
    {
        return true;
    }

    virtual bool Destroy() override { return true; }

    virtual void SetTitle(const std::string&) override {}

    virtual void SetPosition(const int32_t, const int32_t) override {}

    virtual void SetSize(const uint32_t width, const uint32_t height) override {}

    virtual void SetVisibility(bool) override {}

    virtual void SetForeground() override {}

    virtual bool GetNativeHandle(uint32_t id, void** handle) override;

    virtual VkResult CreateSurface(const encode::InstanceTable* table,
                                   VkInstance                   instance,
                                   VkFlags                      flags,
                                   VkSurfaceKHR*                pSurface) override;

  private:
    NullApplication* null_application_;
};

class NullWindowFactory : public decode::WindowFactory
{
  public:
    NullWindowFactory(NullApplication* application);

    virtual ~NullWindowFactory();

    virtual const char* GetSurfaceExtensionName() const override { return nullptr; }

    virtual decode::Window*
    Create(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;

    void Destroy(decode::Window* window) override;

    virtual VkBool32 GetPhysicalDevicePresentationSupport(const encode::InstanceTable* table,
                                                          VkPhysicalDevice             physical_device,
                                                          uint32_t                     queue_family_index) override;

  private:
    NullApplication* null_application_;
};

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_APPLICATION_NULL_WINDOW_H
