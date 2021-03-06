/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_handle_mappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename T>
static void MapHandleArray(const format::HandleId*   ids,
                           T*                        handles,
                           size_t                    len,
                           const VulkanObjectMapper& object_mapper,
                           T (VulkanObjectMapper::*MapFunc)(format::HandleId) const)
{
    if ((ids != nullptr) && (handles != nullptr))
    {
        for (size_t i = 0; i < len; ++i)
        {
            handles[i] = (object_mapper.*MapFunc)(ids[i]);
        }
    }
}

void MapStructHandles(Decoded_VkDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkSubmitInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSubmitInfo* value = wrapper->value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapHandleArray<VkCommandBuffer>(wrapper->pCommandBuffers.GetPointer(), wrapper->pCommandBuffers.GetHandlePointer(), wrapper->pCommandBuffers.GetLength(), object_mapper, &VulkanObjectMapper::MapVkCommandBuffer);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void MapStructHandles(Decoded_VkMemoryAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkMappedMemoryRange* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMappedMemoryRange* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseMemoryBind* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseMemoryBind* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBind* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryBind* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBind>(wrapper->pBinds.GetMetaStructPointer(), wrapper->pBinds.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindSparseInfo* value = wrapper->value;

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds.GetMetaStructPointer(), wrapper->pBufferBinds.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds.GetMetaStructPointer(), wrapper->pImageOpaqueBinds.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds.GetMetaStructPointer(), wrapper->pImageBinds.GetLength(), object_mapper);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void MapStructHandles(Decoded_VkBufferViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferViewCreateInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkImageViewCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageViewCreateInfo* value = wrapper->value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkShaderModuleCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkPipelineShaderStageCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineShaderStageCreateInfo* value = wrapper->value;

        value->module = object_mapper.MapVkShaderModule(wrapper->module);
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGraphicsPipelineCreateInfo* value = wrapper->value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages.GetMetaStructPointer(), wrapper->pStages.GetLength(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->value;

        MapStructHandles(&wrapper->stage, object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkPipelineLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPipelineLayoutCreateInfo* value = wrapper->value;

        MapHandleArray<VkDescriptorSetLayout>(wrapper->pSetLayouts.GetPointer(), wrapper->pSetLayouts.GetHandlePointer(), wrapper->pSetLayouts.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
}

void MapStructHandles(Decoded_VkSamplerCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutBinding* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetLayoutBinding* value = wrapper->value;

        MapHandleArray<VkSampler>(wrapper->pImmutableSamplers.GetPointer(), wrapper->pImmutableSamplers.GetHandlePointer(), wrapper->pImmutableSamplers.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSampler);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(wrapper->pBindings.GetMetaStructPointer(), wrapper->pBindings.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorSetAllocateInfo* value = wrapper->value;

        value->descriptorPool = object_mapper.MapVkDescriptorPool(wrapper->descriptorPool);

        MapHandleArray<VkDescriptorSetLayout>(wrapper->pSetLayouts.GetPointer(), wrapper->pSetLayouts.GetHandlePointer(), wrapper->pSetLayouts.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDescriptorSetLayout);
    }
}

void MapStructHandles(Decoded_VkDescriptorImageInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorImageInfo* value = wrapper->value;

        value->sampler = object_mapper.MapVkSampler(wrapper->sampler);

        value->imageView = object_mapper.MapVkImageView(wrapper->imageView);
    }
}

void MapStructHandles(Decoded_VkDescriptorBufferInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorBufferInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSet* value = wrapper->value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->dstSet = object_mapper.MapVkDescriptorSet(wrapper->dstSet);

        MapStructArrayHandles<Decoded_VkDescriptorImageInfo>(wrapper->pImageInfo.GetMetaStructPointer(), wrapper->pImageInfo.GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkDescriptorBufferInfo>(wrapper->pBufferInfo.GetMetaStructPointer(), wrapper->pBufferInfo.GetLength(), object_mapper);

        MapHandleArray<VkBufferView>(wrapper->pTexelBufferView.GetPointer(), wrapper->pTexelBufferView.GetHandlePointer(), wrapper->pTexelBufferView.GetLength(), object_mapper, &VulkanObjectMapper::MapVkBufferView);
    }
}

void MapStructHandles(Decoded_VkCopyDescriptorSet* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCopyDescriptorSet* value = wrapper->value;

        value->srcSet = object_mapper.MapVkDescriptorSet(wrapper->srcSet);

        value->dstSet = object_mapper.MapVkDescriptorSet(wrapper->dstSet);
    }
}

void MapStructHandles(Decoded_VkFramebufferCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFramebufferCreateInfo* value = wrapper->value;

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        MapHandleArray<VkImageView>(wrapper->pAttachments.GetPointer(), wrapper->pAttachments.GetHandlePointer(), wrapper->pAttachments.GetLength(), object_mapper, &VulkanObjectMapper::MapVkImageView);
    }
}

void MapStructHandles(Decoded_VkCommandBufferAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferAllocateInfo* value = wrapper->value;

        value->commandPool = object_mapper.MapVkCommandPool(wrapper->commandPool);
    }
}

void MapStructHandles(Decoded_VkCommandBufferInheritanceInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCommandBufferInheritanceInfo* value = wrapper->value;

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->framebuffer = object_mapper.MapVkFramebuffer(wrapper->framebuffer);
    }
}

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(wrapper->pInheritanceInfo.GetMetaStructPointer(), 1, object_mapper);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferMemoryBarrier* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageMemoryBarrier* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageMemoryBarrier* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkRenderPassBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRenderPassBeginInfo* value = wrapper->value;

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->framebuffer = object_mapper.MapVkFramebuffer(wrapper->framebuffer);
    }
}

void MapStructHandles(Decoded_VkBindBufferMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindBufferMemoryInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkBindImageMemoryInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImageMemoryInfo* value = wrapper->value;

        if (wrapper->pNext)
        {
            MapPNextStructHandles(wrapper->pNext->GetPointer(), wrapper->pNext->GetMetaStructPointer(), object_mapper);
        }

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkMemoryDedicatedAllocateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryDedicatedAllocateInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceGroupProperties* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceGroupProperties* value = wrapper->value;

        MapHandleArray<VkPhysicalDevice>(wrapper->physicalDevices.GetPointer(), wrapper->physicalDevices.GetHandlePointer(), wrapper->physicalDevices.GetLength(), object_mapper, &VulkanObjectMapper::MapVkPhysicalDevice);
    }
}

void MapStructHandles(Decoded_VkDeviceGroupDeviceCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDeviceGroupDeviceCreateInfo* value = wrapper->value;

        MapHandleArray<VkPhysicalDevice>(wrapper->pPhysicalDevices.GetPointer(), wrapper->pPhysicalDevices.GetHandlePointer(), wrapper->pPhysicalDevices.GetLength(), object_mapper, &VulkanObjectMapper::MapVkPhysicalDevice);
    }
}

void MapStructHandles(Decoded_VkBufferMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferMemoryRequirementsInfo2* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageMemoryRequirementsInfo2* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkImageSparseMemoryRequirementsInfo2* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageSparseMemoryRequirementsInfo2* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);
    }
}

void MapStructHandles(Decoded_VkSamplerYcbcrConversionInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSamplerYcbcrConversionInfo* value = wrapper->value;

        value->conversion = object_mapper.MapVkSamplerYcbcrConversion(wrapper->conversion);
    }
}

void MapStructHandles(Decoded_VkDescriptorUpdateTemplateCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDescriptorUpdateTemplateCreateInfo* value = wrapper->value;

        value->descriptorSetLayout = object_mapper.MapVkDescriptorSetLayout(wrapper->descriptorSetLayout);

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);
    }
}

void MapStructHandles(Decoded_VkSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSwapchainCreateInfoKHR* value = wrapper->value;

        value->surface = object_mapper.MapVkSurfaceKHR(wrapper->surface);

        value->oldSwapchain = object_mapper.MapVkSwapchainKHR(wrapper->oldSwapchain);
    }
}

void MapStructHandles(Decoded_VkPresentInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPresentInfoKHR* value = wrapper->value;

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapHandleArray<VkSwapchainKHR>(wrapper->pSwapchains.GetPointer(), wrapper->pSwapchains.GetHandlePointer(), wrapper->pSwapchains.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSwapchainKHR);
    }
}

void MapStructHandles(Decoded_VkImageSwapchainCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageSwapchainCreateInfoKHR* value = wrapper->value;

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);
    }
}

void MapStructHandles(Decoded_VkBindImageMemorySwapchainInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindImageMemorySwapchainInfoKHR* value = wrapper->value;

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);
    }
}

void MapStructHandles(Decoded_VkAcquireNextImageInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAcquireNextImageInfoKHR* value = wrapper->value;

        value->swapchain = object_mapper.MapVkSwapchainKHR(wrapper->swapchain);

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkDisplayPropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPropertiesKHR* value = wrapper->value;

        value->display = object_mapper.MapVkDisplayKHR(wrapper->display);
    }
}

void MapStructHandles(Decoded_VkDisplayModePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayModePropertiesKHR* value = wrapper->value;

        value->displayMode = object_mapper.MapVkDisplayModeKHR(wrapper->displayMode);
    }
}

void MapStructHandles(Decoded_VkDisplayPlanePropertiesKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlanePropertiesKHR* value = wrapper->value;

        value->currentDisplay = object_mapper.MapVkDisplayKHR(wrapper->currentDisplay);
    }
}

void MapStructHandles(Decoded_VkDisplaySurfaceCreateInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplaySurfaceCreateInfoKHR* value = wrapper->value;

        value->displayMode = object_mapper.MapVkDisplayModeKHR(wrapper->displayMode);
    }
}

void MapStructHandles(Decoded_VkMemoryGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetWin32HandleInfoKHR* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkMemoryGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetFdInfoKHR* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoKHR* value = wrapper->value;

        MapHandleArray<VkDeviceMemory>(wrapper->pAcquireSyncs.GetPointer(), wrapper->pAcquireSyncs.GetHandlePointer(), wrapper->pAcquireSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);

        MapHandleArray<VkDeviceMemory>(wrapper->pReleaseSyncs.GetPointer(), wrapper->pReleaseSyncs.GetHandlePointer(), wrapper->pReleaseSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportSemaphoreWin32HandleInfoKHR* value = wrapper->value;

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSemaphoreGetWin32HandleInfoKHR* value = wrapper->value;

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkImportSemaphoreFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportSemaphoreFdInfoKHR* value = wrapper->value;

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkSemaphoreGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSemaphoreGetFdInfoKHR* value = wrapper->value;

        value->semaphore = object_mapper.MapVkSemaphore(wrapper->semaphore);
    }
}

void MapStructHandles(Decoded_VkImportFenceWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportFenceWin32HandleInfoKHR* value = wrapper->value;

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkFenceGetWin32HandleInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFenceGetWin32HandleInfoKHR* value = wrapper->value;

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkImportFenceFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImportFenceFdInfoKHR* value = wrapper->value;

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkFenceGetFdInfoKHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkFenceGetFdInfoKHR* value = wrapper->value;

        value->fence = object_mapper.MapVkFence(wrapper->fence);
    }
}

void MapStructHandles(Decoded_VkPhysicalDeviceSurfaceInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkPhysicalDeviceSurfaceInfo2KHR* value = wrapper->value;

        value->surface = object_mapper.MapVkSurfaceKHR(wrapper->surface);
    }
}

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->displayProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->displayPlaneProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->displayModeProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneInfo2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDisplayPlaneInfo2KHR* value = wrapper->value;

        value->mode = object_mapper.MapVkDisplayModeKHR(wrapper->mode);
    }
}

void MapStructHandles(Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkDedicatedAllocationMemoryAllocateInfoNV* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkImageViewHandleInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkImageViewHandleInfoNVX* value = wrapper->value;

        value->imageView = object_mapper.MapVkImageView(wrapper->imageView);

        value->sampler = object_mapper.MapVkSampler(wrapper->sampler);
    }
}

void MapStructHandles(Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWin32KeyedMutexAcquireReleaseInfoNV* value = wrapper->value;

        MapHandleArray<VkDeviceMemory>(wrapper->pAcquireSyncs.GetPointer(), wrapper->pAcquireSyncs.GetHandlePointer(), wrapper->pAcquireSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);

        MapHandleArray<VkDeviceMemory>(wrapper->pReleaseSyncs.GetPointer(), wrapper->pReleaseSyncs.GetHandlePointer(), wrapper->pReleaseSyncs.GetLength(), object_mapper, &VulkanObjectMapper::MapVkDeviceMemory);
    }
}

void MapStructHandles(Decoded_VkConditionalRenderingBeginInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkConditionalRenderingBeginInfoEXT* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkIndirectCommandsTokenNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkIndirectCommandsTokenNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkCmdProcessCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCmdProcessCommandsInfoNVX* value = wrapper->value;

        value->objectTable = object_mapper.MapVkObjectTableNVX(wrapper->objectTable);

        value->indirectCommandsLayout = object_mapper.MapVkIndirectCommandsLayoutNVX(wrapper->indirectCommandsLayout);

        MapStructArrayHandles<Decoded_VkIndirectCommandsTokenNVX>(wrapper->pIndirectCommandsTokens.GetMetaStructPointer(), wrapper->pIndirectCommandsTokens.GetLength(), object_mapper);

        value->targetCommandBuffer = object_mapper.MapVkCommandBuffer(wrapper->targetCommandBuffer);

        value->sequencesCountBuffer = object_mapper.MapVkBuffer(wrapper->sequencesCountBuffer);

        value->sequencesIndexBuffer = object_mapper.MapVkBuffer(wrapper->sequencesIndexBuffer);
    }
}

void MapStructHandles(Decoded_VkCmdReserveSpaceForCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCmdReserveSpaceForCommandsInfoNVX* value = wrapper->value;

        value->objectTable = object_mapper.MapVkObjectTableNVX(wrapper->objectTable);

        value->indirectCommandsLayout = object_mapper.MapVkIndirectCommandsLayoutNVX(wrapper->indirectCommandsLayout);
    }
}

void MapStructHandles(Decoded_VkObjectTablePipelineEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTablePipelineEntryNVX* value = wrapper->value;

        value->pipeline = object_mapper.MapVkPipeline(wrapper->pipeline);
    }
}

void MapStructHandles(Decoded_VkObjectTableDescriptorSetEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableDescriptorSetEntryNVX* value = wrapper->value;

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);

        value->descriptorSet = object_mapper.MapVkDescriptorSet(wrapper->descriptorSet);
    }
}

void MapStructHandles(Decoded_VkObjectTableVertexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableVertexBufferEntryNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkObjectTableIndexBufferEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTableIndexBufferEntryNVX* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapStructHandles(Decoded_VkObjectTablePushConstantEntryNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkObjectTablePushConstantEntryNVX* value = wrapper->value;

        value->pipelineLayout = object_mapper.MapVkPipelineLayout(wrapper->pipelineLayout);
    }
}

void MapStructHandles(Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkMemoryGetAndroidHardwareBufferInfoANDROID* value = wrapper->value;

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkShaderModuleValidationCacheCreateInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkShaderModuleValidationCacheCreateInfoEXT* value = wrapper->value;

        value->validationCache = object_mapper.MapVkValidationCacheEXT(wrapper->validationCache);
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages.GetMetaStructPointer(), wrapper->pStages.GetLength(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkGeometryTrianglesNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGeometryTrianglesNV* value = wrapper->value;

        value->vertexData = object_mapper.MapVkBuffer(wrapper->vertexData);

        value->indexData = object_mapper.MapVkBuffer(wrapper->indexData);

        value->transformData = object_mapper.MapVkBuffer(wrapper->transformData);
    }
}

void MapStructHandles(Decoded_VkGeometryAABBNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGeometryAABBNV* value = wrapper->value;

        value->aabbData = object_mapper.MapVkBuffer(wrapper->aabbData);
    }
}

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->triangles, object_mapper);

        MapStructHandles(&wrapper->aabbs, object_mapper);
    }
}

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->geometry, object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkGeometryNV>(wrapper->pGeometries.GetMetaStructPointer(), wrapper->pGeometries.GetLength(), object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(&wrapper->info, object_mapper);
    }
}

void MapStructHandles(Decoded_VkBindAccelerationStructureMemoryInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindAccelerationStructureMemoryInfoNV* value = wrapper->value;

        value->accelerationStructure = object_mapper.MapVkAccelerationStructureNV(wrapper->accelerationStructure);

        value->memory = object_mapper.MapVkDeviceMemory(wrapper->memory);
    }
}

void MapStructHandles(Decoded_VkWriteDescriptorSetAccelerationStructureNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkWriteDescriptorSetAccelerationStructureNV* value = wrapper->value;

        MapHandleArray<VkAccelerationStructureNV>(wrapper->pAccelerationStructures.GetPointer(), wrapper->pAccelerationStructures.GetHandlePointer(), wrapper->pAccelerationStructures.GetLength(), object_mapper, &VulkanObjectMapper::MapVkAccelerationStructureNV);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkAccelerationStructureMemoryRequirementsInfoNV* value = wrapper->value;

        value->accelerationStructure = object_mapper.MapVkAccelerationStructureNV(wrapper->accelerationStructure);
    }
}

void MapStructHandles(Decoded_VkBufferDeviceAddressInfoEXT* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBufferDeviceAddressInfoEXT* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);
    }
}

void MapPNextStructHandles(const void* value, void* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((value != nullptr) && (wrapper != nullptr))
    {
        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

        switch (base->sType)
        {
        default:
            // TODO: Report or raise fatal error for unrecongized sType?
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkMemoryDedicatedAllocateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkDeviceGroupDeviceCreateInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            MapStructHandles(reinterpret_cast<Decoded_VkSamplerYcbcrConversionInfo*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkImageSwapchainCreateInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkBindImageMemorySwapchainInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            MapStructHandles(reinterpret_cast<Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(wrapper), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            MapStructHandles(reinterpret_cast<Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(wrapper), object_mapper);
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
