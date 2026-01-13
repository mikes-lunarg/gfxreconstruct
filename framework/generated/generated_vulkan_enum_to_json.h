/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_ENUM_TO_JSON_H
#define  GFXRECON_GENERATED_VULKAN_ENUM_TO_JSON_H

#include "format/platform_types.h"
#include "util/json_util.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)


void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ChromaSamplePosition& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ColorPrimaries& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1FrameRestorationType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1FrameType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1InterpolationFilter& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1Level& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1MatrixCoefficients& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1Profile& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ReferenceName& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1TransferCharacteristics& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1TxMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoDecodeH264FieldOrderCount& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264AspectRatioIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264CabacInitIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ChromaFormatIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264DisableDeblockingFilterIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264LevelIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264MemMgmtControlOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ModificationOfPicNumsIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264NonVclNaluType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PictureType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PocType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ProfileIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264SliceType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264WeightedBipredIdc& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9ColorSpace& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9FrameType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9InterpolationFilter& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9Level& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9Profile& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoVP9ReferenceName& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureBuildTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureCompatibilityKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMemoryRequirementsTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInstanceTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAntiLagModeAMD& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAntiLagStageAMD& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentLoadOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentStoreOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendFactor& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOverlapEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBlockMatchWindowCompareModeQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBorderColor& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureModeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildMicromapModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkChromaLocation& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCoarseSampleOrderTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkColorSpaceKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferLevel& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCompareOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentSwizzle& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkConservativeRasterizationModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCooperativeVectorMatrixLayoutNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyAccelerationStructureModeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyMicromapModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageModulationModeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageReductionModeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkCubicFilterWeightsQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDataGraphModelCacheTypeQCOM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDataGraphPipelinePropertyARM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionBindPointARM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDataGraphPipelineSessionBindPointTypeARM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugReportObjectTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDefaultVertexAttributeValueKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDepthBiasRepresentationEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDepthClampModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorUpdateTemplateType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceEventTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultAddressTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultVendorBinaryHeaderVersionEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceMemoryReportEventTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDirectDriverLoadingModeLUNARG& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDiscardRectangleModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplacementMicromapFormatNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayEventTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayPowerStateEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplaySurfaceStereoTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDriverId& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkDynamicState& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFilter& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFormat& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateCombinerOpKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFrontFace& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkFullScreenExclusiveEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkImageLayout& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkImageTiling& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkImageType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkImageViewType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkIndexType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectExecutionSetInfoTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkInternalAllocationType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkLatencyMarkerNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkLayerSettingTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkLayeredDriverUnderlyingApiMSFT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkLineRasterizationMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkLogicOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryOverallocationBehaviorAMD& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkMicromapTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkObjectType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapFormatEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapSpecialIndexEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowPerformanceLevelNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionBindingPointNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkOutOfBandQueueTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPartitionedAccelerationStructureOpTypeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceConfigurationTypeINTEL& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterScopeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterStorageKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterUnitKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceOverrideTypeINTEL& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceParameterTypeINTEL& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceValueTypeINTEL& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceDataGraphOperationTypeARM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceDataGraphProcessingEngineTypeARM& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceLayeredApiKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineBindPoint& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCacheHeaderVersion& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineExecutableStatisticFormatKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessBufferBehavior& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessImageBehavior& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPointClippingBehavior& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPolygonMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentModeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkPrimitiveTopology& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkProvokingVertexModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryPoolSamplingModeINTEL& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryResultStatusKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkQueueGlobalPriority& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkRasterizationOrderAMD& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingInvocationReorderModeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingLssIndexingModeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingLssPrimitiveEndCapsModeNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingShaderGroupTypeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkResult& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerAddressMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerMipmapMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerReductionMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrModelConversion& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrRange& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkScopeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCodeTypeEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderFloatControlsIndependence& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderGroupShaderKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderInfoTypeAMD& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkShadingRatePaletteEntryNV& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSharingMode& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkStencilOp& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkStructureType& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassContents& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassMergeStatusEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkSystemAllocationScope& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkTessellationDomainOrigin& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkTimeDomainKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCacheHeaderVersionEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCheckEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureDisableEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureEnableEXT& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkVendorId& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkVertexInputRate& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1PredictionModeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeAV1RateControlGroupKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeTuningModeKHR& value, const util::JsonOptions& options = util::JsonOptions());
void FieldToJson(nlohmann::ordered_json& jdata, const VkViewportCoordinateSwizzleNV& value, const util::JsonOptions& options = util::JsonOptions());
void VkAccelerationStructureCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAccelerationStructureMotionInfoFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAccelerationStructureMotionInstanceFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAccessFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAccessFlags2ToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkAccessFlags3KHRToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkAcquireProfilingLockFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAddressCopyFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAndroidSurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkAttachmentDescriptionFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkBufferCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkBufferUsageFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkBufferUsageFlags2ToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkBufferViewCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkBuildAccelerationStructureFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkBuildMicromapFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkColorComponentFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCommandBufferResetFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCommandBufferUsageFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCommandPoolCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCommandPoolResetFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCommandPoolTrimFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCompositeAlphaFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkConditionalRenderingFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkCullModeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDataGraphPipelineDispatchFlagsARMToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkDataGraphPipelineSessionCreateFlagsARMToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkDebugReportFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDebugUtilsMessageSeverityFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDebugUtilsMessageTypeFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDebugUtilsMessengerCallbackDataFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDebugUtilsMessengerCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDependencyFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDescriptorBindingFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDescriptorPoolCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDescriptorPoolResetFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDescriptorSetLayoutCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDescriptorUpdateTemplateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceAddressBindingFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceDiagnosticsConfigFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceGroupPresentModeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceMemoryReportFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDeviceQueueCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDirectDriverLoadingFlagsLUNARGToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDirectFBSurfaceCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDisplayModeCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDisplayPlaneAlphaFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkDisplaySurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkEventCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalFenceFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalFenceHandleTypeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalMemoryFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalMemoryFeatureFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalMemoryHandleTypeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalMemoryHandleTypeFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalSemaphoreFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkExternalSemaphoreHandleTypeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkFenceCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkFenceImportFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkFormatFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkFormatFeatureFlags2ToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkFrameBoundaryFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkFramebufferCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkGeometryFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkGeometryInstanceFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkGraphicsPipelineLibraryFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkHeadlessSurfaceCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkHostImageCopyFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkIOSSurfaceCreateFlagsMVKToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageAspectFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageCompressionFixedRateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageCompressionFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImagePipeSurfaceCreateFlagsFUCHSIAToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageUsageFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkImageViewCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkIndirectCommandsInputModeFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkIndirectCommandsLayoutUsageFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkIndirectCommandsLayoutUsageFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkIndirectStateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkInstanceCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMacOSSurfaceCreateFlagsMVKToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryAllocateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryDecompressionMethodFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryHeapFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryMapFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryPropertyFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMemoryUnmapFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMetalSurfaceCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkMicromapCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkOpticalFlowExecuteFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkOpticalFlowGridSizeFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkOpticalFlowSessionCreateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkOpticalFlowUsageFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPartitionedAccelerationStructureInstanceFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPastPresentationTimingFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPeerMemoryFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPerformanceCounterDescriptionFlagsARMToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPerformanceCounterDescriptionFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPhysicalDeviceSchedulingControlsFlagsARMToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCacheCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineColorBlendStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCompilerControlFlagsAMDToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCoverageModulationStateCreateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCoverageReductionStateCreateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCoverageToColorStateCreateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCreateFlags2ToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineCreationFeedbackFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineDepthStencilStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineDiscardRectangleStateCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineDynamicStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineInputAssemblyStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineLayoutCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineMultisampleStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineRasterizationConservativeStateCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineRasterizationDepthClipStateCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineRasterizationStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineRasterizationStateStreamCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineShaderStageCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineStageFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineStageFlags2ToJson(nlohmann::ordered_json& jdata, const VkFlags64 flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineTessellationStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineVertexInputStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineViewportStateCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPipelineViewportSwizzleStateCreateFlagsNVToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPresentGravityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPresentScalingFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPresentStageFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPresentTimingInfoFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkPrivateDataSlotCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkQueryControlFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkQueryPipelineStatisticFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkQueryPoolCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkQueryResultFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkQueueFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkRenderPassCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkRenderingAttachmentFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkRenderingFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkResolveImageFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkResolveModeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSampleCountFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSamplerCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkScreenSurfaceCreateFlagsQNXToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSemaphoreCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSemaphoreImportFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSemaphoreWaitFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkShaderCorePropertiesFlagsAMDToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkShaderCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkShaderModuleCreateFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkShaderStageFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSparseImageFormatFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSparseMemoryBindFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkStencilFaceFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkStreamDescriptorSurfaceCreateFlagsGGPToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSubgroupFeatureFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSubmitFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSubpassDescriptionFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSurfaceCounterFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSurfaceTransformFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkSwapchainCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkTileShadingRenderPassFlagsQCOMToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkToolPurposeFlagsToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkValidationCacheCreateFlagsEXTToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkViSurfaceCreateFlagsNNToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoBeginCodingFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoCapabilityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoChromaSubsamplingFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoCodecOperationFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoCodingControlFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoComponentBitDepthFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoDecodeCapabilityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoDecodeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoDecodeH264PictureLayoutFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoDecodeUsageFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeAV1CapabilityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeAV1RateControlFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeAV1StdFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeAV1SuperblockSizeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeCapabilityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeContentFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeFeedbackFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeH264CapabilityFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeH264RateControlFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeH264StdFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeH265CtbSizeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeIntraRefreshModeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeRateControlFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeRateControlModeFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeRgbChromaOffsetFlagsVALVEToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeRgbModelConversionFlagsVALVEToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeRgbRangeCompressionFlagsVALVEToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEncodeUsageFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoEndCodingFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoSessionCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkVideoSessionParametersCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkWaylandSurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkWin32SurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkXcbSurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());
void VkXlibSurfaceCreateFlagsKHRToJson(nlohmann::ordered_json& jdata, const VkFlags flags, const util::JsonOptions& options = util::JsonOptions());

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_ENUM_TO_JSON_H
