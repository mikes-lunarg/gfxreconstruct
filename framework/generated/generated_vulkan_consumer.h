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

#ifndef  GFXRECON_GENERATED_VULKAN_CONSUMER_H
#define  GFXRECON_GENERATED_VULKAN_CONSUMER_H

#include "decode/vulkan_consumer_base.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class VulkanConsumer : public VulkanConsumerBase
{
  public:
    VulkanConsumer() { }

    virtual ~VulkanConsumer() override { }

    virtual void Process_vkCreateInstance(
        VkResult                                    returnValue,
        const StructPointerDecoder<Decoded_VkInstanceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkInstance>*           pInstance) {}

    virtual void Process_vkDestroyInstance(
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkEnumeratePhysicalDevices(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceCount,
        HandlePointerDecoder<VkPhysicalDevice>*     pPhysicalDevices) {}

    virtual void Process_vkGetPhysicalDeviceFeatures(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        StructPointerDecoder<Decoded_VkImageFormatProperties>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties>* pMemoryProperties) {}

    virtual void Process_vkCreateDevice(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkDeviceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDevice>*             pDevice) {}

    virtual void Process_vkDestroyDevice(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetDeviceQueue(
        format::HandleId                            device,
        uint32_t                                    queueFamilyIndex,
        uint32_t                                    queueIndex,
        HandlePointerDecoder<VkQueue>*              pQueue) {}

    virtual void Process_vkQueueSubmit(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    submitCount,
        const StructPointerDecoder<Decoded_VkSubmitInfo>& pSubmits,
        format::HandleId                            fence) {}

    virtual void Process_vkQueueWaitIdle(
        VkResult                                    returnValue,
        format::HandleId                            queue) {}

    virtual void Process_vkDeviceWaitIdle(
        VkResult                                    returnValue,
        format::HandleId                            device) {}

    virtual void Process_vkAllocateMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkMemoryAllocateInfo>& pAllocateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDeviceMemory>*       pMemory) {}

    virtual void Process_vkFreeMemory(
        format::HandleId                            device,
        format::HandleId                            memory,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkMapMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkDeviceSize                                offset,
        VkDeviceSize                                size,
        VkMemoryMapFlags                            flags,
        PointerDecoder<uint64_t, void*>*            ppData) {}

    virtual void Process_vkUnmapMemory(
        format::HandleId                            device,
        format::HandleId                            memory) {}

    virtual void Process_vkFlushMappedMemoryRanges(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) {}

    virtual void Process_vkInvalidateMappedMemoryRanges(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    memoryRangeCount,
        const StructPointerDecoder<Decoded_VkMappedMemoryRange>& pMemoryRanges) {}

    virtual void Process_vkGetDeviceMemoryCommitment(
        format::HandleId                            device,
        format::HandleId                            memory,
        PointerDecoder<VkDeviceSize>*               pCommittedMemoryInBytes) {}

    virtual void Process_vkBindBufferMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            buffer,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) {}

    virtual void Process_vkBindImageMemory(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        format::HandleId                            memory,
        VkDeviceSize                                memoryOffset) {}

    virtual void Process_vkGetBufferMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            buffer,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) {}

    virtual void Process_vkGetImageMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkMemoryRequirements>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements(
        format::HandleId                            device,
        format::HandleId                            image,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements>* pSparseMemoryRequirements) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkSampleCountFlagBits                       samples,
        VkImageUsageFlags                           usage,
        VkImageTiling                               tiling,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties>* pProperties) {}

    virtual void Process_vkQueueBindSparse(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindSparseInfo>& pBindInfo,
        format::HandleId                            fence) {}

    virtual void Process_vkCreateFence(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkFenceCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkDestroyFence(
        format::HandleId                            device,
        format::HandleId                            fence,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkResetFences(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        const HandlePointerDecoder<VkFence>&        pFences) {}

    virtual void Process_vkGetFenceStatus(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            fence) {}

    virtual void Process_vkWaitForFences(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    fenceCount,
        const HandlePointerDecoder<VkFence>&        pFences,
        VkBool32                                    waitAll,
        uint64_t                                    timeout) {}

    virtual void Process_vkCreateSemaphore(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSemaphoreCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSemaphore>*          pSemaphore) {}

    virtual void Process_vkDestroySemaphore(
        format::HandleId                            device,
        format::HandleId                            semaphore,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkEventCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkEvent>*              pEvent) {}

    virtual void Process_vkDestroyEvent(
        format::HandleId                            device,
        format::HandleId                            event,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetEventStatus(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkSetEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkResetEvent(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            event) {}

    virtual void Process_vkCreateQueryPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkQueryPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkQueryPool>*          pQueryPool) {}

    virtual void Process_vkDestroyQueryPool(
        format::HandleId                            device,
        format::HandleId                            queryPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetQueryPoolResults(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) {}

    virtual void Process_vkCreateBuffer(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkBufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkBuffer>*             pBuffer) {}

    virtual void Process_vkDestroyBuffer(
        format::HandleId                            device,
        format::HandleId                            buffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateBufferView(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkBufferViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkBufferView>*         pView) {}

    virtual void Process_vkDestroyBufferView(
        format::HandleId                            device,
        format::HandleId                            bufferView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateImage(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkImage>*              pImage) {}

    virtual void Process_vkDestroyImage(
        format::HandleId                            device,
        format::HandleId                            image,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetImageSubresourceLayout(
        format::HandleId                            device,
        format::HandleId                            image,
        const StructPointerDecoder<Decoded_VkImageSubresource>& pSubresource,
        StructPointerDecoder<Decoded_VkSubresourceLayout>* pLayout) {}

    virtual void Process_vkCreateImageView(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageViewCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkImageView>*          pView) {}

    virtual void Process_vkDestroyImageView(
        format::HandleId                            device,
        format::HandleId                            imageView,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateShaderModule(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkShaderModuleCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkShaderModule>*       pShaderModule) {}

    virtual void Process_vkDestroyShaderModule(
        format::HandleId                            device,
        format::HandleId                            shaderModule,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreatePipelineCache(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPipelineCacheCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkPipelineCache>*      pPipelineCache) {}

    virtual void Process_vkDestroyPipelineCache(
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetPipelineCacheData(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkMergePipelineCaches(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        const HandlePointerDecoder<VkPipelineCache>& pSrcCaches) {}

    virtual void Process_vkCreateGraphicsPipelines(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkGraphicsPipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkCreateComputePipelines(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkComputePipelineCreateInfo>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkDestroyPipeline(
        format::HandleId                            device,
        format::HandleId                            pipeline,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreatePipelineLayout(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPipelineLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkPipelineLayout>*     pPipelineLayout) {}

    virtual void Process_vkDestroyPipelineLayout(
        format::HandleId                            device,
        format::HandleId                            pipelineLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateSampler(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSamplerCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSampler>*            pSampler) {}

    virtual void Process_vkDestroySampler(
        format::HandleId                            device,
        format::HandleId                            sampler,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateDescriptorSetLayout(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDescriptorSetLayout>* pSetLayout) {}

    virtual void Process_vkDestroyDescriptorSetLayout(
        format::HandleId                            device,
        format::HandleId                            descriptorSetLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateDescriptorPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDescriptorPool>*     pDescriptorPool) {}

    virtual void Process_vkDestroyDescriptorPool(
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkResetDescriptorPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        VkDescriptorPoolResetFlags                  flags) {}

    virtual void Process_vkAllocateDescriptorSets(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorSetAllocateInfo>& pAllocateInfo,
        HandlePointerDecoder<VkDescriptorSet>*      pDescriptorSets) {}

    virtual void Process_vkFreeDescriptorSets(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            descriptorPool,
        uint32_t                                    descriptorSetCount,
        const HandlePointerDecoder<VkDescriptorSet>& pDescriptorSets) {}

    virtual void Process_vkUpdateDescriptorSets(
        format::HandleId                            device,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites,
        uint32_t                                    descriptorCopyCount,
        const StructPointerDecoder<Decoded_VkCopyDescriptorSet>& pDescriptorCopies) {}

    virtual void Process_vkCreateFramebuffer(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkFramebufferCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkFramebuffer>*        pFramebuffer) {}

    virtual void Process_vkDestroyFramebuffer(
        format::HandleId                            device,
        format::HandleId                            framebuffer,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateRenderPass(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) {}

    virtual void Process_vkDestroyRenderPass(
        format::HandleId                            device,
        format::HandleId                            renderPass,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetRenderAreaGranularity(
        format::HandleId                            device,
        format::HandleId                            renderPass,
        StructPointerDecoder<Decoded_VkExtent2D>*   pGranularity) {}

    virtual void Process_vkCreateCommandPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkCommandPoolCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkCommandPool>*        pCommandPool) {}

    virtual void Process_vkDestroyCommandPool(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkResetCommandPool(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolResetFlags                     flags) {}

    virtual void Process_vkAllocateCommandBuffers(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkCommandBufferAllocateInfo>& pAllocateInfo,
        HandlePointerDecoder<VkCommandBuffer>*      pCommandBuffers) {}

    virtual void Process_vkFreeCommandBuffers(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        uint32_t                                    commandBufferCount,
        const HandlePointerDecoder<VkCommandBuffer>& pCommandBuffers) {}

    virtual void Process_vkBeginCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkCommandBufferBeginInfo>& pBeginInfo) {}

    virtual void Process_vkEndCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkResetCommandBuffer(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        VkCommandBufferResetFlags                   flags) {}

    virtual void Process_vkCmdBindPipeline(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            pipeline) {}

    virtual void Process_vkCmdSetViewport(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewport>& pViewports) {}

    virtual void Process_vkCmdSetScissor(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstScissor,
        uint32_t                                    scissorCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pScissors) {}

    virtual void Process_vkCmdSetLineWidth(
        format::HandleId                            commandBuffer,
        float                                       lineWidth) {}

    virtual void Process_vkCmdSetDepthBias(
        format::HandleId                            commandBuffer,
        float                                       depthBiasConstantFactor,
        float                                       depthBiasClamp,
        float                                       depthBiasSlopeFactor) {}

    virtual void Process_vkCmdSetBlendConstants(
        format::HandleId                            commandBuffer,
        const PointerDecoder<float>&                blendConstants) {}

    virtual void Process_vkCmdSetDepthBounds(
        format::HandleId                            commandBuffer,
        float                                       minDepthBounds,
        float                                       maxDepthBounds) {}

    virtual void Process_vkCmdSetStencilCompareMask(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    compareMask) {}

    virtual void Process_vkCmdSetStencilWriteMask(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    writeMask) {}

    virtual void Process_vkCmdSetStencilReference(
        format::HandleId                            commandBuffer,
        VkStencilFaceFlags                          faceMask,
        uint32_t                                    reference) {}

    virtual void Process_vkCmdBindDescriptorSets(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    firstSet,
        uint32_t                                    descriptorSetCount,
        const HandlePointerDecoder<VkDescriptorSet>& pDescriptorSets,
        uint32_t                                    dynamicOffsetCount,
        const PointerDecoder<uint32_t>&             pDynamicOffsets) {}

    virtual void Process_vkCmdBindIndexBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        VkIndexType                                 indexType) {}

    virtual void Process_vkCmdBindVertexBuffers(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        const HandlePointerDecoder<VkBuffer>&       pBuffers,
        const PointerDecoder<VkDeviceSize>&         pOffsets) {}

    virtual void Process_vkCmdDraw(
        format::HandleId                            commandBuffer,
        uint32_t                                    vertexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstVertex,
        uint32_t                                    firstInstance) {}

    virtual void Process_vkCmdDrawIndexed(
        format::HandleId                            commandBuffer,
        uint32_t                                    indexCount,
        uint32_t                                    instanceCount,
        uint32_t                                    firstIndex,
        int32_t                                     vertexOffset,
        uint32_t                                    firstInstance) {}

    virtual void Process_vkCmdDrawIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDispatch(
        format::HandleId                            commandBuffer,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkCmdDispatchIndirect(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset) {}

    virtual void Process_vkCmdCopyBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferCopy>& pRegions) {}

    virtual void Process_vkCmdCopyImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageCopy>& pRegions) {}

    virtual void Process_vkCmdBlitImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageBlit>& pRegions,
        VkFilter                                    filter) {}

    virtual void Process_vkCmdCopyBufferToImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcBuffer,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) {}

    virtual void Process_vkCmdCopyImageToBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstBuffer,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkBufferImageCopy>& pRegions) {}

    virtual void Process_vkCmdUpdateBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                dataSize,
        const PointerDecoder<uint8_t>&              pData) {}

    virtual void Process_vkCmdFillBuffer(
        format::HandleId                            commandBuffer,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                size,
        uint32_t                                    data) {}

    virtual void Process_vkCmdClearColorImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearColorValue>& pColor,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) {}

    virtual void Process_vkCmdClearDepthStencilImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            image,
        VkImageLayout                               imageLayout,
        const StructPointerDecoder<Decoded_VkClearDepthStencilValue>& pDepthStencil,
        uint32_t                                    rangeCount,
        const StructPointerDecoder<Decoded_VkImageSubresourceRange>& pRanges) {}

    virtual void Process_vkCmdClearAttachments(
        format::HandleId                            commandBuffer,
        uint32_t                                    attachmentCount,
        const StructPointerDecoder<Decoded_VkClearAttachment>& pAttachments,
        uint32_t                                    rectCount,
        const StructPointerDecoder<Decoded_VkClearRect>& pRects) {}

    virtual void Process_vkCmdResolveImage(
        format::HandleId                            commandBuffer,
        format::HandleId                            srcImage,
        VkImageLayout                               srcImageLayout,
        format::HandleId                            dstImage,
        VkImageLayout                               dstImageLayout,
        uint32_t                                    regionCount,
        const StructPointerDecoder<Decoded_VkImageResolve>& pRegions) {}

    virtual void Process_vkCmdSetEvent(
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) {}

    virtual void Process_vkCmdResetEvent(
        format::HandleId                            commandBuffer,
        format::HandleId                            event,
        VkPipelineStageFlags                        stageMask) {}

    virtual void Process_vkCmdWaitEvents(
        format::HandleId                            commandBuffer,
        uint32_t                                    eventCount,
        const HandlePointerDecoder<VkEvent>&        pEvents,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        uint32_t                                    memoryBarrierCount,
        const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers) {}

    virtual void Process_vkCmdPipelineBarrier(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlags                        srcStageMask,
        VkPipelineStageFlags                        dstStageMask,
        VkDependencyFlags                           dependencyFlags,
        uint32_t                                    memoryBarrierCount,
        const StructPointerDecoder<Decoded_VkMemoryBarrier>& pMemoryBarriers,
        uint32_t                                    bufferMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkBufferMemoryBarrier>& pBufferMemoryBarriers,
        uint32_t                                    imageMemoryBarrierCount,
        const StructPointerDecoder<Decoded_VkImageMemoryBarrier>& pImageMemoryBarriers) {}

    virtual void Process_vkCmdBeginQuery(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags) {}

    virtual void Process_vkCmdEndQuery(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkCmdResetQueryPool(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) {}

    virtual void Process_vkCmdWriteTimestamp(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            queryPool,
        uint32_t                                    query) {}

    virtual void Process_vkCmdCopyQueryPoolResults(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        VkDeviceSize                                stride,
        VkQueryResultFlags                          flags) {}

    virtual void Process_vkCmdPushConstants(
        format::HandleId                            commandBuffer,
        format::HandleId                            layout,
        VkShaderStageFlags                          stageFlags,
        uint32_t                                    offset,
        uint32_t                                    size,
        const PointerDecoder<uint8_t>&              pValues) {}

    virtual void Process_vkCmdBeginRenderPass(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        VkSubpassContents                           contents) {}

    virtual void Process_vkCmdNextSubpass(
        format::HandleId                            commandBuffer,
        VkSubpassContents                           contents) {}

    virtual void Process_vkCmdEndRenderPass(
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdExecuteCommands(
        format::HandleId                            commandBuffer,
        uint32_t                                    commandBufferCount,
        const HandlePointerDecoder<VkCommandBuffer>& pCommandBuffers) {}

    virtual void Process_vkBindBufferMemory2(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) {}

    virtual void Process_vkBindImageMemory2(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeatures(
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) {}

    virtual void Process_vkCmdSetDeviceMask(
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) {}

    virtual void Process_vkCmdDispatchBase(
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroups(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) {}

    virtual void Process_vkGetImageMemoryRequirements2(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetBufferMemoryRequirements2(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceProperties2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) {}

    virtual void Process_vkTrimCommandPool(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) {}

    virtual void Process_vkGetDeviceQueue2(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDeviceQueueInfo2>& pQueueInfo,
        HandlePointerDecoder<VkQueue>*              pQueue) {}

    virtual void Process_vkCreateSamplerYcbcrConversion(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) {}

    virtual void Process_vkDestroySamplerYcbcrConversion(
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateDescriptorUpdateTemplate(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplate(
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferProperties(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalFenceProperties(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphoreProperties(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) {}

    virtual void Process_vkGetDescriptorSetLayoutSupport(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) {}

    virtual void Process_vkDestroySurfaceKHR(
        format::HandleId                            instance,
        format::HandleId                            surface,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceSupportKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        format::HandleId                            surface,
        PointerDecoder<VkBool32>*                   pSupported) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilitiesKHR>* pSurfaceCapabilities) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormatsKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormatKHR>* pSurfaceFormats) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) {}

    virtual void Process_vkCreateSwapchainKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchain) {}

    virtual void Process_vkDestroySwapchainKHR(
        format::HandleId                            device,
        format::HandleId                            swapchain,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetSwapchainImagesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pSwapchainImageCount,
        HandlePointerDecoder<VkImage>*              pSwapchainImages) {}

    virtual void Process_vkAcquireNextImageKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        uint64_t                                    timeout,
        format::HandleId                            semaphore,
        format::HandleId                            fence,
        PointerDecoder<uint32_t>*                   pImageIndex) {}

    virtual void Process_vkQueuePresentKHR(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        const StructPointerDecoder<Decoded_VkPresentInfoKHR>& pPresentInfo) {}

    virtual void Process_vkGetDeviceGroupPresentCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        StructPointerDecoder<Decoded_VkDeviceGroupPresentCapabilitiesKHR>* pDeviceGroupPresentCapabilities) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            surface,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) {}

    virtual void Process_vkGetPhysicalDevicePresentRectanglesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        PointerDecoder<uint32_t>*                   pRectCount,
        StructPointerDecoder<Decoded_VkRect2D>*     pRects) {}

    virtual void Process_vkAcquireNextImage2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkAcquireNextImageInfoKHR>& pAcquireInfo,
        PointerDecoder<uint32_t>*                   pImageIndex) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPropertiesKHR>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlanePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlanePropertiesKHR>* pProperties) {}

    virtual void Process_vkGetDisplayPlaneSupportedDisplaysKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    planeIndex,
        PointerDecoder<uint32_t>*                   pDisplayCount,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplays) {}

    virtual void Process_vkGetDisplayModePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModePropertiesKHR>* pProperties) {}

    virtual void Process_vkCreateDisplayModeKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        const StructPointerDecoder<Decoded_VkDisplayModeCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDisplayModeKHR>*     pMode) {}

    virtual void Process_vkGetDisplayPlaneCapabilitiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            mode,
        uint32_t                                    planeIndex,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilitiesKHR>* pCapabilities) {}

    virtual void Process_vkCreateDisplayPlaneSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkDisplaySurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateSharedSwapchainsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        const StructPointerDecoder<Decoded_VkSwapchainCreateInfoKHR>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSwapchainKHR>*       pSwapchains) {}

    virtual void Process_vkCreateXlibSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkXlibSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceXlibPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    dpy,
        size_t                                      visualID) {}

    virtual void Process_vkCreateXcbSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkXcbSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceXcbPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    connection,
        uint32_t                                    visual_id) {}

    virtual void Process_vkCreateWaylandSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkWaylandSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceWaylandPresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex,
        uint64_t                                    display) {}

    virtual void Process_vkCreateAndroidSurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkAndroidSurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateWin32SurfaceKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkWin32SurfaceCreateInfoKHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceWin32PresentationSupportKHR(
        VkBool32                                    returnValue,
        format::HandleId                            physicalDevice,
        uint32_t                                    queueFamilyIndex) {}

    virtual void Process_vkGetPhysicalDeviceFeatures2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures2>* pFeatures) {}

    virtual void Process_vkGetPhysicalDeviceProperties2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceProperties2>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceFormatProperties2KHR(
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        StructPointerDecoder<Decoded_VkFormatProperties2>* pFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceImageFormatProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceImageFormatInfo2>& pImageFormatInfo,
        StructPointerDecoder<Decoded_VkImageFormatProperties2>* pImageFormatProperties) {}

    virtual void Process_vkGetPhysicalDeviceQueueFamilyProperties2KHR(
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pQueueFamilyPropertyCount,
        StructPointerDecoder<Decoded_VkQueueFamilyProperties2>* pQueueFamilyProperties) {}

    virtual void Process_vkGetPhysicalDeviceMemoryProperties2KHR(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkPhysicalDeviceMemoryProperties2>* pMemoryProperties) {}

    virtual void Process_vkGetPhysicalDeviceSparseImageFormatProperties2KHR(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSparseImageFormatInfo2>& pFormatInfo,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkSparseImageFormatProperties2>* pProperties) {}

    virtual void Process_vkGetDeviceGroupPeerMemoryFeaturesKHR(
        format::HandleId                            device,
        uint32_t                                    heapIndex,
        uint32_t                                    localDeviceIndex,
        uint32_t                                    remoteDeviceIndex,
        PointerDecoder<VkPeerMemoryFeatureFlags>*   pPeerMemoryFeatures) {}

    virtual void Process_vkCmdSetDeviceMaskKHR(
        format::HandleId                            commandBuffer,
        uint32_t                                    deviceMask) {}

    virtual void Process_vkCmdDispatchBaseKHR(
        format::HandleId                            commandBuffer,
        uint32_t                                    baseGroupX,
        uint32_t                                    baseGroupY,
        uint32_t                                    baseGroupZ,
        uint32_t                                    groupCountX,
        uint32_t                                    groupCountY,
        uint32_t                                    groupCountZ) {}

    virtual void Process_vkTrimCommandPoolKHR(
        format::HandleId                            device,
        format::HandleId                            commandPool,
        VkCommandPoolTrimFlags                      flags) {}

    virtual void Process_vkEnumeratePhysicalDeviceGroupsKHR(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        PointerDecoder<uint32_t>*                   pPhysicalDeviceGroupCount,
        StructPointerDecoder<Decoded_VkPhysicalDeviceGroupProperties>* pPhysicalDeviceGroupProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalBufferPropertiesKHR(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalBufferInfo>& pExternalBufferInfo,
        StructPointerDecoder<Decoded_VkExternalBufferProperties>* pExternalBufferProperties) {}

    virtual void Process_vkGetMemoryWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkMemoryGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkGetMemoryWin32HandlePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    handle,
        StructPointerDecoder<Decoded_VkMemoryWin32HandlePropertiesKHR>* pMemoryWin32HandleProperties) {}

    virtual void Process_vkGetMemoryFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkMemoryGetFdInfoKHR>& pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkGetMemoryFdPropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        int                                         fd,
        StructPointerDecoder<Decoded_VkMemoryFdPropertiesKHR>* pMemoryFdProperties) {}

    virtual void Process_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalSemaphoreInfo>& pExternalSemaphoreInfo,
        StructPointerDecoder<Decoded_VkExternalSemaphoreProperties>* pExternalSemaphoreProperties) {}

    virtual void Process_vkImportSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreWin32HandleInfoKHR>& pImportSemaphoreWin32HandleInfo) {}

    virtual void Process_vkGetSemaphoreWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkImportSemaphoreFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImportSemaphoreFdInfoKHR>& pImportSemaphoreFdInfo) {}

    virtual void Process_vkGetSemaphoreFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSemaphoreGetFdInfoKHR>& pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkCmdPushDescriptorSetKHR(
        format::HandleId                            commandBuffer,
        VkPipelineBindPoint                         pipelineBindPoint,
        format::HandleId                            layout,
        uint32_t                                    set,
        uint32_t                                    descriptorWriteCount,
        const StructPointerDecoder<Decoded_VkWriteDescriptorSet>& pDescriptorWrites) {}

    virtual void Process_vkCreateDescriptorUpdateTemplateKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDescriptorUpdateTemplate>* pDescriptorUpdateTemplate) {}

    virtual void Process_vkDestroyDescriptorUpdateTemplateKHR(
        format::HandleId                            device,
        format::HandleId                            descriptorUpdateTemplate,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateRenderPass2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkRenderPassCreateInfo2KHR>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkRenderPass>*         pRenderPass) {}

    virtual void Process_vkCmdBeginRenderPass2KHR(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkRenderPassBeginInfo>& pRenderPassBegin,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo) {}

    virtual void Process_vkCmdNextSubpass2KHR(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassBeginInfoKHR>& pSubpassBeginInfo,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) {}

    virtual void Process_vkCmdEndRenderPass2KHR(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkSubpassEndInfoKHR>& pSubpassEndInfo) {}

    virtual void Process_vkGetSwapchainStatusKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkGetPhysicalDeviceExternalFencePropertiesKHR(
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceExternalFenceInfo>& pExternalFenceInfo,
        StructPointerDecoder<Decoded_VkExternalFenceProperties>* pExternalFenceProperties) {}

    virtual void Process_vkImportFenceWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImportFenceWin32HandleInfoKHR>& pImportFenceWin32HandleInfo) {}

    virtual void Process_vkGetFenceWin32HandleKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkFenceGetWin32HandleInfoKHR>& pGetWin32HandleInfo,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkImportFenceFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImportFenceFdInfoKHR>& pImportFenceFdInfo) {}

    virtual void Process_vkGetFenceFdKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkFenceGetFdInfoKHR>& pGetFdInfo,
        PointerDecoder<int>*                        pFd) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2KHR>* pSurfaceCapabilities) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceFormats2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pSurfaceFormatCount,
        StructPointerDecoder<Decoded_VkSurfaceFormat2KHR>* pSurfaceFormats) {}

    virtual void Process_vkGetPhysicalDeviceDisplayProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayProperties2KHR>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceDisplayPlaneProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayPlaneProperties2KHR>* pProperties) {}

    virtual void Process_vkGetDisplayModeProperties2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkDisplayModeProperties2KHR>* pProperties) {}

    virtual void Process_vkGetDisplayPlaneCapabilities2KHR(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkDisplayPlaneInfo2KHR>& pDisplayPlaneInfo,
        StructPointerDecoder<Decoded_VkDisplayPlaneCapabilities2KHR>* pCapabilities) {}

    virtual void Process_vkGetImageMemoryRequirements2KHR(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageMemoryRequirementsInfo2>& pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetBufferMemoryRequirements2KHR(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkBufferMemoryRequirementsInfo2>& pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2>* pMemoryRequirements) {}

    virtual void Process_vkGetImageSparseMemoryRequirements2KHR(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageSparseMemoryRequirementsInfo2>& pInfo,
        PointerDecoder<uint32_t>*                   pSparseMemoryRequirementCount,
        StructPointerDecoder<Decoded_VkSparseImageMemoryRequirements2>* pSparseMemoryRequirements) {}

    virtual void Process_vkCreateSamplerYcbcrConversionKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSamplerYcbcrConversionCreateInfo>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSamplerYcbcrConversion>* pYcbcrConversion) {}

    virtual void Process_vkDestroySamplerYcbcrConversionKHR(
        format::HandleId                            device,
        format::HandleId                            ycbcrConversion,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkBindBufferMemory2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindBufferMemoryInfo>& pBindInfos) {}

    virtual void Process_vkBindImageMemory2KHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindImageMemoryInfo>& pBindInfos) {}

    virtual void Process_vkGetDescriptorSetLayoutSupportKHR(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDescriptorSetLayoutCreateInfo>& pCreateInfo,
        StructPointerDecoder<Decoded_VkDescriptorSetLayoutSupport>* pSupport) {}

    virtual void Process_vkCmdDrawIndirectCountKHR(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountKHR(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkGetSemaphoreCounterValueKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            semaphore,
        PointerDecoder<uint64_t>*                   pValue) {}

    virtual void Process_vkWaitSemaphoresKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSemaphoreWaitInfoKHR>& pWaitInfo,
        uint64_t                                    timeout) {}

    virtual void Process_vkSignalSemaphoreKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkSemaphoreSignalInfoKHR>& pSignalInfo) {}

    virtual void Process_vkGetPipelineExecutablePropertiesKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPipelineInfoKHR>& pPipelineInfo,
        PointerDecoder<uint32_t>*                   pExecutableCount,
        StructPointerDecoder<Decoded_VkPipelineExecutablePropertiesKHR>* pProperties) {}

    virtual void Process_vkGetPipelineExecutableStatisticsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>& pExecutableInfo,
        PointerDecoder<uint32_t>*                   pStatisticCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableStatisticKHR>* pStatistics) {}

    virtual void Process_vkGetPipelineExecutableInternalRepresentationsKHR(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPipelineExecutableInfoKHR>& pExecutableInfo,
        PointerDecoder<uint32_t>*                   pInternalRepresentationCount,
        StructPointerDecoder<Decoded_VkPipelineExecutableInternalRepresentationKHR>* pInternalRepresentations) {}

    virtual void Process_vkCreateDebugReportCallbackEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkDebugReportCallbackCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDebugReportCallbackEXT>* pCallback) {}

    virtual void Process_vkDestroyDebugReportCallbackEXT(
        format::HandleId                            instance,
        format::HandleId                            callback,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkDebugReportMessageEXT(
        format::HandleId                            instance,
        VkDebugReportFlagsEXT                       flags,
        VkDebugReportObjectTypeEXT                  objectType,
        uint64_t                                    object,
        size_t                                      location,
        int32_t                                     messageCode,
        const StringDecoder&                        pLayerPrefix,
        const StringDecoder&                        pMessage) {}

    virtual void Process_vkDebugMarkerSetObjectTagEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectTagInfoEXT>& pTagInfo) {}

    virtual void Process_vkDebugMarkerSetObjectNameEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDebugMarkerObjectNameInfoEXT>& pNameInfo) {}

    virtual void Process_vkCmdDebugMarkerBeginEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) {}

    virtual void Process_vkCmdDebugMarkerEndEXT(
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdDebugMarkerInsertEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugMarkerMarkerInfoEXT>& pMarkerInfo) {}

    virtual void Process_vkCmdBindTransformFeedbackBuffersEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstBinding,
        uint32_t                                    bindingCount,
        const HandlePointerDecoder<VkBuffer>&       pBuffers,
        const PointerDecoder<VkDeviceSize>&         pOffsets,
        const PointerDecoder<VkDeviceSize>&         pSizes) {}

    virtual void Process_vkCmdBeginTransformFeedbackEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        const HandlePointerDecoder<VkBuffer>&       pCounterBuffers,
        const PointerDecoder<VkDeviceSize>&         pCounterBufferOffsets) {}

    virtual void Process_vkCmdEndTransformFeedbackEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstCounterBuffer,
        uint32_t                                    counterBufferCount,
        const HandlePointerDecoder<VkBuffer>&       pCounterBuffers,
        const PointerDecoder<VkDeviceSize>&         pCounterBufferOffsets) {}

    virtual void Process_vkCmdBeginQueryIndexedEXT(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        VkQueryControlFlags                         flags,
        uint32_t                                    index) {}

    virtual void Process_vkCmdEndQueryIndexedEXT(
        format::HandleId                            commandBuffer,
        format::HandleId                            queryPool,
        uint32_t                                    query,
        uint32_t                                    index) {}

    virtual void Process_vkCmdDrawIndirectByteCountEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    instanceCount,
        uint32_t                                    firstInstance,
        format::HandleId                            counterBuffer,
        VkDeviceSize                                counterBufferOffset,
        uint32_t                                    counterOffset,
        uint32_t                                    vertexStride) {}

    virtual void Process_vkGetImageViewHandleNVX(
        uint32_t                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkImageViewHandleInfoNVX>& pInfo) {}

    virtual void Process_vkCmdDrawIndirectCountAMD(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawIndexedIndirectCountAMD(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkGetShaderInfoAMD(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        VkShaderStageFlagBits                       shaderStage,
        VkShaderInfoTypeAMD                         infoType,
        PointerDecoder<size_t>*                     pInfoSize,
        PointerDecoder<uint8_t>*                    pInfo) {}

    virtual void Process_vkCreateStreamDescriptorSurfaceGGP(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkStreamDescriptorSurfaceCreateInfoGGP>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetPhysicalDeviceExternalImageFormatPropertiesNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        VkFormat                                    format,
        VkImageType                                 type,
        VkImageTiling                               tiling,
        VkImageUsageFlags                           usage,
        VkImageCreateFlags                          flags,
        VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
        StructPointerDecoder<Decoded_VkExternalImageFormatPropertiesNV>* pExternalImageFormatProperties) {}

    virtual void Process_vkGetMemoryWin32HandleNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            memory,
        VkExternalMemoryHandleTypeFlagsNV           handleType,
        PointerDecoder<uint64_t, void*>*            pHandle) {}

    virtual void Process_vkCreateViSurfaceNN(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkViSurfaceCreateInfoNN>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCmdBeginConditionalRenderingEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkConditionalRenderingBeginInfoEXT>& pConditionalRenderingBegin) {}

    virtual void Process_vkCmdEndConditionalRenderingEXT(
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdProcessCommandsNVX(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdProcessCommandsInfoNVX>& pProcessCommandsInfo) {}

    virtual void Process_vkCmdReserveSpaceForCommandsNVX(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkCmdReserveSpaceForCommandsInfoNVX>& pReserveSpaceInfo) {}

    virtual void Process_vkCreateIndirectCommandsLayoutNVX(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkIndirectCommandsLayoutCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkIndirectCommandsLayoutNVX>* pIndirectCommandsLayout) {}

    virtual void Process_vkDestroyIndirectCommandsLayoutNVX(
        format::HandleId                            device,
        format::HandleId                            indirectCommandsLayout,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkCreateObjectTableNVX(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkObjectTableCreateInfoNVX>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkObjectTableNVX>*     pObjectTable) {}

    virtual void Process_vkDestroyObjectTableNVX(
        format::HandleId                            device,
        format::HandleId                            objectTable,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkUnregisterObjectsNVX(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            objectTable,
        uint32_t                                    objectCount,
        const PointerDecoder<VkObjectEntryTypeNVX>& pObjectEntryTypes,
        const PointerDecoder<uint32_t>&             pObjectIndices) {}

    virtual void Process_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX(
        format::HandleId                            physicalDevice,
        StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsFeaturesNVX>* pFeatures,
        StructPointerDecoder<Decoded_VkDeviceGeneratedCommandsLimitsNVX>* pLimits) {}

    virtual void Process_vkCmdSetViewportWScalingNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkViewportWScalingNV>& pViewportWScalings) {}

    virtual void Process_vkReleaseDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            display) {}

    virtual void Process_vkAcquireXlibDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        format::HandleId                            display) {}

    virtual void Process_vkGetRandROutputDisplayEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        uint64_t                                    dpy,
        size_t                                      rrOutput,
        HandlePointerDecoder<VkDisplayKHR>*         pDisplay) {}

    virtual void Process_vkGetPhysicalDeviceSurfaceCapabilities2EXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        format::HandleId                            surface,
        StructPointerDecoder<Decoded_VkSurfaceCapabilities2EXT>* pSurfaceCapabilities) {}

    virtual void Process_vkDisplayPowerControlEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        const StructPointerDecoder<Decoded_VkDisplayPowerInfoEXT>& pDisplayPowerInfo) {}

    virtual void Process_vkRegisterDeviceEventEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDeviceEventInfoEXT>& pDeviceEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkRegisterDisplayEventEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            display,
        const StructPointerDecoder<Decoded_VkDisplayEventInfoEXT>& pDisplayEventInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkFence>*              pFence) {}

    virtual void Process_vkGetSwapchainCounterEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        VkSurfaceCounterFlagBitsEXT                 counter,
        PointerDecoder<uint64_t>*                   pCounterValue) {}

    virtual void Process_vkGetRefreshCycleDurationGOOGLE(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        StructPointerDecoder<Decoded_VkRefreshCycleDurationGOOGLE>* pDisplayTimingProperties) {}

    virtual void Process_vkGetPastPresentationTimingGOOGLE(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain,
        PointerDecoder<uint32_t>*                   pPresentationTimingCount,
        StructPointerDecoder<Decoded_VkPastPresentationTimingGOOGLE>* pPresentationTimings) {}

    virtual void Process_vkCmdSetDiscardRectangleEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstDiscardRectangle,
        uint32_t                                    discardRectangleCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pDiscardRectangles) {}

    virtual void Process_vkSetHdrMetadataEXT(
        format::HandleId                            device,
        uint32_t                                    swapchainCount,
        const HandlePointerDecoder<VkSwapchainKHR>& pSwapchains,
        const StructPointerDecoder<Decoded_VkHdrMetadataEXT>& pMetadata) {}

    virtual void Process_vkCreateIOSSurfaceMVK(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkIOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateMacOSSurfaceMVK(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkMacOSSurfaceCreateInfoMVK>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkSetDebugUtilsObjectNameEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>& pNameInfo) {}

    virtual void Process_vkSetDebugUtilsObjectTagEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkDebugUtilsObjectTagInfoEXT>& pTagInfo) {}

    virtual void Process_vkQueueBeginDebugUtilsLabelEXT(
        format::HandleId                            queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) {}

    virtual void Process_vkQueueEndDebugUtilsLabelEXT(
        format::HandleId                            queue) {}

    virtual void Process_vkQueueInsertDebugUtilsLabelEXT(
        format::HandleId                            queue,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) {}

    virtual void Process_vkCmdBeginDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) {}

    virtual void Process_vkCmdEndDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer) {}

    virtual void Process_vkCmdInsertDebugUtilsLabelEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>& pLabelInfo) {}

    virtual void Process_vkCreateDebugUtilsMessengerEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkDebugUtilsMessengerEXT>* pMessenger) {}

    virtual void Process_vkDestroyDebugUtilsMessengerEXT(
        format::HandleId                            instance,
        format::HandleId                            messenger,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkSubmitDebugUtilsMessageEXT(
        format::HandleId                            instance,
        VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
        const StructPointerDecoder<Decoded_VkDebugUtilsMessengerCallbackDataEXT>& pCallbackData) {}

    virtual void Process_vkGetAndroidHardwareBufferPropertiesANDROID(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint64_t                                    buffer,
        StructPointerDecoder<Decoded_VkAndroidHardwareBufferPropertiesANDROID>* pProperties) {}

    virtual void Process_vkGetMemoryAndroidHardwareBufferANDROID(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID>& pInfo,
        PointerDecoder<uint64_t, void*>*            pBuffer) {}

    virtual void Process_vkCmdSetSampleLocationsEXT(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkSampleLocationsInfoEXT>& pSampleLocationsInfo) {}

    virtual void Process_vkGetPhysicalDeviceMultisamplePropertiesEXT(
        format::HandleId                            physicalDevice,
        VkSampleCountFlagBits                       samples,
        StructPointerDecoder<Decoded_VkMultisamplePropertiesEXT>* pMultisampleProperties) {}

    virtual void Process_vkGetImageDrmFormatModifierPropertiesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            image,
        StructPointerDecoder<Decoded_VkImageDrmFormatModifierPropertiesEXT>* pProperties) {}

    virtual void Process_vkCreateValidationCacheEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkValidationCacheCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkValidationCacheEXT>* pValidationCache) {}

    virtual void Process_vkDestroyValidationCacheEXT(
        format::HandleId                            device,
        format::HandleId                            validationCache,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkMergeValidationCachesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            dstCache,
        uint32_t                                    srcCacheCount,
        const HandlePointerDecoder<VkValidationCacheEXT>& pSrcCaches) {}

    virtual void Process_vkGetValidationCacheDataEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            validationCache,
        PointerDecoder<size_t>*                     pDataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdBindShadingRateImageNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            imageView,
        VkImageLayout                               imageLayout) {}

    virtual void Process_vkCmdSetViewportShadingRatePaletteNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstViewport,
        uint32_t                                    viewportCount,
        const StructPointerDecoder<Decoded_VkShadingRatePaletteNV>& pShadingRatePalettes) {}

    virtual void Process_vkCmdSetCoarseSampleOrderNV(
        format::HandleId                            commandBuffer,
        VkCoarseSampleOrderTypeNV                   sampleOrderType,
        uint32_t                                    customSampleOrderCount,
        const StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>& pCustomSampleOrders) {}

    virtual void Process_vkCreateAccelerationStructureNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkAccelerationStructureCreateInfoNV>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkAccelerationStructureNV>* pAccelerationStructure) {}

    virtual void Process_vkDestroyAccelerationStructureNV(
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator) {}

    virtual void Process_vkGetAccelerationStructureMemoryRequirementsNV(
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkAccelerationStructureMemoryRequirementsInfoNV>& pInfo,
        StructPointerDecoder<Decoded_VkMemoryRequirements2KHR>* pMemoryRequirements) {}

    virtual void Process_vkBindAccelerationStructureMemoryNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    bindInfoCount,
        const StructPointerDecoder<Decoded_VkBindAccelerationStructureMemoryInfoNV>& pBindInfos) {}

    virtual void Process_vkCmdBuildAccelerationStructureNV(
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkAccelerationStructureInfoNV>& pInfo,
        format::HandleId                            instanceData,
        VkDeviceSize                                instanceOffset,
        VkBool32                                    update,
        format::HandleId                            dst,
        format::HandleId                            src,
        format::HandleId                            scratch,
        VkDeviceSize                                scratchOffset) {}

    virtual void Process_vkCmdCopyAccelerationStructureNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            dst,
        format::HandleId                            src,
        VkCopyAccelerationStructureModeNV           mode) {}

    virtual void Process_vkCmdTraceRaysNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            raygenShaderBindingTableBuffer,
        VkDeviceSize                                raygenShaderBindingOffset,
        format::HandleId                            missShaderBindingTableBuffer,
        VkDeviceSize                                missShaderBindingOffset,
        VkDeviceSize                                missShaderBindingStride,
        format::HandleId                            hitShaderBindingTableBuffer,
        VkDeviceSize                                hitShaderBindingOffset,
        VkDeviceSize                                hitShaderBindingStride,
        format::HandleId                            callableShaderBindingTableBuffer,
        VkDeviceSize                                callableShaderBindingOffset,
        VkDeviceSize                                callableShaderBindingStride,
        uint32_t                                    width,
        uint32_t                                    height,
        uint32_t                                    depth) {}

    virtual void Process_vkCreateRayTracingPipelinesNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipelineCache,
        uint32_t                                    createInfoCount,
        const StructPointerDecoder<Decoded_VkRayTracingPipelineCreateInfoNV>& pCreateInfos,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkPipeline>*           pPipelines) {}

    virtual void Process_vkGetRayTracingShaderGroupHandlesNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    firstGroup,
        uint32_t                                    groupCount,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkGetAccelerationStructureHandleNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            accelerationStructure,
        size_t                                      dataSize,
        PointerDecoder<uint8_t>*                    pData) {}

    virtual void Process_vkCmdWriteAccelerationStructuresPropertiesNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    accelerationStructureCount,
        const HandlePointerDecoder<VkAccelerationStructureNV>& pAccelerationStructures,
        VkQueryType                                 queryType,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery) {}

    virtual void Process_vkCompileDeferredNV(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            pipeline,
        uint32_t                                    shader) {}

    virtual void Process_vkGetMemoryHostPointerPropertiesEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkExternalMemoryHandleTypeFlagBits          handleType,
        uint64_t                                    pHostPointer,
        StructPointerDecoder<Decoded_VkMemoryHostPointerPropertiesEXT>* pMemoryHostPointerProperties) {}

    virtual void Process_vkCmdWriteBufferMarkerAMD(
        format::HandleId                            commandBuffer,
        VkPipelineStageFlagBits                     pipelineStage,
        format::HandleId                            dstBuffer,
        VkDeviceSize                                dstOffset,
        uint32_t                                    marker) {}

    virtual void Process_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pTimeDomainCount,
        PointerDecoder<VkTimeDomainEXT>*            pTimeDomains) {}

    virtual void Process_vkGetCalibratedTimestampsEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        uint32_t                                    timestampCount,
        const StructPointerDecoder<Decoded_VkCalibratedTimestampInfoEXT>& pTimestampInfos,
        PointerDecoder<uint64_t>*                   pTimestamps,
        PointerDecoder<uint64_t>*                   pMaxDeviation) {}

    virtual void Process_vkCmdDrawMeshTasksNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    taskCount,
        uint32_t                                    firstTask) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        uint32_t                                    drawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdDrawMeshTasksIndirectCountNV(
        format::HandleId                            commandBuffer,
        format::HandleId                            buffer,
        VkDeviceSize                                offset,
        format::HandleId                            countBuffer,
        VkDeviceSize                                countBufferOffset,
        uint32_t                                    maxDrawCount,
        uint32_t                                    stride) {}

    virtual void Process_vkCmdSetExclusiveScissorNV(
        format::HandleId                            commandBuffer,
        uint32_t                                    firstExclusiveScissor,
        uint32_t                                    exclusiveScissorCount,
        const StructPointerDecoder<Decoded_VkRect2D>& pExclusiveScissors) {}

    virtual void Process_vkCmdSetCheckpointNV(
        format::HandleId                            commandBuffer,
        uint64_t                                    pCheckpointMarker) {}

    virtual void Process_vkGetQueueCheckpointDataNV(
        format::HandleId                            queue,
        PointerDecoder<uint32_t>*                   pCheckpointDataCount,
        StructPointerDecoder<Decoded_VkCheckpointDataNV>* pCheckpointData) {}

    virtual void Process_vkInitializePerformanceApiINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkInitializePerformanceApiInfoINTEL>& pInitializeInfo) {}

    virtual void Process_vkUninitializePerformanceApiINTEL(
        format::HandleId                            device) {}

    virtual void Process_vkCmdSetPerformanceMarkerINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkPerformanceMarkerInfoINTEL>& pMarkerInfo) {}

    virtual void Process_vkCmdSetPerformanceStreamMarkerINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkPerformanceStreamMarkerInfoINTEL>& pMarkerInfo) {}

    virtual void Process_vkCmdSetPerformanceOverrideINTEL(
        VkResult                                    returnValue,
        format::HandleId                            commandBuffer,
        const StructPointerDecoder<Decoded_VkPerformanceOverrideInfoINTEL>& pOverrideInfo) {}

    virtual void Process_vkAcquirePerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPerformanceConfigurationAcquireInfoINTEL>& pAcquireInfo,
        HandlePointerDecoder<VkPerformanceConfigurationINTEL>* pConfiguration) {}

    virtual void Process_vkReleasePerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            configuration) {}

    virtual void Process_vkQueueSetPerformanceConfigurationINTEL(
        VkResult                                    returnValue,
        format::HandleId                            queue,
        format::HandleId                            configuration) {}

    virtual void Process_vkGetPerformanceParameterINTEL(
        VkResult                                    returnValue,
        format::HandleId                            device,
        VkPerformanceParameterTypeINTEL             parameter,
        StructPointerDecoder<Decoded_VkPerformanceValueINTEL>* pValue) {}

    virtual void Process_vkSetLocalDimmingAMD(
        format::HandleId                            device,
        format::HandleId                            swapChain,
        VkBool32                                    localDimmingEnable) {}

    virtual void Process_vkCreateImagePipeSurfaceFUCHSIA(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCreateMetalSurfaceEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkMetalSurfaceCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkGetBufferDeviceAddressEXT(
        VkDeviceAddress                             returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkBufferDeviceAddressInfoEXT>& pInfo) {}

    virtual void Process_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pPropertyCount,
        StructPointerDecoder<Decoded_VkCooperativeMatrixPropertiesNV>* pProperties) {}

    virtual void Process_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        PointerDecoder<uint32_t>*                   pCombinationCount,
        StructPointerDecoder<Decoded_VkFramebufferMixedSamplesCombinationNV>* pCombinations) {}

    virtual void Process_vkGetPhysicalDeviceSurfacePresentModes2EXT(
        VkResult                                    returnValue,
        format::HandleId                            physicalDevice,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        PointerDecoder<uint32_t>*                   pPresentModeCount,
        PointerDecoder<VkPresentModeKHR>*           pPresentModes) {}

    virtual void Process_vkAcquireFullScreenExclusiveModeEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkReleaseFullScreenExclusiveModeEXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        format::HandleId                            swapchain) {}

    virtual void Process_vkGetDeviceGroupSurfacePresentModes2EXT(
        VkResult                                    returnValue,
        format::HandleId                            device,
        const StructPointerDecoder<Decoded_VkPhysicalDeviceSurfaceInfo2KHR>& pSurfaceInfo,
        PointerDecoder<VkDeviceGroupPresentModeFlagsKHR>* pModes) {}

    virtual void Process_vkCreateHeadlessSurfaceEXT(
        VkResult                                    returnValue,
        format::HandleId                            instance,
        const StructPointerDecoder<Decoded_VkHeadlessSurfaceCreateInfoEXT>& pCreateInfo,
        const StructPointerDecoder<Decoded_VkAllocationCallbacks>& pAllocator,
        HandlePointerDecoder<VkSurfaceKHR>*         pSurface) {}

    virtual void Process_vkCmdSetLineStippleEXT(
        format::HandleId                            commandBuffer,
        uint32_t                                    lineStippleFactor,
        uint16_t                                    lineStipplePattern) {}

    virtual void Process_vkResetQueryPoolEXT(
        format::HandleId                            device,
        format::HandleId                            queryPool,
        uint32_t                                    firstQuery,
        uint32_t                                    queryCount) {}
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
