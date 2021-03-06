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

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H

#include "decode/custom_vulkan_struct_decoders.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pnext_node.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkApplicationInfo
{
    using struct_type = VkApplicationInfo;

    VkApplicationInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pApplicationName;
    StringDecoder pEngineName;
};

struct Decoded_VkInstanceCreateInfo
{
    using struct_type = VkInstanceCreateInfo;

    VkInstanceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkApplicationInfo> pApplicationInfo;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
};

struct Decoded_VkAllocationCallbacks
{
    using struct_type = VkAllocationCallbacks;

    VkAllocationCallbacks* value{ nullptr };

    uint64_t pUserData{ 0 };
    uint64_t pfnAllocation{ 0 };
    uint64_t pfnReallocation{ 0 };
    uint64_t pfnFree{ 0 };
    uint64_t pfnInternalAllocation{ 0 };
    uint64_t pfnInternalFree{ 0 };
};

struct Decoded_VkPhysicalDeviceFeatures
{
    using struct_type = VkPhysicalDeviceFeatures;

    VkPhysicalDeviceFeatures* value{ nullptr };
};

struct Decoded_VkFormatProperties
{
    using struct_type = VkFormatProperties;

    VkFormatProperties* value{ nullptr };
};

struct Decoded_VkExtent3D
{
    using struct_type = VkExtent3D;

    VkExtent3D* value{ nullptr };
};

struct Decoded_VkImageFormatProperties
{
    using struct_type = VkImageFormatProperties;

    VkImageFormatProperties* value{ nullptr };

    Decoded_VkExtent3D maxExtent;
};

struct Decoded_VkPhysicalDeviceLimits
{
    using struct_type = VkPhysicalDeviceLimits;

    VkPhysicalDeviceLimits* value{ nullptr };

    PointerDecoder<uint32_t> maxComputeWorkGroupCount;
    PointerDecoder<uint32_t> maxComputeWorkGroupSize;
    PointerDecoder<uint32_t> maxViewportDimensions;
    PointerDecoder<float> viewportBoundsRange;
    PointerDecoder<float> pointSizeRange;
    PointerDecoder<float> lineWidthRange;
};

struct Decoded_VkPhysicalDeviceSparseProperties
{
    using struct_type = VkPhysicalDeviceSparseProperties;

    VkPhysicalDeviceSparseProperties* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties
{
    using struct_type = VkPhysicalDeviceProperties;

    VkPhysicalDeviceProperties* value{ nullptr };

    StringDecoder deviceName;
    PointerDecoder<uint8_t> pipelineCacheUUID;
    Decoded_VkPhysicalDeviceLimits limits;
    Decoded_VkPhysicalDeviceSparseProperties sparseProperties;
};

struct Decoded_VkQueueFamilyProperties
{
    using struct_type = VkQueueFamilyProperties;

    VkQueueFamilyProperties* value{ nullptr };

    Decoded_VkExtent3D minImageTransferGranularity;
};

struct Decoded_VkMemoryType
{
    using struct_type = VkMemoryType;

    VkMemoryType* value{ nullptr };
};

struct Decoded_VkMemoryHeap
{
    using struct_type = VkMemoryHeap;

    VkMemoryHeap* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryProperties
{
    using struct_type = VkPhysicalDeviceMemoryProperties;

    VkPhysicalDeviceMemoryProperties* value{ nullptr };

    StructPointerDecoder<Decoded_VkMemoryType> memoryTypes;
    StructPointerDecoder<Decoded_VkMemoryHeap> memoryHeaps;
};

struct Decoded_VkDeviceQueueCreateInfo
{
    using struct_type = VkDeviceQueueCreateInfo;

    VkDeviceQueueCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pQueuePriorities;
};

struct Decoded_VkDeviceCreateInfo
{
    using struct_type = VkDeviceCreateInfo;

    VkDeviceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDeviceQueueCreateInfo> pQueueCreateInfos;
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures> pEnabledFeatures;
};

struct Decoded_VkExtensionProperties
{
    using struct_type = VkExtensionProperties;

    VkExtensionProperties* value{ nullptr };

    StringDecoder extensionName;
};

struct Decoded_VkLayerProperties
{
    using struct_type = VkLayerProperties;

    VkLayerProperties* value{ nullptr };

    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_VkSubmitInfo
{
    using struct_type = VkSubmitInfo;

    VkSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    PointerDecoder<VkPipelineStageFlags> pWaitDstStageMask;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkMemoryAllocateInfo
{
    using struct_type = VkMemoryAllocateInfo;

    VkMemoryAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMappedMemoryRange
{
    using struct_type = VkMappedMemoryRange;

    VkMappedMemoryRange* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ 0 };
};

struct Decoded_VkMemoryRequirements
{
    using struct_type = VkMemoryRequirements;

    VkMemoryRequirements* value{ nullptr };
};

struct Decoded_VkSparseImageFormatProperties
{
    using struct_type = VkSparseImageFormatProperties;

    VkSparseImageFormatProperties* value{ nullptr };

    Decoded_VkExtent3D imageGranularity;
};

struct Decoded_VkSparseImageMemoryRequirements
{
    using struct_type = VkSparseImageMemoryRequirements;

    VkSparseImageMemoryRequirements* value{ nullptr };

    Decoded_VkSparseImageFormatProperties formatProperties;
};

struct Decoded_VkSparseMemoryBind
{
    using struct_type = VkSparseMemoryBind;

    VkSparseMemoryBind* value{ nullptr };

    format::HandleId memory{ 0 };
};

struct Decoded_VkSparseBufferMemoryBindInfo
{
    using struct_type = VkSparseBufferMemoryBindInfo;

    VkSparseBufferMemoryBindInfo* value{ nullptr };

    format::HandleId buffer{ 0 };
    StructPointerDecoder<Decoded_VkSparseMemoryBind> pBinds;
};

struct Decoded_VkSparseImageOpaqueMemoryBindInfo
{
    using struct_type = VkSparseImageOpaqueMemoryBindInfo;

    VkSparseImageOpaqueMemoryBindInfo* value{ nullptr };

    format::HandleId image{ 0 };
    StructPointerDecoder<Decoded_VkSparseMemoryBind> pBinds;
};

struct Decoded_VkImageSubresource
{
    using struct_type = VkImageSubresource;

    VkImageSubresource* value{ nullptr };
};

struct Decoded_VkOffset3D
{
    using struct_type = VkOffset3D;

    VkOffset3D* value{ nullptr };
};

struct Decoded_VkSparseImageMemoryBind
{
    using struct_type = VkSparseImageMemoryBind;

    VkSparseImageMemoryBind* value{ nullptr };

    Decoded_VkImageSubresource subresource;
    Decoded_VkOffset3D offset;
    Decoded_VkExtent3D extent;
    format::HandleId memory{ 0 };
};

struct Decoded_VkSparseImageMemoryBindInfo
{
    using struct_type = VkSparseImageMemoryBindInfo;

    VkSparseImageMemoryBindInfo* value{ nullptr };

    format::HandleId image{ 0 };
    StructPointerDecoder<Decoded_VkSparseImageMemoryBind> pBinds;
};

struct Decoded_VkBindSparseInfo
{
    using struct_type = VkBindSparseInfo;

    VkBindSparseInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo> pBufferBinds;
    StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo> pImageOpaqueBinds;
    StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo> pImageBinds;
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkFenceCreateInfo
{
    using struct_type = VkFenceCreateInfo;

    VkFenceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSemaphoreCreateInfo
{
    using struct_type = VkSemaphoreCreateInfo;

    VkSemaphoreCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkEventCreateInfo
{
    using struct_type = VkEventCreateInfo;

    VkEventCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueryPoolCreateInfo
{
    using struct_type = VkQueryPoolCreateInfo;

    VkQueryPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferCreateInfo
{
    using struct_type = VkBufferCreateInfo;

    VkBufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkBufferViewCreateInfo
{
    using struct_type = VkBufferViewCreateInfo;

    VkBufferViewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
};

struct Decoded_VkImageCreateInfo
{
    using struct_type = VkImageCreateInfo;

    VkImageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent3D extent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkSubresourceLayout
{
    using struct_type = VkSubresourceLayout;

    VkSubresourceLayout* value{ nullptr };
};

struct Decoded_VkComponentMapping
{
    using struct_type = VkComponentMapping;

    VkComponentMapping* value{ nullptr };
};

struct Decoded_VkImageSubresourceRange
{
    using struct_type = VkImageSubresourceRange;

    VkImageSubresourceRange* value{ nullptr };
};

struct Decoded_VkImageViewCreateInfo
{
    using struct_type = VkImageViewCreateInfo;

    VkImageViewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
    Decoded_VkComponentMapping components;
    Decoded_VkImageSubresourceRange subresourceRange;
};

struct Decoded_VkShaderModuleCreateInfo
{
    using struct_type = VkShaderModuleCreateInfo;

    VkShaderModuleCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pCode;
};

struct Decoded_VkPipelineCacheCreateInfo
{
    using struct_type = VkPipelineCacheCreateInfo;

    VkPipelineCacheCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkSpecializationMapEntry
{
    using struct_type = VkSpecializationMapEntry;

    VkSpecializationMapEntry* value{ nullptr };
};

struct Decoded_VkSpecializationInfo
{
    using struct_type = VkSpecializationInfo;

    VkSpecializationInfo* value{ nullptr };

    StructPointerDecoder<Decoded_VkSpecializationMapEntry> pMapEntries;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineShaderStageCreateInfo
{
    using struct_type = VkPipelineShaderStageCreateInfo;

    VkPipelineShaderStageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId module{ 0 };
    StringDecoder pName;
    StructPointerDecoder<Decoded_VkSpecializationInfo> pSpecializationInfo;
};

struct Decoded_VkVertexInputBindingDescription
{
    using struct_type = VkVertexInputBindingDescription;

    VkVertexInputBindingDescription* value{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription
{
    using struct_type = VkVertexInputAttributeDescription;

    VkVertexInputAttributeDescription* value{ nullptr };
};

struct Decoded_VkPipelineVertexInputStateCreateInfo
{
    using struct_type = VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription> pVertexBindingDescriptions;
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription> pVertexAttributeDescriptions;
};

struct Decoded_VkPipelineInputAssemblyStateCreateInfo
{
    using struct_type = VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationStateCreateInfo
{
    using struct_type = VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewport
{
    using struct_type = VkViewport;

    VkViewport* value{ nullptr };
};

struct Decoded_VkOffset2D
{
    using struct_type = VkOffset2D;

    VkOffset2D* value{ nullptr };
};

struct Decoded_VkExtent2D
{
    using struct_type = VkExtent2D;

    VkExtent2D* value{ nullptr };
};

struct Decoded_VkRect2D
{
    using struct_type = VkRect2D;

    VkRect2D* value{ nullptr };

    Decoded_VkOffset2D offset;
    Decoded_VkExtent2D extent;
};

struct Decoded_VkPipelineViewportStateCreateInfo
{
    using struct_type = VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewport> pViewports;
    StructPointerDecoder<Decoded_VkRect2D> pScissors;
};

struct Decoded_VkPipelineRasterizationStateCreateInfo
{
    using struct_type = VkPipelineRasterizationStateCreateInfo;

    VkPipelineRasterizationStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineMultisampleStateCreateInfo
{
    using struct_type = VkPipelineMultisampleStateCreateInfo;

    VkPipelineMultisampleStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkSampleMask> pSampleMask;
};

struct Decoded_VkStencilOpState
{
    using struct_type = VkStencilOpState;

    VkStencilOpState* value{ nullptr };
};

struct Decoded_VkPipelineDepthStencilStateCreateInfo
{
    using struct_type = VkPipelineDepthStencilStateCreateInfo;

    VkPipelineDepthStencilStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkStencilOpState front;
    Decoded_VkStencilOpState back;
};

struct Decoded_VkPipelineColorBlendAttachmentState
{
    using struct_type = VkPipelineColorBlendAttachmentState;

    VkPipelineColorBlendAttachmentState* value{ nullptr };
};

struct Decoded_VkPipelineColorBlendStateCreateInfo
{
    using struct_type = VkPipelineColorBlendStateCreateInfo;

    VkPipelineColorBlendStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState> pAttachments;
    PointerDecoder<float> blendConstants;
};

struct Decoded_VkPipelineDynamicStateCreateInfo
{
    using struct_type = VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDynamicState> pDynamicStates;
};

struct Decoded_VkGraphicsPipelineCreateInfo
{
    using struct_type = VkGraphicsPipelineCreateInfo;

    VkGraphicsPipelineCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo> pStages;
    StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo> pVertexInputState;
    StructPointerDecoder<Decoded_VkPipelineInputAssemblyStateCreateInfo> pInputAssemblyState;
    StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo> pTessellationState;
    StructPointerDecoder<Decoded_VkPipelineViewportStateCreateInfo> pViewportState;
    StructPointerDecoder<Decoded_VkPipelineRasterizationStateCreateInfo> pRasterizationState;
    StructPointerDecoder<Decoded_VkPipelineMultisampleStateCreateInfo> pMultisampleState;
    StructPointerDecoder<Decoded_VkPipelineDepthStencilStateCreateInfo> pDepthStencilState;
    StructPointerDecoder<Decoded_VkPipelineColorBlendStateCreateInfo> pColorBlendState;
    StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo> pDynamicState;
    format::HandleId layout{ 0 };
    format::HandleId renderPass{ 0 };
    format::HandleId basePipelineHandle{ 0 };
};

struct Decoded_VkComputePipelineCreateInfo
{
    using struct_type = VkComputePipelineCreateInfo;

    VkComputePipelineCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPipelineShaderStageCreateInfo stage;
    format::HandleId layout{ 0 };
    format::HandleId basePipelineHandle{ 0 };
};

struct Decoded_VkPushConstantRange
{
    using struct_type = VkPushConstantRange;

    VkPushConstantRange* value{ nullptr };
};

struct Decoded_VkPipelineLayoutCreateInfo
{
    using struct_type = VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange> pPushConstantRanges;
};

struct Decoded_VkSamplerCreateInfo
{
    using struct_type = VkSamplerCreateInfo;

    VkSamplerCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutBinding
{
    using struct_type = VkDescriptorSetLayoutBinding;

    VkDescriptorSetLayoutBinding* value{ nullptr };

    HandlePointerDecoder<VkSampler> pImmutableSamplers;
};

struct Decoded_VkDescriptorSetLayoutCreateInfo
{
    using struct_type = VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding> pBindings;
};

struct Decoded_VkDescriptorPoolSize
{
    using struct_type = VkDescriptorPoolSize;

    VkDescriptorPoolSize* value{ nullptr };
};

struct Decoded_VkDescriptorPoolCreateInfo
{
    using struct_type = VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorPoolSize> pPoolSizes;
};

struct Decoded_VkDescriptorSetAllocateInfo
{
    using struct_type = VkDescriptorSetAllocateInfo;

    VkDescriptorSetAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId descriptorPool{ 0 };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
};

struct Decoded_VkDescriptorImageInfo
{
    using struct_type = VkDescriptorImageInfo;

    VkDescriptorImageInfo* value{ nullptr };

    format::HandleId sampler{ 0 };
    format::HandleId imageView{ 0 };
};

struct Decoded_VkDescriptorBufferInfo
{
    using struct_type = VkDescriptorBufferInfo;

    VkDescriptorBufferInfo* value{ nullptr };

    format::HandleId buffer{ 0 };
};

struct Decoded_VkWriteDescriptorSet
{
    using struct_type = VkWriteDescriptorSet;

    VkWriteDescriptorSet* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId dstSet{ 0 };
    StructPointerDecoder<Decoded_VkDescriptorImageInfo> pImageInfo;
    StructPointerDecoder<Decoded_VkDescriptorBufferInfo> pBufferInfo;
    HandlePointerDecoder<VkBufferView> pTexelBufferView;
};

struct Decoded_VkCopyDescriptorSet
{
    using struct_type = VkCopyDescriptorSet;

    VkCopyDescriptorSet* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId srcSet{ 0 };
    format::HandleId dstSet{ 0 };
};

struct Decoded_VkFramebufferCreateInfo
{
    using struct_type = VkFramebufferCreateInfo;

    VkFramebufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ 0 };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkAttachmentDescription
{
    using struct_type = VkAttachmentDescription;

    VkAttachmentDescription* value{ nullptr };
};

struct Decoded_VkAttachmentReference
{
    using struct_type = VkAttachmentReference;

    VkAttachmentReference* value{ nullptr };
};

struct Decoded_VkSubpassDescription
{
    using struct_type = VkSubpassDescription;

    VkSubpassDescription* value{ nullptr };

    StructPointerDecoder<Decoded_VkAttachmentReference> pInputAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pColorAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pResolveAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency
{
    using struct_type = VkSubpassDependency;

    VkSubpassDependency* value{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo
{
    using struct_type = VkRenderPassCreateInfo;

    VkRenderPassCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentDescription> pAttachments;
    StructPointerDecoder<Decoded_VkSubpassDescription> pSubpasses;
    StructPointerDecoder<Decoded_VkSubpassDependency> pDependencies;
};

struct Decoded_VkCommandPoolCreateInfo
{
    using struct_type = VkCommandPoolCreateInfo;

    VkCommandPoolCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferAllocateInfo
{
    using struct_type = VkCommandBufferAllocateInfo;

    VkCommandBufferAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId commandPool{ 0 };
};

struct Decoded_VkCommandBufferInheritanceInfo
{
    using struct_type = VkCommandBufferInheritanceInfo;

    VkCommandBufferInheritanceInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ 0 };
    format::HandleId framebuffer{ 0 };
};

struct Decoded_VkCommandBufferBeginInfo
{
    using struct_type = VkCommandBufferBeginInfo;

    VkCommandBufferBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo> pInheritanceInfo;
};

struct Decoded_VkBufferCopy
{
    using struct_type = VkBufferCopy;

    VkBufferCopy* value{ nullptr };
};

struct Decoded_VkImageSubresourceLayers
{
    using struct_type = VkImageSubresourceLayers;

    VkImageSubresourceLayers* value{ nullptr };
};

struct Decoded_VkImageCopy
{
    using struct_type = VkImageCopy;

    VkImageCopy* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    Decoded_VkOffset3D srcOffset;
    Decoded_VkImageSubresourceLayers dstSubresource;
    Decoded_VkOffset3D dstOffset;
    Decoded_VkExtent3D extent;
};

struct Decoded_VkImageBlit
{
    using struct_type = VkImageBlit;

    VkImageBlit* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    StructPointerDecoder<Decoded_VkOffset3D> srcOffsets;
    Decoded_VkImageSubresourceLayers dstSubresource;
    StructPointerDecoder<Decoded_VkOffset3D> dstOffsets;
};

struct Decoded_VkBufferImageCopy
{
    using struct_type = VkBufferImageCopy;

    VkBufferImageCopy* value{ nullptr };

    Decoded_VkImageSubresourceLayers imageSubresource;
    Decoded_VkOffset3D imageOffset;
    Decoded_VkExtent3D imageExtent;
};

struct Decoded_VkClearDepthStencilValue
{
    using struct_type = VkClearDepthStencilValue;

    VkClearDepthStencilValue* value{ nullptr };
};

struct Decoded_VkClearAttachment
{
    using struct_type = VkClearAttachment;

    VkClearAttachment* value{ nullptr };

    Decoded_VkClearValue clearValue;
};

struct Decoded_VkClearRect
{
    using struct_type = VkClearRect;

    VkClearRect* value{ nullptr };

    Decoded_VkRect2D rect;
};

struct Decoded_VkImageResolve
{
    using struct_type = VkImageResolve;

    VkImageResolve* value{ nullptr };

    Decoded_VkImageSubresourceLayers srcSubresource;
    Decoded_VkOffset3D srcOffset;
    Decoded_VkImageSubresourceLayers dstSubresource;
    Decoded_VkOffset3D dstOffset;
    Decoded_VkExtent3D extent;
};

struct Decoded_VkMemoryBarrier
{
    using struct_type = VkMemoryBarrier;

    VkMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferMemoryBarrier
{
    using struct_type = VkBufferMemoryBarrier;

    VkBufferMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
};

struct Decoded_VkImageMemoryBarrier
{
    using struct_type = VkImageMemoryBarrier;

    VkImageMemoryBarrier* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
    Decoded_VkImageSubresourceRange subresourceRange;
};

struct Decoded_VkRenderPassBeginInfo
{
    using struct_type = VkRenderPassBeginInfo;

    VkRenderPassBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId renderPass{ 0 };
    format::HandleId framebuffer{ 0 };
    Decoded_VkRect2D renderArea;
    StructPointerDecoder<Decoded_VkClearValue> pClearValues;
};

struct Decoded_VkDispatchIndirectCommand
{
    using struct_type = VkDispatchIndirectCommand;

    VkDispatchIndirectCommand* value{ nullptr };
};

struct Decoded_VkDrawIndexedIndirectCommand
{
    using struct_type = VkDrawIndexedIndirectCommand;

    VkDrawIndexedIndirectCommand* value{ nullptr };
};

struct Decoded_VkDrawIndirectCommand
{
    using struct_type = VkDrawIndirectCommand;

    VkDrawIndirectCommand* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupProperties
{
    using struct_type = VkPhysicalDeviceSubgroupProperties;

    VkPhysicalDeviceSubgroupProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryInfo
{
    using struct_type = VkBindBufferMemoryInfo;

    VkBindBufferMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
    format::HandleId memory{ 0 };
};

struct Decoded_VkBindImageMemoryInfo
{
    using struct_type = VkBindImageMemoryInfo;

    VkBindImageMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
    format::HandleId memory{ 0 };
};

struct Decoded_VkPhysicalDevice16BitStorageFeatures
{
    using struct_type = VkPhysicalDevice16BitStorageFeatures;

    VkPhysicalDevice16BitStorageFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedRequirements
{
    using struct_type = VkMemoryDedicatedRequirements;

    VkMemoryDedicatedRequirements* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryDedicatedAllocateInfo
{
    using struct_type = VkMemoryDedicatedAllocateInfo;

    VkMemoryDedicatedAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
    format::HandleId buffer{ 0 };
};

struct Decoded_VkMemoryAllocateFlagsInfo
{
    using struct_type = VkMemoryAllocateFlagsInfo;

    VkMemoryAllocateFlagsInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupRenderPassBeginInfo
{
    using struct_type = VkDeviceGroupRenderPassBeginInfo;

    VkDeviceGroupRenderPassBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkRect2D> pDeviceRenderAreas;
};

struct Decoded_VkDeviceGroupCommandBufferBeginInfo
{
    using struct_type = VkDeviceGroupCommandBufferBeginInfo;

    VkDeviceGroupCommandBufferBeginInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGroupSubmitInfo
{
    using struct_type = VkDeviceGroupSubmitInfo;

    VkDeviceGroupSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pWaitSemaphoreDeviceIndices;
    PointerDecoder<uint32_t> pCommandBufferDeviceMasks;
    PointerDecoder<uint32_t> pSignalSemaphoreDeviceIndices;
};

struct Decoded_VkDeviceGroupBindSparseInfo
{
    using struct_type = VkDeviceGroupBindSparseInfo;

    VkDeviceGroupBindSparseInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBindBufferMemoryDeviceGroupInfo
{
    using struct_type = VkBindBufferMemoryDeviceGroupInfo;

    VkBindBufferMemoryDeviceGroupInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkBindImageMemoryDeviceGroupInfo
{
    using struct_type = VkBindImageMemoryDeviceGroupInfo;

    VkBindImageMemoryDeviceGroupInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceIndices;
    StructPointerDecoder<Decoded_VkRect2D> pSplitInstanceBindRegions;
};

struct Decoded_VkPhysicalDeviceGroupProperties
{
    using struct_type = VkPhysicalDeviceGroupProperties;

    VkPhysicalDeviceGroupProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkPhysicalDevice> physicalDevices;
};

struct Decoded_VkDeviceGroupDeviceCreateInfo
{
    using struct_type = VkDeviceGroupDeviceCreateInfo;

    VkDeviceGroupDeviceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
};

struct Decoded_VkBufferMemoryRequirementsInfo2
{
    using struct_type = VkBufferMemoryRequirementsInfo2;

    VkBufferMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
};

struct Decoded_VkImageMemoryRequirementsInfo2
{
    using struct_type = VkImageMemoryRequirementsInfo2;

    VkImageMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
};

struct Decoded_VkImageSparseMemoryRequirementsInfo2
{
    using struct_type = VkImageSparseMemoryRequirementsInfo2;

    VkImageSparseMemoryRequirementsInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
};

struct Decoded_VkMemoryRequirements2
{
    using struct_type = VkMemoryRequirements2;

    VkMemoryRequirements2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkMemoryRequirements memoryRequirements;
};

struct Decoded_VkSparseImageMemoryRequirements2
{
    using struct_type = VkSparseImageMemoryRequirements2;

    VkSparseImageMemoryRequirements2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSparseImageMemoryRequirements memoryRequirements;
};

struct Decoded_VkPhysicalDeviceFeatures2
{
    using struct_type = VkPhysicalDeviceFeatures2;

    VkPhysicalDeviceFeatures2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceFeatures features;
};

struct Decoded_VkPhysicalDeviceProperties2
{
    using struct_type = VkPhysicalDeviceProperties2;

    VkPhysicalDeviceProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceProperties properties;
};

struct Decoded_VkFormatProperties2
{
    using struct_type = VkFormatProperties2;

    VkFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkFormatProperties formatProperties;
};

struct Decoded_VkImageFormatProperties2
{
    using struct_type = VkImageFormatProperties2;

    VkImageFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkImageFormatProperties imageFormatProperties;
};

struct Decoded_VkPhysicalDeviceImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceImageFormatInfo2;

    VkPhysicalDeviceImageFormatInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueueFamilyProperties2
{
    using struct_type = VkQueueFamilyProperties2;

    VkQueueFamilyProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkQueueFamilyProperties queueFamilyProperties;
};

struct Decoded_VkPhysicalDeviceMemoryProperties2
{
    using struct_type = VkPhysicalDeviceMemoryProperties2;

    VkPhysicalDeviceMemoryProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkPhysicalDeviceMemoryProperties memoryProperties;
};

struct Decoded_VkSparseImageFormatProperties2
{
    using struct_type = VkSparseImageFormatProperties2;

    VkSparseImageFormatProperties2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSparseImageFormatProperties properties;
};

struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceSparseImageFormatInfo2;

    VkPhysicalDeviceSparseImageFormatInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDevicePointClippingProperties
{
    using struct_type = VkPhysicalDevicePointClippingProperties;

    VkPhysicalDevicePointClippingProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkInputAttachmentAspectReference
{
    using struct_type = VkInputAttachmentAspectReference;

    VkInputAttachmentAspectReference* value{ nullptr };
};

struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo
{
    using struct_type = VkRenderPassInputAttachmentAspectCreateInfo;

    VkRenderPassInputAttachmentAspectCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkInputAttachmentAspectReference> pAspectReferences;
};

struct Decoded_VkImageViewUsageCreateInfo
{
    using struct_type = VkImageViewUsageCreateInfo;

    VkImageViewUsageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo
{
    using struct_type = VkPipelineTessellationDomainOriginStateCreateInfo;

    VkPipelineTessellationDomainOriginStateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassMultiviewCreateInfo
{
    using struct_type = VkRenderPassMultiviewCreateInfo;

    VkRenderPassMultiviewCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pViewMasks;
    PointerDecoder<int32_t> pViewOffsets;
    PointerDecoder<uint32_t> pCorrelationMasks;
};

struct Decoded_VkPhysicalDeviceMultiviewFeatures
{
    using struct_type = VkPhysicalDeviceMultiviewFeatures;

    VkPhysicalDeviceMultiviewFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMultiviewProperties
{
    using struct_type = VkPhysicalDeviceMultiviewProperties;

    VkPhysicalDeviceMultiviewProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVariablePointerFeatures
{
    using struct_type = VkPhysicalDeviceVariablePointerFeatures;

    VkPhysicalDeviceVariablePointerFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures
{
    using struct_type = VkPhysicalDeviceProtectedMemoryFeatures;

    VkPhysicalDeviceProtectedMemoryFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceProtectedMemoryProperties
{
    using struct_type = VkPhysicalDeviceProtectedMemoryProperties;

    VkPhysicalDeviceProtectedMemoryProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueInfo2
{
    using struct_type = VkDeviceQueueInfo2;

    VkDeviceQueueInfo2* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkProtectedSubmitInfo
{
    using struct_type = VkProtectedSubmitInfo;

    VkProtectedSubmitInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionCreateInfo
{
    using struct_type = VkSamplerYcbcrConversionCreateInfo;

    VkSamplerYcbcrConversionCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkComponentMapping components;
};

struct Decoded_VkSamplerYcbcrConversionInfo
{
    using struct_type = VkSamplerYcbcrConversionInfo;

    VkSamplerYcbcrConversionInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId conversion{ 0 };
};

struct Decoded_VkBindImagePlaneMemoryInfo
{
    using struct_type = VkBindImagePlaneMemoryInfo;

    VkBindImagePlaneMemoryInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImagePlaneMemoryRequirementsInfo
{
    using struct_type = VkImagePlaneMemoryRequirementsInfo;

    VkImagePlaneMemoryRequirementsInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
    using struct_type = VkPhysicalDeviceSamplerYcbcrConversionFeatures;

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerYcbcrConversionImageFormatProperties
{
    using struct_type = VkSamplerYcbcrConversionImageFormatProperties;

    VkSamplerYcbcrConversionImageFormatProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorUpdateTemplateEntry
{
    using struct_type = VkDescriptorUpdateTemplateEntry;

    VkDescriptorUpdateTemplateEntry* value{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateCreateInfo
{
    using struct_type = VkDescriptorUpdateTemplateCreateInfo;

    VkDescriptorUpdateTemplateCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry> pDescriptorUpdateEntries;
    format::HandleId descriptorSetLayout{ 0 };
    format::HandleId pipelineLayout{ 0 };
};

struct Decoded_VkExternalMemoryProperties
{
    using struct_type = VkExternalMemoryProperties;

    VkExternalMemoryProperties* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalImageFormatInfo
{
    using struct_type = VkPhysicalDeviceExternalImageFormatInfo;

    VkPhysicalDeviceExternalImageFormatInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalImageFormatProperties
{
    using struct_type = VkExternalImageFormatProperties;

    VkExternalImageFormatProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExternalMemoryProperties externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceExternalBufferInfo
{
    using struct_type = VkPhysicalDeviceExternalBufferInfo;

    VkPhysicalDeviceExternalBufferInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalBufferProperties
{
    using struct_type = VkExternalBufferProperties;

    VkExternalBufferProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExternalMemoryProperties externalMemoryProperties;
};

struct Decoded_VkPhysicalDeviceIDProperties
{
    using struct_type = VkPhysicalDeviceIDProperties;

    VkPhysicalDeviceIDProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkExternalMemoryImageCreateInfo
{
    using struct_type = VkExternalMemoryImageCreateInfo;

    VkExternalMemoryImageCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalMemoryBufferCreateInfo
{
    using struct_type = VkExternalMemoryBufferCreateInfo;

    VkExternalMemoryBufferCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfo
{
    using struct_type = VkExportMemoryAllocateInfo;

    VkExportMemoryAllocateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalFenceInfo
{
    using struct_type = VkPhysicalDeviceExternalFenceInfo;

    VkPhysicalDeviceExternalFenceInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalFenceProperties
{
    using struct_type = VkExternalFenceProperties;

    VkExternalFenceProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportFenceCreateInfo
{
    using struct_type = VkExportFenceCreateInfo;

    VkExportFenceCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportSemaphoreCreateInfo
{
    using struct_type = VkExportSemaphoreCreateInfo;

    VkExportSemaphoreCreateInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo
{
    using struct_type = VkPhysicalDeviceExternalSemaphoreInfo;

    VkPhysicalDeviceExternalSemaphoreInfo* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalSemaphoreProperties
{
    using struct_type = VkExternalSemaphoreProperties;

    VkExternalSemaphoreProperties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMaintenance3Properties
{
    using struct_type = VkPhysicalDeviceMaintenance3Properties;

    VkPhysicalDeviceMaintenance3Properties* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetLayoutSupport
{
    using struct_type = VkDescriptorSetLayoutSupport;

    VkDescriptorSetLayoutSupport* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderDrawParameterFeatures
{
    using struct_type = VkPhysicalDeviceShaderDrawParameterFeatures;

    VkPhysicalDeviceShaderDrawParameterFeatures* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkMemoryRequirements2 Decoded_VkMemoryRequirements2KHR;

struct Decoded_VkSurfaceCapabilitiesKHR
{
    using struct_type = VkSurfaceCapabilitiesKHR;

    VkSurfaceCapabilitiesKHR* value{ nullptr };

    Decoded_VkExtent2D currentExtent;
    Decoded_VkExtent2D minImageExtent;
    Decoded_VkExtent2D maxImageExtent;
};

struct Decoded_VkSurfaceFormatKHR
{
    using struct_type = VkSurfaceFormatKHR;

    VkSurfaceFormatKHR* value{ nullptr };
};

struct Decoded_VkSwapchainCreateInfoKHR
{
    using struct_type = VkSwapchainCreateInfoKHR;

    VkSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId surface{ 0 };
    Decoded_VkExtent2D imageExtent;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
    format::HandleId oldSwapchain{ 0 };
};

struct Decoded_VkPresentInfoKHR
{
    using struct_type = VkPresentInfoKHR;

    VkPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    PointerDecoder<uint32_t> pImageIndices;
    PointerDecoder<VkResult> pResults;
};

struct Decoded_VkImageSwapchainCreateInfoKHR
{
    using struct_type = VkImageSwapchainCreateInfoKHR;

    VkImageSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ 0 };
};

struct Decoded_VkBindImageMemorySwapchainInfoKHR
{
    using struct_type = VkBindImageMemorySwapchainInfoKHR;

    VkBindImageMemorySwapchainInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ 0 };
};

struct Decoded_VkAcquireNextImageInfoKHR
{
    using struct_type = VkAcquireNextImageInfoKHR;

    VkAcquireNextImageInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId swapchain{ 0 };
    format::HandleId semaphore{ 0 };
    format::HandleId fence{ 0 };
};

struct Decoded_VkDeviceGroupPresentCapabilitiesKHR
{
    using struct_type = VkDeviceGroupPresentCapabilitiesKHR;

    VkDeviceGroupPresentCapabilitiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> presentMask;
};

struct Decoded_VkDeviceGroupPresentInfoKHR
{
    using struct_type = VkDeviceGroupPresentInfoKHR;

    VkDeviceGroupPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDeviceMasks;
};

struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR
{
    using struct_type = VkDeviceGroupSwapchainCreateInfoKHR;

    VkDeviceGroupSwapchainCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayPropertiesKHR
{
    using struct_type = VkDisplayPropertiesKHR;

    VkDisplayPropertiesKHR* value{ nullptr };

    format::HandleId display{ 0 };
    StringDecoder displayName;
    Decoded_VkExtent2D physicalDimensions;
    Decoded_VkExtent2D physicalResolution;
};

struct Decoded_VkDisplayModeParametersKHR
{
    using struct_type = VkDisplayModeParametersKHR;

    VkDisplayModeParametersKHR* value{ nullptr };

    Decoded_VkExtent2D visibleRegion;
};

struct Decoded_VkDisplayModePropertiesKHR
{
    using struct_type = VkDisplayModePropertiesKHR;

    VkDisplayModePropertiesKHR* value{ nullptr };

    format::HandleId displayMode{ 0 };
    Decoded_VkDisplayModeParametersKHR parameters;
};

struct Decoded_VkDisplayModeCreateInfoKHR
{
    using struct_type = VkDisplayModeCreateInfoKHR;

    VkDisplayModeCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayModeParametersKHR parameters;
};

struct Decoded_VkDisplayPlaneCapabilitiesKHR
{
    using struct_type = VkDisplayPlaneCapabilitiesKHR;

    VkDisplayPlaneCapabilitiesKHR* value{ nullptr };

    Decoded_VkOffset2D minSrcPosition;
    Decoded_VkOffset2D maxSrcPosition;
    Decoded_VkExtent2D minSrcExtent;
    Decoded_VkExtent2D maxSrcExtent;
    Decoded_VkOffset2D minDstPosition;
    Decoded_VkOffset2D maxDstPosition;
    Decoded_VkExtent2D minDstExtent;
    Decoded_VkExtent2D maxDstExtent;
};

struct Decoded_VkDisplayPlanePropertiesKHR
{
    using struct_type = VkDisplayPlanePropertiesKHR;

    VkDisplayPlanePropertiesKHR* value{ nullptr };

    format::HandleId currentDisplay{ 0 };
};

struct Decoded_VkDisplaySurfaceCreateInfoKHR
{
    using struct_type = VkDisplaySurfaceCreateInfoKHR;

    VkDisplaySurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId displayMode{ 0 };
    Decoded_VkExtent2D imageExtent;
};

struct Decoded_VkDisplayPresentInfoKHR
{
    using struct_type = VkDisplayPresentInfoKHR;

    VkDisplayPresentInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkRect2D srcRect;
    Decoded_VkRect2D dstRect;
};

struct Decoded_VkXlibSurfaceCreateInfoKHR
{
    using struct_type = VkXlibSurfaceCreateInfoKHR;

    VkXlibSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t dpy{ 0 };
};

struct Decoded_VkXcbSurfaceCreateInfoKHR
{
    using struct_type = VkXcbSurfaceCreateInfoKHR;

    VkXcbSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t connection{ 0 };
};

struct Decoded_VkWaylandSurfaceCreateInfoKHR
{
    using struct_type = VkWaylandSurfaceCreateInfoKHR;

    VkWaylandSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t display{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkAndroidSurfaceCreateInfoKHR
{
    using struct_type = VkAndroidSurfaceCreateInfoKHR;

    VkAndroidSurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t window{ 0 };
};

struct Decoded_VkWin32SurfaceCreateInfoKHR
{
    using struct_type = VkWin32SurfaceCreateInfoKHR;

    VkWin32SurfaceCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t hinstance{ 0 };
    uint64_t hwnd{ 0 };
};

typedef Decoded_VkRenderPassMultiviewCreateInfo Decoded_VkRenderPassMultiviewCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceMultiviewFeatures Decoded_VkPhysicalDeviceMultiviewFeaturesKHR;

typedef Decoded_VkPhysicalDeviceMultiviewProperties Decoded_VkPhysicalDeviceMultiviewPropertiesKHR;

typedef Decoded_VkPhysicalDeviceFeatures2 Decoded_VkPhysicalDeviceFeatures2KHR;

typedef Decoded_VkPhysicalDeviceProperties2 Decoded_VkPhysicalDeviceProperties2KHR;

typedef Decoded_VkFormatProperties2 Decoded_VkFormatProperties2KHR;

typedef Decoded_VkImageFormatProperties2 Decoded_VkImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceImageFormatInfo2 Decoded_VkPhysicalDeviceImageFormatInfo2KHR;

typedef Decoded_VkQueueFamilyProperties2 Decoded_VkQueueFamilyProperties2KHR;

typedef Decoded_VkPhysicalDeviceMemoryProperties2 Decoded_VkPhysicalDeviceMemoryProperties2KHR;

typedef Decoded_VkSparseImageFormatProperties2 Decoded_VkSparseImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceSparseImageFormatInfo2 Decoded_VkPhysicalDeviceSparseImageFormatInfo2KHR;

typedef Decoded_VkMemoryAllocateFlagsInfo Decoded_VkMemoryAllocateFlagsInfoKHR;

typedef Decoded_VkDeviceGroupRenderPassBeginInfo Decoded_VkDeviceGroupRenderPassBeginInfoKHR;

typedef Decoded_VkDeviceGroupCommandBufferBeginInfo Decoded_VkDeviceGroupCommandBufferBeginInfoKHR;

typedef Decoded_VkDeviceGroupSubmitInfo Decoded_VkDeviceGroupSubmitInfoKHR;

typedef Decoded_VkDeviceGroupBindSparseInfo Decoded_VkDeviceGroupBindSparseInfoKHR;

typedef Decoded_VkBindBufferMemoryDeviceGroupInfo Decoded_VkBindBufferMemoryDeviceGroupInfoKHR;

typedef Decoded_VkBindImageMemoryDeviceGroupInfo Decoded_VkBindImageMemoryDeviceGroupInfoKHR;

typedef Decoded_VkPhysicalDeviceGroupProperties Decoded_VkPhysicalDeviceGroupPropertiesKHR;

typedef Decoded_VkDeviceGroupDeviceCreateInfo Decoded_VkDeviceGroupDeviceCreateInfoKHR;

typedef Decoded_VkExternalMemoryProperties Decoded_VkExternalMemoryPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalImageFormatInfo Decoded_VkPhysicalDeviceExternalImageFormatInfoKHR;

typedef Decoded_VkExternalImageFormatProperties Decoded_VkExternalImageFormatPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalBufferInfo Decoded_VkPhysicalDeviceExternalBufferInfoKHR;

typedef Decoded_VkExternalBufferProperties Decoded_VkExternalBufferPropertiesKHR;

typedef Decoded_VkPhysicalDeviceIDProperties Decoded_VkPhysicalDeviceIDPropertiesKHR;

typedef Decoded_VkExternalMemoryImageCreateInfo Decoded_VkExternalMemoryImageCreateInfoKHR;

typedef Decoded_VkExternalMemoryBufferCreateInfo Decoded_VkExternalMemoryBufferCreateInfoKHR;

typedef Decoded_VkExportMemoryAllocateInfo Decoded_VkExportMemoryAllocateInfoKHR;

struct Decoded_VkImportMemoryWin32HandleInfoKHR
{
    using struct_type = VkImportMemoryWin32HandleInfoKHR;

    VkImportMemoryWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportMemoryWin32HandleInfoKHR
{
    using struct_type = VkExportMemoryWin32HandleInfoKHR;

    VkExportMemoryWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkMemoryWin32HandlePropertiesKHR
{
    using struct_type = VkMemoryWin32HandlePropertiesKHR;

    VkMemoryWin32HandlePropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetWin32HandleInfoKHR
{
    using struct_type = VkMemoryGetWin32HandleInfoKHR;

    VkMemoryGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ 0 };
};

struct Decoded_VkImportMemoryFdInfoKHR
{
    using struct_type = VkImportMemoryFdInfoKHR;

    VkImportMemoryFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryFdPropertiesKHR
{
    using struct_type = VkMemoryFdPropertiesKHR;

    VkMemoryFdPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryGetFdInfoKHR
{
    using struct_type = VkMemoryGetFdInfoKHR;

    VkMemoryGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ 0 };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoKHR;

    VkWin32KeyedMutexAcquireReleaseInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeouts;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

typedef Decoded_VkPhysicalDeviceExternalSemaphoreInfo Decoded_VkPhysicalDeviceExternalSemaphoreInfoKHR;

typedef Decoded_VkExternalSemaphoreProperties Decoded_VkExternalSemaphorePropertiesKHR;

typedef Decoded_VkExportSemaphoreCreateInfo Decoded_VkExportSemaphoreCreateInfoKHR;

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkImportSemaphoreWin32HandleInfoKHR;

    VkImportSemaphoreWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ 0 };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkExportSemaphoreWin32HandleInfoKHR;

    VkExportSemaphoreWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkD3D12FenceSubmitInfoKHR
{
    using struct_type = VkD3D12FenceSubmitInfoKHR;

    VkD3D12FenceSubmitInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreGetWin32HandleInfoKHR
{
    using struct_type = VkSemaphoreGetWin32HandleInfoKHR;

    VkSemaphoreGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ 0 };
};

struct Decoded_VkImportSemaphoreFdInfoKHR
{
    using struct_type = VkImportSemaphoreFdInfoKHR;

    VkImportSemaphoreFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ 0 };
};

struct Decoded_VkSemaphoreGetFdInfoKHR
{
    using struct_type = VkSemaphoreGetFdInfoKHR;

    VkSemaphoreGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId semaphore{ 0 };
};

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR
{
    using struct_type = VkPhysicalDevicePushDescriptorPropertiesKHR;

    VkPhysicalDevicePushDescriptorPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR
{
    using struct_type = VkPhysicalDeviceFloat16Int8FeaturesKHR;

    VkPhysicalDeviceFloat16Int8FeaturesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDevice16BitStorageFeatures Decoded_VkPhysicalDevice16BitStorageFeaturesKHR;

struct Decoded_VkRectLayerKHR
{
    using struct_type = VkRectLayerKHR;

    VkRectLayerKHR* value{ nullptr };

    Decoded_VkOffset2D offset;
    Decoded_VkExtent2D extent;
};

struct Decoded_VkPresentRegionKHR
{
    using struct_type = VkPresentRegionKHR;

    VkPresentRegionKHR* value{ nullptr };

    StructPointerDecoder<Decoded_VkRectLayerKHR> pRectangles;
};

struct Decoded_VkPresentRegionsKHR
{
    using struct_type = VkPresentRegionsKHR;

    VkPresentRegionsKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPresentRegionKHR> pRegions;
};

typedef Decoded_VkDescriptorUpdateTemplateEntry Decoded_VkDescriptorUpdateTemplateEntryKHR;

typedef Decoded_VkDescriptorUpdateTemplateCreateInfo Decoded_VkDescriptorUpdateTemplateCreateInfoKHR;

struct Decoded_VkAttachmentDescription2KHR
{
    using struct_type = VkAttachmentDescription2KHR;

    VkAttachmentDescription2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAttachmentReference2KHR
{
    using struct_type = VkAttachmentReference2KHR;

    VkAttachmentReference2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassDescription2KHR
{
    using struct_type = VkSubpassDescription2KHR;

    VkSubpassDescription2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pInputAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pColorAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pResolveAttachments;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pDepthStencilAttachment;
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency2KHR
{
    using struct_type = VkSubpassDependency2KHR;

    VkSubpassDependency2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRenderPassCreateInfo2KHR
{
    using struct_type = VkRenderPassCreateInfo2KHR;

    VkRenderPassCreateInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentDescription2KHR> pAttachments;
    StructPointerDecoder<Decoded_VkSubpassDescription2KHR> pSubpasses;
    StructPointerDecoder<Decoded_VkSubpassDependency2KHR> pDependencies;
    PointerDecoder<uint32_t> pCorrelatedViewMasks;
};

struct Decoded_VkSubpassBeginInfoKHR
{
    using struct_type = VkSubpassBeginInfoKHR;

    VkSubpassBeginInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassEndInfoKHR
{
    using struct_type = VkSubpassEndInfoKHR;

    VkSubpassEndInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR
{
    using struct_type = VkSharedPresentSurfaceCapabilitiesKHR;

    VkSharedPresentSurfaceCapabilitiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

typedef Decoded_VkPhysicalDeviceExternalFenceInfo Decoded_VkPhysicalDeviceExternalFenceInfoKHR;

typedef Decoded_VkExternalFenceProperties Decoded_VkExternalFencePropertiesKHR;

typedef Decoded_VkExportFenceCreateInfo Decoded_VkExportFenceCreateInfoKHR;

struct Decoded_VkImportFenceWin32HandleInfoKHR
{
    using struct_type = VkImportFenceWin32HandleInfoKHR;

    VkImportFenceWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ 0 };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportFenceWin32HandleInfoKHR
{
    using struct_type = VkExportFenceWin32HandleInfoKHR;

    VkExportFenceWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES> pAttributes;
    WStringDecoder name;
};

struct Decoded_VkFenceGetWin32HandleInfoKHR
{
    using struct_type = VkFenceGetWin32HandleInfoKHR;

    VkFenceGetWin32HandleInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ 0 };
};

struct Decoded_VkImportFenceFdInfoKHR
{
    using struct_type = VkImportFenceFdInfoKHR;

    VkImportFenceFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ 0 };
};

struct Decoded_VkFenceGetFdInfoKHR
{
    using struct_type = VkFenceGetFdInfoKHR;

    VkFenceGetFdInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId fence{ 0 };
};

typedef Decoded_VkPhysicalDevicePointClippingProperties Decoded_VkPhysicalDevicePointClippingPropertiesKHR;

typedef Decoded_VkRenderPassInputAttachmentAspectCreateInfo Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR;

typedef Decoded_VkInputAttachmentAspectReference Decoded_VkInputAttachmentAspectReferenceKHR;

typedef Decoded_VkImageViewUsageCreateInfo Decoded_VkImageViewUsageCreateInfoKHR;

typedef Decoded_VkPipelineTessellationDomainOriginStateCreateInfo Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR;

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR
{
    using struct_type = VkPhysicalDeviceSurfaceInfo2KHR;

    VkPhysicalDeviceSurfaceInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId surface{ 0 };
};

struct Decoded_VkSurfaceCapabilities2KHR
{
    using struct_type = VkSurfaceCapabilities2KHR;

    VkSurfaceCapabilities2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSurfaceCapabilitiesKHR surfaceCapabilities;
};

struct Decoded_VkSurfaceFormat2KHR
{
    using struct_type = VkSurfaceFormat2KHR;

    VkSurfaceFormat2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSurfaceFormatKHR surfaceFormat;
};

typedef Decoded_VkPhysicalDeviceVariablePointerFeatures Decoded_VkPhysicalDeviceVariablePointerFeaturesKHR;

struct Decoded_VkDisplayProperties2KHR
{
    using struct_type = VkDisplayProperties2KHR;

    VkDisplayProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPropertiesKHR displayProperties;
};

struct Decoded_VkDisplayPlaneProperties2KHR
{
    using struct_type = VkDisplayPlaneProperties2KHR;

    VkDisplayPlaneProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPlanePropertiesKHR displayPlaneProperties;
};

struct Decoded_VkDisplayModeProperties2KHR
{
    using struct_type = VkDisplayModeProperties2KHR;

    VkDisplayModeProperties2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayModePropertiesKHR displayModeProperties;
};

struct Decoded_VkDisplayPlaneInfo2KHR
{
    using struct_type = VkDisplayPlaneInfo2KHR;

    VkDisplayPlaneInfo2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId mode{ 0 };
};

struct Decoded_VkDisplayPlaneCapabilities2KHR
{
    using struct_type = VkDisplayPlaneCapabilities2KHR;

    VkDisplayPlaneCapabilities2KHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkDisplayPlaneCapabilitiesKHR capabilities;
};

typedef Decoded_VkMemoryDedicatedRequirements Decoded_VkMemoryDedicatedRequirementsKHR;

typedef Decoded_VkMemoryDedicatedAllocateInfo Decoded_VkMemoryDedicatedAllocateInfoKHR;

typedef Decoded_VkBufferMemoryRequirementsInfo2 Decoded_VkBufferMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageMemoryRequirementsInfo2 Decoded_VkImageMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageSparseMemoryRequirementsInfo2 Decoded_VkImageSparseMemoryRequirementsInfo2KHR;

typedef Decoded_VkSparseImageMemoryRequirements2 Decoded_VkSparseImageMemoryRequirements2KHR;

struct Decoded_VkImageFormatListCreateInfoKHR
{
    using struct_type = VkImageFormatListCreateInfoKHR;

    VkImageFormatListCreateInfoKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkFormat> pViewFormats;
};

typedef Decoded_VkSamplerYcbcrConversionCreateInfo Decoded_VkSamplerYcbcrConversionCreateInfoKHR;

typedef Decoded_VkSamplerYcbcrConversionInfo Decoded_VkSamplerYcbcrConversionInfoKHR;

typedef Decoded_VkBindImagePlaneMemoryInfo Decoded_VkBindImagePlaneMemoryInfoKHR;

typedef Decoded_VkImagePlaneMemoryRequirementsInfo Decoded_VkImagePlaneMemoryRequirementsInfoKHR;

typedef Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR;

typedef Decoded_VkSamplerYcbcrConversionImageFormatProperties Decoded_VkSamplerYcbcrConversionImageFormatPropertiesKHR;

typedef Decoded_VkBindBufferMemoryInfo Decoded_VkBindBufferMemoryInfoKHR;

typedef Decoded_VkBindImageMemoryInfo Decoded_VkBindImageMemoryInfoKHR;

typedef Decoded_VkPhysicalDeviceMaintenance3Properties Decoded_VkPhysicalDeviceMaintenance3PropertiesKHR;

typedef Decoded_VkDescriptorSetLayoutSupport Decoded_VkDescriptorSetLayoutSupportKHR;

struct Decoded_VkPhysicalDevice8BitStorageFeaturesKHR
{
    using struct_type = VkPhysicalDevice8BitStorageFeaturesKHR;

    VkPhysicalDevice8BitStorageFeaturesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderAtomicInt64FeaturesKHR;

    VkPhysicalDeviceShaderAtomicInt64FeaturesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkConformanceVersionKHR
{
    using struct_type = VkConformanceVersionKHR;

    VkConformanceVersionKHR* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceDriverPropertiesKHR
{
    using struct_type = VkPhysicalDeviceDriverPropertiesKHR;

    VkPhysicalDeviceDriverPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder driverName;
    StringDecoder driverInfo;
    Decoded_VkConformanceVersionKHR conformanceVersion;
};

struct Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR
{
    using struct_type = VkPhysicalDeviceFloatControlsPropertiesKHR;

    VkPhysicalDeviceFloatControlsPropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSubpassDescriptionDepthStencilResolveKHR
{
    using struct_type = VkSubpassDescriptionDepthStencilResolveKHR;

    VkSubpassDescriptionDepthStencilResolveKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentReference2KHR> pDepthStencilResolveAttachment;
};

struct Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR
{
    using struct_type = VkPhysicalDeviceDepthStencilResolvePropertiesKHR;

    VkPhysicalDeviceDepthStencilResolvePropertiesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR
{
    using struct_type = VkPhysicalDeviceVulkanMemoryModelFeaturesKHR;

    VkPhysicalDeviceVulkanMemoryModelFeaturesKHR* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDebugReportCallbackCreateInfoEXT
{
    using struct_type = VkDebugReportCallbackCreateInfoEXT;

    VkDebugReportCallbackCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD
{
    using struct_type = VkPipelineRasterizationStateRasterizationOrderAMD;

    VkPipelineRasterizationStateRasterizationOrderAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDebugMarkerObjectNameInfoEXT
{
    using struct_type = VkDebugMarkerObjectNameInfoEXT;

    VkDebugMarkerObjectNameInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugMarkerObjectTagInfoEXT
{
    using struct_type = VkDebugMarkerObjectTagInfoEXT;

    VkDebugMarkerObjectTagInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugMarkerMarkerInfoEXT
{
    using struct_type = VkDebugMarkerMarkerInfoEXT;

    VkDebugMarkerMarkerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMarkerName;
    PointerDecoder<float> color;
};

struct Decoded_VkDedicatedAllocationImageCreateInfoNV
{
    using struct_type = VkDedicatedAllocationImageCreateInfoNV;

    VkDedicatedAllocationImageCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationBufferCreateInfoNV
{
    using struct_type = VkDedicatedAllocationBufferCreateInfoNV;

    VkDedicatedAllocationBufferCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV
{
    using struct_type = VkDedicatedAllocationMemoryAllocateInfoNV;

    VkDedicatedAllocationMemoryAllocateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId image{ 0 };
    format::HandleId buffer{ 0 };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackFeaturesEXT;

    VkPhysicalDeviceTransformFeedbackFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackPropertiesEXT;

    VkPhysicalDeviceTransformFeedbackPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationStateStreamCreateInfoEXT;

    VkPipelineRasterizationStateStreamCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImageViewHandleInfoNVX
{
    using struct_type = VkImageViewHandleInfoNVX;

    VkImageViewHandleInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId imageView{ 0 };
    format::HandleId sampler{ 0 };
};

struct Decoded_VkTextureLODGatherFormatPropertiesAMD
{
    using struct_type = VkTextureLODGatherFormatPropertiesAMD;

    VkTextureLODGatherFormatPropertiesAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkShaderResourceUsageAMD
{
    using struct_type = VkShaderResourceUsageAMD;

    VkShaderResourceUsageAMD* value{ nullptr };
};

struct Decoded_VkShaderStatisticsInfoAMD
{
    using struct_type = VkShaderStatisticsInfoAMD;

    VkShaderStatisticsInfoAMD* value{ nullptr };

    Decoded_VkShaderResourceUsageAMD resourceUsage;
    PointerDecoder<uint32_t> computeWorkGroupSize;
};

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceCornerSampledImageFeaturesNV;

    VkPhysicalDeviceCornerSampledImageFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExternalImageFormatPropertiesNV
{
    using struct_type = VkExternalImageFormatPropertiesNV;

    VkExternalImageFormatPropertiesNV* value{ nullptr };

    Decoded_VkImageFormatProperties imageFormatProperties;
};

struct Decoded_VkExternalMemoryImageCreateInfoNV
{
    using struct_type = VkExternalMemoryImageCreateInfoNV;

    VkExternalMemoryImageCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkExportMemoryAllocateInfoNV
{
    using struct_type = VkExportMemoryAllocateInfoNV;

    VkExportMemoryAllocateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImportMemoryWin32HandleInfoNV
{
    using struct_type = VkImportMemoryWin32HandleInfoNV;

    VkImportMemoryWin32HandleInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t handle{ 0 };
};

struct Decoded_VkExportMemoryWin32HandleInfoNV
{
    using struct_type = VkExportMemoryWin32HandleInfoNV;

    VkExportMemoryWin32HandleInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES> pAttributes;
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoNV;

    VkWin32KeyedMutexAcquireReleaseInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeoutMilliseconds;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

struct Decoded_VkValidationFlagsEXT
{
    using struct_type = VkValidationFlagsEXT;

    VkValidationFlagsEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkValidationCheckEXT> pDisabledValidationChecks;
};

struct Decoded_VkViSurfaceCreateInfoNN
{
    using struct_type = VkViSurfaceCreateInfoNN;

    VkViSurfaceCreateInfoNN* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t window{ 0 };
};

struct Decoded_VkImageViewASTCDecodeModeEXT
{
    using struct_type = VkImageViewASTCDecodeModeEXT;

    VkImageViewASTCDecodeModeEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceASTCDecodeFeaturesEXT;

    VkPhysicalDeviceASTCDecodeFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkConditionalRenderingBeginInfoEXT
{
    using struct_type = VkConditionalRenderingBeginInfoEXT;

    VkConditionalRenderingBeginInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
};

struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceConditionalRenderingFeaturesEXT;

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT
{
    using struct_type = VkCommandBufferInheritanceConditionalRenderingInfoEXT;

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGeneratedCommandsFeaturesNVX
{
    using struct_type = VkDeviceGeneratedCommandsFeaturesNVX;

    VkDeviceGeneratedCommandsFeaturesNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceGeneratedCommandsLimitsNVX
{
    using struct_type = VkDeviceGeneratedCommandsLimitsNVX;

    VkDeviceGeneratedCommandsLimitsNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkIndirectCommandsTokenNVX
{
    using struct_type = VkIndirectCommandsTokenNVX;

    VkIndirectCommandsTokenNVX* value{ nullptr };

    format::HandleId buffer{ 0 };
};

struct Decoded_VkIndirectCommandsLayoutTokenNVX
{
    using struct_type = VkIndirectCommandsLayoutTokenNVX;

    VkIndirectCommandsLayoutTokenNVX* value{ nullptr };
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoNVX
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoNVX;

    VkIndirectCommandsLayoutCreateInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNVX> pTokens;
};

struct Decoded_VkCmdProcessCommandsInfoNVX
{
    using struct_type = VkCmdProcessCommandsInfoNVX;

    VkCmdProcessCommandsInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId objectTable{ 0 };
    format::HandleId indirectCommandsLayout{ 0 };
    StructPointerDecoder<Decoded_VkIndirectCommandsTokenNVX> pIndirectCommandsTokens;
    format::HandleId targetCommandBuffer{ 0 };
    format::HandleId sequencesCountBuffer{ 0 };
    format::HandleId sequencesIndexBuffer{ 0 };
};

struct Decoded_VkCmdReserveSpaceForCommandsInfoNVX
{
    using struct_type = VkCmdReserveSpaceForCommandsInfoNVX;

    VkCmdReserveSpaceForCommandsInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId objectTable{ 0 };
    format::HandleId indirectCommandsLayout{ 0 };
};

struct Decoded_VkObjectTableCreateInfoNVX
{
    using struct_type = VkObjectTableCreateInfoNVX;

    VkObjectTableCreateInfoNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkObjectEntryTypeNVX> pObjectEntryTypes;
    PointerDecoder<uint32_t> pObjectEntryCounts;
    PointerDecoder<VkObjectEntryUsageFlagsNVX> pObjectEntryUsageFlags;
};

struct Decoded_VkObjectTablePipelineEntryNVX
{
    using struct_type = VkObjectTablePipelineEntryNVX;

    VkObjectTablePipelineEntryNVX* value{ nullptr };

    format::HandleId pipeline{ 0 };
};

struct Decoded_VkObjectTableDescriptorSetEntryNVX
{
    using struct_type = VkObjectTableDescriptorSetEntryNVX;

    VkObjectTableDescriptorSetEntryNVX* value{ nullptr };

    format::HandleId pipelineLayout{ 0 };
    format::HandleId descriptorSet{ 0 };
};

struct Decoded_VkObjectTableVertexBufferEntryNVX
{
    using struct_type = VkObjectTableVertexBufferEntryNVX;

    VkObjectTableVertexBufferEntryNVX* value{ nullptr };

    format::HandleId buffer{ 0 };
};

struct Decoded_VkObjectTableIndexBufferEntryNVX
{
    using struct_type = VkObjectTableIndexBufferEntryNVX;

    VkObjectTableIndexBufferEntryNVX* value{ nullptr };

    format::HandleId buffer{ 0 };
};

struct Decoded_VkObjectTablePushConstantEntryNVX
{
    using struct_type = VkObjectTablePushConstantEntryNVX;

    VkObjectTablePushConstantEntryNVX* value{ nullptr };

    format::HandleId pipelineLayout{ 0 };
};

struct Decoded_VkViewportWScalingNV
{
    using struct_type = VkViewportWScalingNV;

    VkViewportWScalingNV* value{ nullptr };
};

struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV
{
    using struct_type = VkPipelineViewportWScalingStateCreateInfoNV;

    VkPipelineViewportWScalingStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewportWScalingNV> pViewportWScalings;
};

struct Decoded_VkSurfaceCapabilities2EXT
{
    using struct_type = VkSurfaceCapabilities2EXT;

    VkSurfaceCapabilities2EXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D currentExtent;
    Decoded_VkExtent2D minImageExtent;
    Decoded_VkExtent2D maxImageExtent;
};

struct Decoded_VkDisplayPowerInfoEXT
{
    using struct_type = VkDisplayPowerInfoEXT;

    VkDisplayPowerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceEventInfoEXT
{
    using struct_type = VkDeviceEventInfoEXT;

    VkDeviceEventInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDisplayEventInfoEXT
{
    using struct_type = VkDisplayEventInfoEXT;

    VkDisplayEventInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSwapchainCounterCreateInfoEXT
{
    using struct_type = VkSwapchainCounterCreateInfoEXT;

    VkSwapchainCounterCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRefreshCycleDurationGOOGLE
{
    using struct_type = VkRefreshCycleDurationGOOGLE;

    VkRefreshCycleDurationGOOGLE* value{ nullptr };
};

struct Decoded_VkPastPresentationTimingGOOGLE
{
    using struct_type = VkPastPresentationTimingGOOGLE;

    VkPastPresentationTimingGOOGLE* value{ nullptr };
};

struct Decoded_VkPresentTimeGOOGLE
{
    using struct_type = VkPresentTimeGOOGLE;

    VkPresentTimeGOOGLE* value{ nullptr };
};

struct Decoded_VkPresentTimesInfoGOOGLE
{
    using struct_type = VkPresentTimesInfoGOOGLE;

    VkPresentTimesInfoGOOGLE* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPresentTimeGOOGLE> pTimes;
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkViewportSwizzleNV
{
    using struct_type = VkViewportSwizzleNV;

    VkViewportSwizzleNV* value{ nullptr };
};

struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV
{
    using struct_type = VkPipelineViewportSwizzleStateCreateInfoNV;

    VkPipelineViewportSwizzleStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkViewportSwizzleNV> pViewportSwizzles;
};

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
    using struct_type = VkPhysicalDeviceDiscardRectanglePropertiesEXT;

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT
{
    using struct_type = VkPipelineDiscardRectangleStateCreateInfoEXT;

    VkPipelineDiscardRectangleStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkRect2D> pDiscardRectangles;
};

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceConservativeRasterizationPropertiesEXT;

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationConservativeStateCreateInfoEXT;

    VkPipelineRasterizationConservativeStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipEnableFeaturesEXT;

    VkPhysicalDeviceDepthClipEnableFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationDepthClipStateCreateInfoEXT;

    VkPipelineRasterizationDepthClipStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkXYColorEXT
{
    using struct_type = VkXYColorEXT;

    VkXYColorEXT* value{ nullptr };
};

struct Decoded_VkHdrMetadataEXT
{
    using struct_type = VkHdrMetadataEXT;

    VkHdrMetadataEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkXYColorEXT displayPrimaryRed;
    Decoded_VkXYColorEXT displayPrimaryGreen;
    Decoded_VkXYColorEXT displayPrimaryBlue;
    Decoded_VkXYColorEXT whitePoint;
};

struct Decoded_VkIOSSurfaceCreateInfoMVK
{
    using struct_type = VkIOSSurfaceCreateInfoMVK;

    VkIOSSurfaceCreateInfoMVK* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView{ 0 };
};

struct Decoded_VkMacOSSurfaceCreateInfoMVK
{
    using struct_type = VkMacOSSurfaceCreateInfoMVK;

    VkMacOSSurfaceCreateInfoMVK* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pView{ 0 };
};

struct Decoded_VkDebugUtilsObjectNameInfoEXT
{
    using struct_type = VkDebugUtilsObjectNameInfoEXT;

    VkDebugUtilsObjectNameInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pObjectName;
};

struct Decoded_VkDebugUtilsObjectTagInfoEXT
{
    using struct_type = VkDebugUtilsObjectTagInfoEXT;

    VkDebugUtilsObjectTagInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugUtilsLabelEXT
{
    using struct_type = VkDebugUtilsLabelEXT;

    VkDebugUtilsLabelEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pLabelName;
    PointerDecoder<float> color;
};

struct Decoded_VkDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = VkDebugUtilsMessengerCallbackDataEXT;

    VkDebugUtilsMessengerCallbackDataEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StringDecoder pMessageIdName;
    StringDecoder pMessage;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pQueueLabels;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT> pCmdBufLabels;
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT> pObjects;
};

struct Decoded_VkDebugUtilsMessengerCreateInfoEXT
{
    using struct_type = VkDebugUtilsMessengerCreateInfoEXT;

    VkDebugUtilsMessengerCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkAndroidHardwareBufferUsageANDROID
{
    using struct_type = VkAndroidHardwareBufferUsageANDROID;

    VkAndroidHardwareBufferUsageANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferPropertiesANDROID;

    VkAndroidHardwareBufferPropertiesANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatPropertiesANDROID;

    VkAndroidHardwareBufferFormatPropertiesANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkComponentMapping samplerYcbcrConversionComponents;
};

struct Decoded_VkImportAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkImportAndroidHardwareBufferInfoANDROID;

    VkImportAndroidHardwareBufferInfoANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t buffer{ 0 };
};

struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkMemoryGetAndroidHardwareBufferInfoANDROID;

    VkMemoryGetAndroidHardwareBufferInfoANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId memory{ 0 };
};

struct Decoded_VkExternalFormatANDROID
{
    using struct_type = VkExternalFormatANDROID;

    VkExternalFormatANDROID* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSamplerReductionModeCreateInfoEXT
{
    using struct_type = VkSamplerReductionModeCreateInfoEXT;

    VkSamplerReductionModeCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

    VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockFeaturesEXT;

    VkPhysicalDeviceInlineUniformBlockFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockPropertiesEXT;

    VkPhysicalDeviceInlineUniformBlockPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkWriteDescriptorSetInlineUniformBlockEXT
{
    using struct_type = VkWriteDescriptorSetInlineUniformBlockEXT;

    VkWriteDescriptorSetInlineUniformBlockEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT
{
    using struct_type = VkDescriptorPoolInlineUniformBlockCreateInfoEXT;

    VkDescriptorPoolInlineUniformBlockCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkSampleLocationEXT
{
    using struct_type = VkSampleLocationEXT;

    VkSampleLocationEXT* value{ nullptr };
};

struct Decoded_VkSampleLocationsInfoEXT
{
    using struct_type = VkSampleLocationsInfoEXT;

    VkSampleLocationsInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D sampleLocationGridSize;
    StructPointerDecoder<Decoded_VkSampleLocationEXT> pSampleLocations;
};

struct Decoded_VkAttachmentSampleLocationsEXT
{
    using struct_type = VkAttachmentSampleLocationsEXT;

    VkAttachmentSampleLocationsEXT* value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkSubpassSampleLocationsEXT
{
    using struct_type = VkSubpassSampleLocationsEXT;

    VkSubpassSampleLocationsEXT* value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT
{
    using struct_type = VkRenderPassSampleLocationsBeginInfoEXT;

    VkRenderPassSampleLocationsBeginInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT> pAttachmentInitialSampleLocations;
    StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT> pPostSubpassSampleLocations;
};

struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT
{
    using struct_type = VkPipelineSampleLocationsStateCreateInfoEXT;

    VkPipelineSampleLocationsStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkSampleLocationsInfoEXT sampleLocationsInfo;
};

struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSampleLocationsPropertiesEXT;

    VkPhysicalDeviceSampleLocationsPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D maxSampleLocationGridSize;
    PointerDecoder<float> sampleLocationCoordinateRange;
};

struct Decoded_VkMultisamplePropertiesEXT
{
    using struct_type = VkMultisamplePropertiesEXT;

    VkMultisamplePropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D maxSampleLocationGridSize;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
    using struct_type = VkPipelineColorBlendAdvancedStateCreateInfoEXT;

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageToColorStateCreateInfoNV;

    VkPipelineCoverageToColorStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageModulationStateCreateInfoNV;

    VkPipelineCoverageModulationStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<float> pCoverageModulationTable;
};

struct Decoded_VkDrmFormatModifierPropertiesEXT
{
    using struct_type = VkDrmFormatModifierPropertiesEXT;

    VkDrmFormatModifierPropertiesEXT* value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesListEXT
{
    using struct_type = VkDrmFormatModifierPropertiesListEXT;

    VkDrmFormatModifierPropertiesListEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkDrmFormatModifierPropertiesEXT> pDrmFormatModifierProperties;
};

struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT
{
    using struct_type = VkPhysicalDeviceImageDrmFormatModifierInfoEXT;

    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierListCreateInfoEXT;

    VkImageDrmFormatModifierListCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint64_t> pDrmFormatModifiers;
};

struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierExplicitCreateInfoEXT;

    VkImageDrmFormatModifierExplicitCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkSubresourceLayout> pPlaneLayouts;
};

struct Decoded_VkImageDrmFormatModifierPropertiesEXT
{
    using struct_type = VkImageDrmFormatModifierPropertiesEXT;

    VkImageDrmFormatModifierPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkValidationCacheCreateInfoEXT
{
    using struct_type = VkValidationCacheCreateInfoEXT;

    VkValidationCacheCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT
{
    using struct_type = VkShaderModuleValidationCacheCreateInfoEXT;

    VkShaderModuleValidationCacheCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId validationCache{ 0 };
};

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT
{
    using struct_type = VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;

    VkDescriptorSetLayoutBindingFlagsCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDescriptorBindingFlagsEXT> pBindingFlags;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingFeaturesEXT;

    VkPhysicalDeviceDescriptorIndexingFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingPropertiesEXT;

    VkPhysicalDeviceDescriptorIndexingPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT
{
    using struct_type = VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;

    VkDescriptorSetVariableDescriptorCountAllocateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> pDescriptorCounts;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT
{
    using struct_type = VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

    VkDescriptorSetVariableDescriptorCountLayoutSupportEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkShadingRatePaletteNV
{
    using struct_type = VkShadingRatePaletteNV;

    VkShadingRatePaletteNV* value{ nullptr };

    PointerDecoder<VkShadingRatePaletteEntryNV> pShadingRatePaletteEntries;
};

struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV
{
    using struct_type = VkPipelineViewportShadingRateImageStateCreateInfoNV;

    VkPipelineViewportShadingRateImageStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV> pShadingRatePalettes;
};

struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImageFeaturesNV;

    VkPhysicalDeviceShadingRateImageFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImagePropertiesNV;

    VkPhysicalDeviceShadingRateImagePropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D shadingRateTexelSize;
};

struct Decoded_VkCoarseSampleLocationNV
{
    using struct_type = VkCoarseSampleLocationNV;

    VkCoarseSampleLocationNV* value{ nullptr };
};

struct Decoded_VkCoarseSampleOrderCustomNV
{
    using struct_type = VkCoarseSampleOrderCustomNV;

    VkCoarseSampleOrderCustomNV* value{ nullptr };

    StructPointerDecoder<Decoded_VkCoarseSampleLocationNV> pSampleLocations;
};

struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV
{
    using struct_type = VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV> pCustomSampleOrders;
};

struct Decoded_VkRayTracingShaderGroupCreateInfoNV
{
    using struct_type = VkRayTracingShaderGroupCreateInfoNV;

    VkRayTracingShaderGroupCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkRayTracingPipelineCreateInfoNV
{
    using struct_type = VkRayTracingPipelineCreateInfoNV;

    VkRayTracingPipelineCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo> pStages;
    StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoNV> pGroups;
    format::HandleId layout{ 0 };
    format::HandleId basePipelineHandle{ 0 };
};

struct Decoded_VkGeometryTrianglesNV
{
    using struct_type = VkGeometryTrianglesNV;

    VkGeometryTrianglesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId vertexData{ 0 };
    format::HandleId indexData{ 0 };
    format::HandleId transformData{ 0 };
};

struct Decoded_VkGeometryAABBNV
{
    using struct_type = VkGeometryAABBNV;

    VkGeometryAABBNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId aabbData{ 0 };
};

struct Decoded_VkGeometryDataNV
{
    using struct_type = VkGeometryDataNV;

    VkGeometryDataNV* value{ nullptr };

    Decoded_VkGeometryTrianglesNV triangles;
    Decoded_VkGeometryAABBNV aabbs;
};

struct Decoded_VkGeometryNV
{
    using struct_type = VkGeometryNV;

    VkGeometryNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkGeometryDataNV geometry;
};

struct Decoded_VkAccelerationStructureInfoNV
{
    using struct_type = VkAccelerationStructureInfoNV;

    VkAccelerationStructureInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkGeometryNV> pGeometries;
};

struct Decoded_VkAccelerationStructureCreateInfoNV
{
    using struct_type = VkAccelerationStructureCreateInfoNV;

    VkAccelerationStructureCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkAccelerationStructureInfoNV info;
};

struct Decoded_VkBindAccelerationStructureMemoryInfoNV
{
    using struct_type = VkBindAccelerationStructureMemoryInfoNV;

    VkBindAccelerationStructureMemoryInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ 0 };
    format::HandleId memory{ 0 };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureNV
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureNV;

    VkWriteDescriptorSetAccelerationStructureNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
};

struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV
{
    using struct_type = VkAccelerationStructureMemoryRequirementsInfoNV;

    VkAccelerationStructureMemoryRequirementsInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId accelerationStructure{ 0 };
};

struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingPropertiesNV;

    VkPhysicalDeviceRayTracingPropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV
{
    using struct_type = VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;

    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV
{
    using struct_type = VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT
{
    using struct_type = VkPhysicalDeviceImageViewImageFormatInfoEXT;

    VkPhysicalDeviceImageViewImageFormatInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT
{
    using struct_type = VkFilterCubicImageViewImageFormatPropertiesEXT;

    VkFilterCubicImageViewImageFormatPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT
{
    using struct_type = VkDeviceQueueGlobalPriorityCreateInfoEXT;

    VkDeviceQueueGlobalPriorityCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImportMemoryHostPointerInfoEXT
{
    using struct_type = VkImportMemoryHostPointerInfoEXT;

    VkImportMemoryHostPointerInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pHostPointer{ 0 };
};

struct Decoded_VkMemoryHostPointerPropertiesEXT
{
    using struct_type = VkMemoryHostPointerPropertiesEXT;

    VkMemoryHostPointerPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
    using struct_type = VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCalibratedTimestampInfoEXT
{
    using struct_type = VkCalibratedTimestampInfoEXT;

    VkCalibratedTimestampInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesAMD;

    VkPhysicalDeviceShaderCorePropertiesAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD
{
    using struct_type = VkDeviceMemoryOverallocationCreateInfoAMD;

    VkDeviceMemoryOverallocationCreateInfoAMD* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkVertexInputBindingDivisorDescriptionEXT
{
    using struct_type = VkVertexInputBindingDivisorDescriptionEXT;

    VkVertexInputBindingDivisorDescriptionEXT* value{ nullptr };
};

struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT
{
    using struct_type = VkPipelineVertexInputDivisorStateCreateInfoEXT;

    VkPipelineVertexInputDivisorStateCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescriptionEXT> pVertexBindingDivisors;
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;

    VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV
{
    using struct_type = VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesNV;

    VkPhysicalDeviceMeshShaderFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesNV;

    VkPhysicalDeviceMeshShaderPropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<uint32_t> maxTaskWorkGroupSize;
    PointerDecoder<uint32_t> maxMeshWorkGroupSize;
};

struct Decoded_VkDrawMeshTasksIndirectCommandNV
{
    using struct_type = VkDrawMeshTasksIndirectCommandNV;

    VkDrawMeshTasksIndirectCommandNV* value{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;

    VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderImageFootprintFeaturesNV;

    VkPhysicalDeviceShaderImageFootprintFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV
{
    using struct_type = VkPipelineViewportExclusiveScissorStateCreateInfoNV;

    VkPipelineViewportExclusiveScissorStateCreateInfoNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    StructPointerDecoder<Decoded_VkRect2D> pExclusiveScissors;
};

struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceExclusiveScissorFeaturesNV;

    VkPhysicalDeviceExclusiveScissorFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkQueueFamilyCheckpointPropertiesNV
{
    using struct_type = VkQueueFamilyCheckpointPropertiesNV;

    VkQueueFamilyCheckpointPropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkCheckpointDataNV
{
    using struct_type = VkCheckpointDataNV;

    VkCheckpointDataNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pCheckpointMarker{ 0 };
};

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT
{
    using struct_type = VkPhysicalDevicePCIBusInfoPropertiesEXT;

    VkPhysicalDevicePCIBusInfoPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA
{
    using struct_type = VkImagePipeSurfaceCreateInfoFUCHSIA;

    VkImagePipeSurfaceCreateInfoFUCHSIA* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMetalSurfaceCreateInfoEXT
{
    using struct_type = VkMetalSurfaceCreateInfoEXT;

    VkMetalSurfaceCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    uint64_t pLayer{ 0 };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapFeaturesEXT;

    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapPropertiesEXT;

    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkExtent2D minFragmentDensityTexelSize;
    Decoded_VkExtent2D maxFragmentDensityTexelSize;
};

struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT
{
    using struct_type = VkRenderPassFragmentDensityMapCreateInfoEXT;

    VkRenderPassFragmentDensityMapCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    Decoded_VkAttachmentReference fragmentDensityMapAttachment;
};

struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT
{
    using struct_type = VkPhysicalDeviceScalarBlockLayoutFeaturesEXT;

    VkPhysicalDeviceScalarBlockLayoutFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMemoryBudgetPropertiesEXT;

    VkPhysicalDeviceMemoryBudgetPropertiesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkDeviceSize> heapBudget;
    PointerDecoder<VkDeviceSize> heapUsage;
};

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMemoryPriorityFeaturesEXT;

    VkPhysicalDeviceMemoryPriorityFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkMemoryPriorityAllocateInfoEXT
{
    using struct_type = VkMemoryPriorityAllocateInfoEXT;

    VkMemoryPriorityAllocateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV
{
    using struct_type = VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBufferAddressFeaturesEXT;

    VkPhysicalDeviceBufferAddressFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkBufferDeviceAddressInfoEXT
{
    using struct_type = VkBufferDeviceAddressInfoEXT;

    VkBufferDeviceAddressInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    format::HandleId buffer{ 0 };
};

struct Decoded_VkBufferDeviceAddressCreateInfoEXT
{
    using struct_type = VkBufferDeviceAddressCreateInfoEXT;

    VkBufferDeviceAddressCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkImageStencilUsageCreateInfoEXT
{
    using struct_type = VkImageStencilUsageCreateInfoEXT;

    VkImageStencilUsageCreateInfoEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkValidationFeaturesEXT
{
    using struct_type = VkValidationFeaturesEXT;

    VkValidationFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
    PointerDecoder<VkValidationFeatureEnableEXT> pEnabledValidationFeatures;
    PointerDecoder<VkValidationFeatureDisableEXT> pDisabledValidationFeatures;
};

struct Decoded_VkCooperativeMatrixPropertiesNV
{
    using struct_type = VkCooperativeMatrixPropertiesNV;

    VkCooperativeMatrixPropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesNV;

    VkPhysicalDeviceCooperativeMatrixFeaturesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesNV;

    VkPhysicalDeviceCooperativeMatrixPropertiesNV* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* value{ nullptr };

    std::unique_ptr<PNextNode> pNext;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
