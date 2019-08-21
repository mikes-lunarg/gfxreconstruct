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

#include "generated/generated_vulkan_struct_handle_mappers.h"

#include "decode/custom_vulkan_struct_decoders.h"
#include "generated/generated_vulkan_struct_decoders.h"

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

template <typename T>
static void AddHandleArray(const format::HandleId*   ids,
                           size_t                    ids_len,
                           const T*                  handles,
                           size_t                    handles_len,
                           VulkanObjectMapper&       object_mapper,
                           void (VulkanObjectMapper::*AddFunc)(format::HandleId, T))
{
    if ((ids != nullptr) && (handles != nullptr))
    {
        // TODO: Improved handling of array size mismatch.
        size_t len = std::min(ids_len, handles_len);
        for (size_t i = 0; i < len; ++i)
        {
            (object_mapper.*AddFunc)(ids[i], handles[i]);
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

void AddStructHandles(const Decoded_VkDeviceCreateInfo* id_wrapper, const VkDeviceCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
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

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapHandleArray<VkCommandBuffer>(wrapper->pCommandBuffers.GetPointer(), wrapper->pCommandBuffers.GetHandlePointer(), wrapper->pCommandBuffers.GetLength(), object_mapper, &VulkanObjectMapper::MapVkCommandBuffer);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void AddStructHandles(const Decoded_VkSubmitInfo* id_wrapper, const VkSubmitInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
        }

        AddHandleArray<VkSemaphore>(id_wrapper->pWaitSemaphores.GetPointer(), id_wrapper->pWaitSemaphores.GetLength(), handle_struct->pWaitSemaphores, handle_struct->waitSemaphoreCount, object_mapper, &VulkanObjectMapper::AddVkSemaphore);

        AddHandleArray<VkCommandBuffer>(id_wrapper->pCommandBuffers.GetPointer(), id_wrapper->pCommandBuffers.GetLength(), handle_struct->pCommandBuffers, handle_struct->commandBufferCount, object_mapper, &VulkanObjectMapper::AddVkCommandBuffer);

        AddHandleArray<VkSemaphore>(id_wrapper->pSignalSemaphores.GetPointer(), id_wrapper->pSignalSemaphores.GetLength(), handle_struct->pSignalSemaphores, handle_struct->signalSemaphoreCount, object_mapper, &VulkanObjectMapper::AddVkSemaphore);
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
    }
}

void AddStructHandles(const Decoded_VkMemoryAllocateInfo* id_wrapper, const VkMemoryAllocateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
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

void AddStructHandles(const Decoded_VkMappedMemoryRange* id_wrapper, const VkMappedMemoryRange* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkSparseMemoryBind* id_wrapper, const VkSparseMemoryBind* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
    }
}

void MapStructHandles(Decoded_VkSparseBufferMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseBufferMemoryBindInfo* value = wrapper->value;

        value->buffer = object_mapper.MapVkBuffer(wrapper->buffer);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkSparseBufferMemoryBindInfo* id_wrapper, const VkSparseBufferMemoryBindInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);

        AddStructArrayHandles<Decoded_VkSparseMemoryBind>(id_wrapper->pBinds->GetMetaStructPointer(), id_wrapper->pBinds->GetLength(), handle_struct->pBinds, static_cast<size_t>(handle_struct->bindCount), object_mapper);
    }
}

void MapStructHandles(Decoded_VkSparseImageOpaqueMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageOpaqueMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkSparseImageOpaqueMemoryBindInfo* id_wrapper, const VkSparseImageOpaqueMemoryBindInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);

        AddStructArrayHandles<Decoded_VkSparseMemoryBind>(id_wrapper->pBinds->GetMetaStructPointer(), id_wrapper->pBinds->GetLength(), handle_struct->pBinds, static_cast<size_t>(handle_struct->bindCount), object_mapper);
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

void AddStructHandles(const Decoded_VkSparseImageMemoryBind* id_wrapper, const VkSparseImageMemoryBind* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
    }
}

void MapStructHandles(Decoded_VkSparseImageMemoryBindInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkSparseImageMemoryBindInfo* value = wrapper->value;

        value->image = object_mapper.MapVkImage(wrapper->image);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBind>(wrapper->pBinds->GetMetaStructPointer(), wrapper->pBinds->GetLength(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkSparseImageMemoryBindInfo* id_wrapper, const VkSparseImageMemoryBindInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);

        AddStructArrayHandles<Decoded_VkSparseImageMemoryBind>(id_wrapper->pBinds->GetMetaStructPointer(), id_wrapper->pBinds->GetLength(), handle_struct->pBinds, static_cast<size_t>(handle_struct->bindCount), object_mapper);
    }
}

void MapStructHandles(Decoded_VkBindSparseInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkBindSparseInfo* value = wrapper->value;

        MapHandleArray<VkSemaphore>(wrapper->pWaitSemaphores.GetPointer(), wrapper->pWaitSemaphores.GetHandlePointer(), wrapper->pWaitSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);

        MapStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(wrapper->pBufferBinds->GetMetaStructPointer(), wrapper->pBufferBinds->GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(wrapper->pImageOpaqueBinds->GetMetaStructPointer(), wrapper->pImageOpaqueBinds->GetLength(), object_mapper);

        MapStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(wrapper->pImageBinds->GetMetaStructPointer(), wrapper->pImageBinds->GetLength(), object_mapper);

        MapHandleArray<VkSemaphore>(wrapper->pSignalSemaphores.GetPointer(), wrapper->pSignalSemaphores.GetHandlePointer(), wrapper->pSignalSemaphores.GetLength(), object_mapper, &VulkanObjectMapper::MapVkSemaphore);
    }
}

void AddStructHandles(const Decoded_VkBindSparseInfo* id_wrapper, const VkBindSparseInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkSemaphore>(id_wrapper->pWaitSemaphores.GetPointer(), id_wrapper->pWaitSemaphores.GetLength(), handle_struct->pWaitSemaphores, handle_struct->waitSemaphoreCount, object_mapper, &VulkanObjectMapper::AddVkSemaphore);

        AddStructArrayHandles<Decoded_VkSparseBufferMemoryBindInfo>(id_wrapper->pBufferBinds->GetMetaStructPointer(), id_wrapper->pBufferBinds->GetLength(), handle_struct->pBufferBinds, static_cast<size_t>(handle_struct->bufferBindCount), object_mapper);

        AddStructArrayHandles<Decoded_VkSparseImageOpaqueMemoryBindInfo>(id_wrapper->pImageOpaqueBinds->GetMetaStructPointer(), id_wrapper->pImageOpaqueBinds->GetLength(), handle_struct->pImageOpaqueBinds, static_cast<size_t>(handle_struct->imageOpaqueBindCount), object_mapper);

        AddStructArrayHandles<Decoded_VkSparseImageMemoryBindInfo>(id_wrapper->pImageBinds->GetMetaStructPointer(), id_wrapper->pImageBinds->GetLength(), handle_struct->pImageBinds, static_cast<size_t>(handle_struct->imageBindCount), object_mapper);

        AddHandleArray<VkSemaphore>(id_wrapper->pSignalSemaphores.GetPointer(), id_wrapper->pSignalSemaphores.GetLength(), handle_struct->pSignalSemaphores, handle_struct->signalSemaphoreCount, object_mapper, &VulkanObjectMapper::AddVkSemaphore);
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

void AddStructHandles(const Decoded_VkBufferViewCreateInfo* id_wrapper, const VkBufferViewCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkImageCreateInfo* id_wrapper, const VkImageCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
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

void AddStructHandles(const Decoded_VkImageViewCreateInfo* id_wrapper, const VkImageViewCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
        }

        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);
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

void AddStructHandles(const Decoded_VkShaderModuleCreateInfo* id_wrapper, const VkShaderModuleCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
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

void AddStructHandles(const Decoded_VkPipelineShaderStageCreateInfo* id_wrapper, const VkPipelineShaderStageCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkShaderModule(id_wrapper->module, handle_struct->module);
    }
}

void MapStructHandles(Decoded_VkGraphicsPipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkGraphicsPipelineCreateInfo* value = wrapper->value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->renderPass = object_mapper.MapVkRenderPass(wrapper->renderPass);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void AddStructHandles(const Decoded_VkGraphicsPipelineCreateInfo* id_wrapper, const VkGraphicsPipelineCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(id_wrapper->pStages->GetMetaStructPointer(), id_wrapper->pStages->GetLength(), handle_struct->pStages, static_cast<size_t>(handle_struct->stageCount), object_mapper);

        object_mapper.AddVkPipelineLayout(id_wrapper->layout, handle_struct->layout);

        object_mapper.AddVkRenderPass(id_wrapper->renderPass, handle_struct->renderPass);

        object_mapper.AddVkPipeline(id_wrapper->basePipelineHandle, handle_struct->basePipelineHandle);
    }
}

void MapStructHandles(Decoded_VkComputePipelineCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkComputePipelineCreateInfo* value = wrapper->value;

        MapStructHandles(wrapper->stage.get(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void AddStructHandles(const Decoded_VkComputePipelineCreateInfo* id_wrapper, const VkComputePipelineCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->stage.get(), &handle_struct->stage, object_mapper);

        object_mapper.AddVkPipelineLayout(id_wrapper->layout, handle_struct->layout);

        object_mapper.AddVkPipeline(id_wrapper->basePipelineHandle, handle_struct->basePipelineHandle);
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

void AddStructHandles(const Decoded_VkPipelineLayoutCreateInfo* id_wrapper, const VkPipelineLayoutCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkDescriptorSetLayout>(id_wrapper->pSetLayouts.GetPointer(), id_wrapper->pSetLayouts.GetLength(), handle_struct->pSetLayouts, handle_struct->setLayoutCount, object_mapper, &VulkanObjectMapper::AddVkDescriptorSetLayout);
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

void AddStructHandles(const Decoded_VkSamplerCreateInfo* id_wrapper, const VkSamplerCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
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

void AddStructHandles(const Decoded_VkDescriptorSetLayoutBinding* id_wrapper, const VkDescriptorSetLayoutBinding* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkSampler>(id_wrapper->pImmutableSamplers.GetPointer(), id_wrapper->pImmutableSamplers.GetLength(), handle_struct->pImmutableSamplers, handle_struct->descriptorCount, object_mapper, &VulkanObjectMapper::AddVkSampler);
    }
}

void MapStructHandles(Decoded_VkDescriptorSetLayoutCreateInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(wrapper->pBindings->GetMetaStructPointer(), wrapper->pBindings->GetLength(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkDescriptorSetLayoutCreateInfo* id_wrapper, const VkDescriptorSetLayoutCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_VkDescriptorSetLayoutBinding>(id_wrapper->pBindings->GetMetaStructPointer(), id_wrapper->pBindings->GetLength(), handle_struct->pBindings, static_cast<size_t>(handle_struct->bindingCount), object_mapper);
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

void AddStructHandles(const Decoded_VkDescriptorSetAllocateInfo* id_wrapper, const VkDescriptorSetAllocateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDescriptorPool(id_wrapper->descriptorPool, handle_struct->descriptorPool);

        AddHandleArray<VkDescriptorSetLayout>(id_wrapper->pSetLayouts.GetPointer(), id_wrapper->pSetLayouts.GetLength(), handle_struct->pSetLayouts, handle_struct->descriptorSetCount, object_mapper, &VulkanObjectMapper::AddVkDescriptorSetLayout);
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

void AddStructHandles(const Decoded_VkDescriptorBufferInfo* id_wrapper, const VkDescriptorBufferInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkCopyDescriptorSet* id_wrapper, const VkCopyDescriptorSet* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDescriptorSet(id_wrapper->srcSet, handle_struct->srcSet);

        object_mapper.AddVkDescriptorSet(id_wrapper->dstSet, handle_struct->dstSet);
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

void AddStructHandles(const Decoded_VkFramebufferCreateInfo* id_wrapper, const VkFramebufferCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkRenderPass(id_wrapper->renderPass, handle_struct->renderPass);

        AddHandleArray<VkImageView>(id_wrapper->pAttachments.GetPointer(), id_wrapper->pAttachments.GetLength(), handle_struct->pAttachments, handle_struct->attachmentCount, object_mapper, &VulkanObjectMapper::AddVkImageView);
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

void AddStructHandles(const Decoded_VkCommandBufferAllocateInfo* id_wrapper, const VkCommandBufferAllocateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkCommandPool(id_wrapper->commandPool, handle_struct->commandPool);
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

void AddStructHandles(const Decoded_VkCommandBufferInheritanceInfo* id_wrapper, const VkCommandBufferInheritanceInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkRenderPass(id_wrapper->renderPass, handle_struct->renderPass);

        object_mapper.AddVkFramebuffer(id_wrapper->framebuffer, handle_struct->framebuffer);
    }
}

void MapStructHandles(Decoded_VkCommandBufferBeginInfo* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(wrapper->pInheritanceInfo->GetMetaStructPointer(), 1, object_mapper);
    }
}

void AddStructHandles(const Decoded_VkCommandBufferBeginInfo* id_wrapper, const VkCommandBufferBeginInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_VkCommandBufferInheritanceInfo>(id_wrapper->pInheritanceInfo->GetMetaStructPointer(), 1, handle_struct->pInheritanceInfo, 1, object_mapper);
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

void AddStructHandles(const Decoded_VkBufferMemoryBarrier* id_wrapper, const VkBufferMemoryBarrier* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkImageMemoryBarrier* id_wrapper, const VkImageMemoryBarrier* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);
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

void AddStructHandles(const Decoded_VkRenderPassBeginInfo* id_wrapper, const VkRenderPassBeginInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkRenderPass(id_wrapper->renderPass, handle_struct->renderPass);

        object_mapper.AddVkFramebuffer(id_wrapper->framebuffer, handle_struct->framebuffer);
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

void AddStructHandles(const Decoded_VkBindBufferMemoryInfo* id_wrapper, const VkBindBufferMemoryInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);

        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkBindImageMemoryInfo* id_wrapper, const VkBindImageMemoryInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        if (id_wrapper->pNext)
        {
            AddPNextStructHandles(id_wrapper->pNext->GetPointer(), id_wrapper->pNext->GetMetaStructPointer(), handle_struct->pNext, object_mapper);
        }

        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);

        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkMemoryDedicatedAllocateInfo* id_wrapper, const VkMemoryDedicatedAllocateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);

        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkPhysicalDeviceGroupProperties* id_wrapper, const VkPhysicalDeviceGroupProperties* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkPhysicalDevice>(id_wrapper->physicalDevices.GetPointer(), id_wrapper->physicalDevices.GetLength(), handle_struct->physicalDevices, handle_struct->physicalDeviceCount, object_mapper, &VulkanObjectMapper::AddVkPhysicalDevice);
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

void AddStructHandles(const Decoded_VkDeviceGroupDeviceCreateInfo* id_wrapper, const VkDeviceGroupDeviceCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkPhysicalDevice>(id_wrapper->pPhysicalDevices.GetPointer(), id_wrapper->pPhysicalDevices.GetLength(), handle_struct->pPhysicalDevices, handle_struct->physicalDeviceCount, object_mapper, &VulkanObjectMapper::AddVkPhysicalDevice);
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

void AddStructHandles(const Decoded_VkBufferMemoryRequirementsInfo2* id_wrapper, const VkBufferMemoryRequirementsInfo2* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkImageMemoryRequirementsInfo2* id_wrapper, const VkImageMemoryRequirementsInfo2* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);
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

void AddStructHandles(const Decoded_VkImageSparseMemoryRequirementsInfo2* id_wrapper, const VkImageSparseMemoryRequirementsInfo2* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);
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

void AddStructHandles(const Decoded_VkSamplerYcbcrConversionInfo* id_wrapper, const VkSamplerYcbcrConversionInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSamplerYcbcrConversion(id_wrapper->conversion, handle_struct->conversion);
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

void AddStructHandles(const Decoded_VkDescriptorUpdateTemplateCreateInfo* id_wrapper, const VkDescriptorUpdateTemplateCreateInfo* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDescriptorSetLayout(id_wrapper->descriptorSetLayout, handle_struct->descriptorSetLayout);

        object_mapper.AddVkPipelineLayout(id_wrapper->pipelineLayout, handle_struct->pipelineLayout);
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

void AddStructHandles(const Decoded_VkSwapchainCreateInfoKHR* id_wrapper, const VkSwapchainCreateInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSurfaceKHR(id_wrapper->surface, handle_struct->surface);

        object_mapper.AddVkSwapchainKHR(id_wrapper->oldSwapchain, handle_struct->oldSwapchain);
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

void AddStructHandles(const Decoded_VkPresentInfoKHR* id_wrapper, const VkPresentInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkSemaphore>(id_wrapper->pWaitSemaphores.GetPointer(), id_wrapper->pWaitSemaphores.GetLength(), handle_struct->pWaitSemaphores, handle_struct->waitSemaphoreCount, object_mapper, &VulkanObjectMapper::AddVkSemaphore);

        AddHandleArray<VkSwapchainKHR>(id_wrapper->pSwapchains.GetPointer(), id_wrapper->pSwapchains.GetLength(), handle_struct->pSwapchains, handle_struct->swapchainCount, object_mapper, &VulkanObjectMapper::AddVkSwapchainKHR);
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

void AddStructHandles(const Decoded_VkImageSwapchainCreateInfoKHR* id_wrapper, const VkImageSwapchainCreateInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSwapchainKHR(id_wrapper->swapchain, handle_struct->swapchain);
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

void AddStructHandles(const Decoded_VkBindImageMemorySwapchainInfoKHR* id_wrapper, const VkBindImageMemorySwapchainInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSwapchainKHR(id_wrapper->swapchain, handle_struct->swapchain);
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

void AddStructHandles(const Decoded_VkAcquireNextImageInfoKHR* id_wrapper, const VkAcquireNextImageInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSwapchainKHR(id_wrapper->swapchain, handle_struct->swapchain);

        object_mapper.AddVkSemaphore(id_wrapper->semaphore, handle_struct->semaphore);

        object_mapper.AddVkFence(id_wrapper->fence, handle_struct->fence);
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

void AddStructHandles(const Decoded_VkDisplayPropertiesKHR* id_wrapper, const VkDisplayPropertiesKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDisplayKHR(id_wrapper->display, handle_struct->display);
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

void AddStructHandles(const Decoded_VkDisplayModePropertiesKHR* id_wrapper, const VkDisplayModePropertiesKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDisplayModeKHR(id_wrapper->displayMode, handle_struct->displayMode);
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

void AddStructHandles(const Decoded_VkDisplayPlanePropertiesKHR* id_wrapper, const VkDisplayPlanePropertiesKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDisplayKHR(id_wrapper->currentDisplay, handle_struct->currentDisplay);
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

void AddStructHandles(const Decoded_VkDisplaySurfaceCreateInfoKHR* id_wrapper, const VkDisplaySurfaceCreateInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDisplayModeKHR(id_wrapper->displayMode, handle_struct->displayMode);
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

void AddStructHandles(const Decoded_VkMemoryGetWin32HandleInfoKHR* id_wrapper, const VkMemoryGetWin32HandleInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkMemoryGetFdInfoKHR* id_wrapper, const VkMemoryGetFdInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* id_wrapper, const VkWin32KeyedMutexAcquireReleaseInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkDeviceMemory>(id_wrapper->pAcquireSyncs.GetPointer(), id_wrapper->pAcquireSyncs.GetLength(), handle_struct->pAcquireSyncs, handle_struct->acquireCount, object_mapper, &VulkanObjectMapper::AddVkDeviceMemory);

        AddHandleArray<VkDeviceMemory>(id_wrapper->pReleaseSyncs.GetPointer(), id_wrapper->pReleaseSyncs.GetLength(), handle_struct->pReleaseSyncs, handle_struct->releaseCount, object_mapper, &VulkanObjectMapper::AddVkDeviceMemory);
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

void AddStructHandles(const Decoded_VkImportSemaphoreWin32HandleInfoKHR* id_wrapper, const VkImportSemaphoreWin32HandleInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSemaphore(id_wrapper->semaphore, handle_struct->semaphore);
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

void AddStructHandles(const Decoded_VkSemaphoreGetWin32HandleInfoKHR* id_wrapper, const VkSemaphoreGetWin32HandleInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSemaphore(id_wrapper->semaphore, handle_struct->semaphore);
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

void AddStructHandles(const Decoded_VkImportSemaphoreFdInfoKHR* id_wrapper, const VkImportSemaphoreFdInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSemaphore(id_wrapper->semaphore, handle_struct->semaphore);
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

void AddStructHandles(const Decoded_VkSemaphoreGetFdInfoKHR* id_wrapper, const VkSemaphoreGetFdInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSemaphore(id_wrapper->semaphore, handle_struct->semaphore);
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

void AddStructHandles(const Decoded_VkImportFenceWin32HandleInfoKHR* id_wrapper, const VkImportFenceWin32HandleInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkFence(id_wrapper->fence, handle_struct->fence);
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

void AddStructHandles(const Decoded_VkFenceGetWin32HandleInfoKHR* id_wrapper, const VkFenceGetWin32HandleInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkFence(id_wrapper->fence, handle_struct->fence);
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

void AddStructHandles(const Decoded_VkImportFenceFdInfoKHR* id_wrapper, const VkImportFenceFdInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkFence(id_wrapper->fence, handle_struct->fence);
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

void AddStructHandles(const Decoded_VkFenceGetFdInfoKHR* id_wrapper, const VkFenceGetFdInfoKHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkFence(id_wrapper->fence, handle_struct->fence);
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

void AddStructHandles(const Decoded_VkPhysicalDeviceSurfaceInfo2KHR* id_wrapper, const VkPhysicalDeviceSurfaceInfo2KHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkSurfaceKHR(id_wrapper->surface, handle_struct->surface);
    }
}

void MapStructHandles(Decoded_VkDisplayProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayProperties.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkDisplayProperties2KHR* id_wrapper, const VkDisplayProperties2KHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->displayProperties.get(), &handle_struct->displayProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayPlaneProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayPlaneProperties.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkDisplayPlaneProperties2KHR* id_wrapper, const VkDisplayPlaneProperties2KHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->displayPlaneProperties.get(), &handle_struct->displayPlaneProperties, object_mapper);
    }
}

void MapStructHandles(Decoded_VkDisplayModeProperties2KHR* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->displayModeProperties.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkDisplayModeProperties2KHR* id_wrapper, const VkDisplayModeProperties2KHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->displayModeProperties.get(), &handle_struct->displayModeProperties, object_mapper);
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

void AddStructHandles(const Decoded_VkDisplayPlaneInfo2KHR* id_wrapper, const VkDisplayPlaneInfo2KHR* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDisplayModeKHR(id_wrapper->mode, handle_struct->mode);
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

void AddStructHandles(const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* id_wrapper, const VkDedicatedAllocationMemoryAllocateInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImage(id_wrapper->image, handle_struct->image);

        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkImageViewHandleInfoNVX* id_wrapper, const VkImageViewHandleInfoNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkImageView(id_wrapper->imageView, handle_struct->imageView);

        object_mapper.AddVkSampler(id_wrapper->sampler, handle_struct->sampler);
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

void AddStructHandles(const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* id_wrapper, const VkWin32KeyedMutexAcquireReleaseInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkDeviceMemory>(id_wrapper->pAcquireSyncs.GetPointer(), id_wrapper->pAcquireSyncs.GetLength(), handle_struct->pAcquireSyncs, handle_struct->acquireCount, object_mapper, &VulkanObjectMapper::AddVkDeviceMemory);

        AddHandleArray<VkDeviceMemory>(id_wrapper->pReleaseSyncs.GetPointer(), id_wrapper->pReleaseSyncs.GetLength(), handle_struct->pReleaseSyncs, handle_struct->releaseCount, object_mapper, &VulkanObjectMapper::AddVkDeviceMemory);
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

void AddStructHandles(const Decoded_VkConditionalRenderingBeginInfoEXT* id_wrapper, const VkConditionalRenderingBeginInfoEXT* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkIndirectCommandsTokenNVX* id_wrapper, const VkIndirectCommandsTokenNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
    }
}

void MapStructHandles(Decoded_VkCmdProcessCommandsInfoNVX* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkCmdProcessCommandsInfoNVX* value = wrapper->value;

        value->objectTable = object_mapper.MapVkObjectTableNVX(wrapper->objectTable);

        value->indirectCommandsLayout = object_mapper.MapVkIndirectCommandsLayoutNVX(wrapper->indirectCommandsLayout);

        MapStructArrayHandles<Decoded_VkIndirectCommandsTokenNVX>(wrapper->pIndirectCommandsTokens->GetMetaStructPointer(), wrapper->pIndirectCommandsTokens->GetLength(), object_mapper);

        value->targetCommandBuffer = object_mapper.MapVkCommandBuffer(wrapper->targetCommandBuffer);

        value->sequencesCountBuffer = object_mapper.MapVkBuffer(wrapper->sequencesCountBuffer);

        value->sequencesIndexBuffer = object_mapper.MapVkBuffer(wrapper->sequencesIndexBuffer);
    }
}

void AddStructHandles(const Decoded_VkCmdProcessCommandsInfoNVX* id_wrapper, const VkCmdProcessCommandsInfoNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkObjectTableNVX(id_wrapper->objectTable, handle_struct->objectTable);

        object_mapper.AddVkIndirectCommandsLayoutNVX(id_wrapper->indirectCommandsLayout, handle_struct->indirectCommandsLayout);

        AddStructArrayHandles<Decoded_VkIndirectCommandsTokenNVX>(id_wrapper->pIndirectCommandsTokens->GetMetaStructPointer(), id_wrapper->pIndirectCommandsTokens->GetLength(), handle_struct->pIndirectCommandsTokens, static_cast<size_t>(handle_struct->indirectCommandsTokenCount), object_mapper);

        object_mapper.AddVkCommandBuffer(id_wrapper->targetCommandBuffer, handle_struct->targetCommandBuffer);

        object_mapper.AddVkBuffer(id_wrapper->sequencesCountBuffer, handle_struct->sequencesCountBuffer);

        object_mapper.AddVkBuffer(id_wrapper->sequencesIndexBuffer, handle_struct->sequencesIndexBuffer);
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

void AddStructHandles(const Decoded_VkCmdReserveSpaceForCommandsInfoNVX* id_wrapper, const VkCmdReserveSpaceForCommandsInfoNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkObjectTableNVX(id_wrapper->objectTable, handle_struct->objectTable);

        object_mapper.AddVkIndirectCommandsLayoutNVX(id_wrapper->indirectCommandsLayout, handle_struct->indirectCommandsLayout);
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

void AddStructHandles(const Decoded_VkObjectTablePipelineEntryNVX* id_wrapper, const VkObjectTablePipelineEntryNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkPipeline(id_wrapper->pipeline, handle_struct->pipeline);
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

void AddStructHandles(const Decoded_VkObjectTableDescriptorSetEntryNVX* id_wrapper, const VkObjectTableDescriptorSetEntryNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkPipelineLayout(id_wrapper->pipelineLayout, handle_struct->pipelineLayout);

        object_mapper.AddVkDescriptorSet(id_wrapper->descriptorSet, handle_struct->descriptorSet);
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

void AddStructHandles(const Decoded_VkObjectTableVertexBufferEntryNVX* id_wrapper, const VkObjectTableVertexBufferEntryNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkObjectTableIndexBufferEntryNVX* id_wrapper, const VkObjectTableIndexBufferEntryNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddStructHandles(const Decoded_VkObjectTablePushConstantEntryNVX* id_wrapper, const VkObjectTablePushConstantEntryNVX* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkPipelineLayout(id_wrapper->pipelineLayout, handle_struct->pipelineLayout);
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

void AddStructHandles(const Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* id_wrapper, const VkMemoryGetAndroidHardwareBufferInfoANDROID* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkShaderModuleValidationCacheCreateInfoEXT* id_wrapper, const VkShaderModuleValidationCacheCreateInfoEXT* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkValidationCacheEXT(id_wrapper->validationCache, handle_struct->validationCache);
    }
}

void MapStructHandles(Decoded_VkRayTracingPipelineCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if ((wrapper != nullptr) && (wrapper->value != nullptr))
    {
        VkRayTracingPipelineCreateInfoNV* value = wrapper->value;

        MapStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(wrapper->pStages->GetMetaStructPointer(), wrapper->pStages->GetLength(), object_mapper);

        value->layout = object_mapper.MapVkPipelineLayout(wrapper->layout);

        value->basePipelineHandle = object_mapper.MapVkPipeline(wrapper->basePipelineHandle);
    }
}

void AddStructHandles(const Decoded_VkRayTracingPipelineCreateInfoNV* id_wrapper, const VkRayTracingPipelineCreateInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_VkPipelineShaderStageCreateInfo>(id_wrapper->pStages->GetMetaStructPointer(), id_wrapper->pStages->GetLength(), handle_struct->pStages, static_cast<size_t>(handle_struct->stageCount), object_mapper);

        object_mapper.AddVkPipelineLayout(id_wrapper->layout, handle_struct->layout);

        object_mapper.AddVkPipeline(id_wrapper->basePipelineHandle, handle_struct->basePipelineHandle);
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

void AddStructHandles(const Decoded_VkGeometryTrianglesNV* id_wrapper, const VkGeometryTrianglesNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->vertexData, handle_struct->vertexData);

        object_mapper.AddVkBuffer(id_wrapper->indexData, handle_struct->indexData);

        object_mapper.AddVkBuffer(id_wrapper->transformData, handle_struct->transformData);
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

void AddStructHandles(const Decoded_VkGeometryAABBNV* id_wrapper, const VkGeometryAABBNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->aabbData, handle_struct->aabbData);
    }
}

void MapStructHandles(Decoded_VkGeometryDataNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->triangles.get(), object_mapper);

        MapStructHandles(wrapper->aabbs.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkGeometryDataNV* id_wrapper, const VkGeometryDataNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->triangles.get(), &handle_struct->triangles, object_mapper);

        AddStructHandles(id_wrapper->aabbs.get(), &handle_struct->aabbs, object_mapper);
    }
}

void MapStructHandles(Decoded_VkGeometryNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->geometry.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkGeometryNV* id_wrapper, const VkGeometryNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->geometry.get(), &handle_struct->geometry, object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructArrayHandles<Decoded_VkGeometryNV>(wrapper->pGeometries->GetMetaStructPointer(), wrapper->pGeometries->GetLength(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkAccelerationStructureInfoNV* id_wrapper, const VkAccelerationStructureInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructArrayHandles<Decoded_VkGeometryNV>(id_wrapper->pGeometries->GetMetaStructPointer(), id_wrapper->pGeometries->GetLength(), handle_struct->pGeometries, static_cast<size_t>(handle_struct->geometryCount), object_mapper);
    }
}

void MapStructHandles(Decoded_VkAccelerationStructureCreateInfoNV* wrapper, const VulkanObjectMapper& object_mapper)
{
    if (wrapper != nullptr)
    {
        MapStructHandles(wrapper->info.get(), object_mapper);
    }
}

void AddStructHandles(const Decoded_VkAccelerationStructureCreateInfoNV* id_wrapper, const VkAccelerationStructureCreateInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddStructHandles(id_wrapper->info.get(), &handle_struct->info, object_mapper);
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

void AddStructHandles(const Decoded_VkBindAccelerationStructureMemoryInfoNV* id_wrapper, const VkBindAccelerationStructureMemoryInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkAccelerationStructureNV(id_wrapper->accelerationStructure, handle_struct->accelerationStructure);

        object_mapper.AddVkDeviceMemory(id_wrapper->memory, handle_struct->memory);
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

void AddStructHandles(const Decoded_VkWriteDescriptorSetAccelerationStructureNV* id_wrapper, const VkWriteDescriptorSetAccelerationStructureNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        AddHandleArray<VkAccelerationStructureNV>(id_wrapper->pAccelerationStructures.GetPointer(), id_wrapper->pAccelerationStructures.GetLength(), handle_struct->pAccelerationStructures, handle_struct->accelerationStructureCount, object_mapper, &VulkanObjectMapper::AddVkAccelerationStructureNV);
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

void AddStructHandles(const Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* id_wrapper, const VkAccelerationStructureMemoryRequirementsInfoNV* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkAccelerationStructureNV(id_wrapper->accelerationStructure, handle_struct->accelerationStructure);
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

void AddStructHandles(const Decoded_VkBufferDeviceAddressInfoEXT* id_wrapper, const VkBufferDeviceAddressInfoEXT* handle_struct, VulkanObjectMapper& object_mapper)
{
    if (id_wrapper != nullptr)
    {
        object_mapper.AddVkBuffer(id_wrapper->buffer, handle_struct->buffer);
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

void AddPNextStructHandles(const void* value, const void* id_wrapper, const void* handle_struct, VulkanObjectMapper& object_mapper)
{
    if ((value != nullptr) && (id_wrapper != nullptr) && (handle_struct != nullptr))
    {
        const VkBaseInStructure* base = reinterpret_cast<const VkBaseInStructure*>(value);

        switch (base->sType)
        {
        default:
            // TODO: Report or raise fatal error for unrecongized sType?
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            AddStructHandles(reinterpret_cast<const Decoded_VkMemoryDedicatedAllocateInfo*>(id_wrapper), reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            AddStructHandles(reinterpret_cast<const Decoded_VkDeviceGroupDeviceCreateInfo*>(id_wrapper), reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            AddStructHandles(reinterpret_cast<const Decoded_VkSamplerYcbcrConversionInfo*>(id_wrapper), reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            AddStructHandles(reinterpret_cast<const Decoded_VkImageSwapchainCreateInfoKHR*>(id_wrapper), reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            AddStructHandles(reinterpret_cast<const Decoded_VkBindImageMemorySwapchainInfoKHR*>(id_wrapper), reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            AddStructHandles(reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(id_wrapper), reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            AddStructHandles(reinterpret_cast<const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(id_wrapper), reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            AddStructHandles(reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(id_wrapper), reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            AddStructHandles(reinterpret_cast<const Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(id_wrapper), reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(handle_struct), object_mapper);
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            AddStructHandles(reinterpret_cast<const Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(id_wrapper), reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(handle_struct), object_mapper);
            break;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
