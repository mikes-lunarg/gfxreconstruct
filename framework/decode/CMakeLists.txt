add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                   api_decoder.h
                   custom_vulkan_struct_decoders.h
                   custom_vulkan_struct_decoders.cpp
                   custom_vulkan_struct_decoders_forward.h
                   compression_converter.h
                   compression_converter.cpp
                   descriptor_update_template_decoder.h
                   descriptor_update_template_decoder.cpp
                   file_processor.h
                   file_processor.cpp
                   handle_pointer_decoder.h
                   pnext_node.h
                   pnext_typed_node.h
                   pointer_decoder_base.h
                   pointer_decoder.h
                   string_array_decoder.h
                   string_decoder.h
                   struct_pointer_decoder.h
                   struct_pointer_decoder_nvx.h
                   value_decoder.h
                   vulkan_ascii_consumer_base.h
                   vulkan_ascii_consumer_base.cpp
                   vulkan_consumer_base.h
                   vulkan_decoder_base.h
                   vulkan_decoder_base.cpp
                   vulkan_enum_util.h
                   vulkan_object_mapper.h
                   vulkan_replay_consumer_base.h
                   vulkan_replay_consumer_base.cpp
                   vulkan_replay_options.h
                   window.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
              )

target_include_directories(gfxrecon_decode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_decode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)
