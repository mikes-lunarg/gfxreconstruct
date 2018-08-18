#!/usr/bin/python3 -i
#
# Copyright (c) 2018 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os,re,sys
from base_generator import *

class ApiCallEncodersGeneratorOptions(BaseGeneratorOptions):
    """Options for Vulkan API parameter encoding C++ code generation"""
    def __init__(self,
                 blacklists = None,         # Path to JSON file listing apicalls and structs to ignore.
                 platformTypes = None,      # Path to JSON file listing platform (WIN32, X11, etc.) defined types.
                 filename = None,
                 directory = '.',
                 prefixText = '',
                 protectFile = False,
                 protectFeature = True):
        BaseGeneratorOptions.__init__(self, blacklists, platformTypes,
                                      filename, directory, prefixText,
                                      protectFile, protectFeature)

# APICallEncodersGenerator - subclass of BaseGenerator.
# Generates C++ functions responsible for encoding Vulkan API call parameter data.
class ApiCallEncodersGenerator(BaseGenerator):
    """Generate API parameter encoding C++ code"""
    def __init__(self,
                 errFile = sys.stderr,
                 warnFile = sys.stderr,
                 diagFile = sys.stdout):
        BaseGenerator.__init__(self, errFile, warnFile, diagFile)

    # Method override
    def beginFile(self, genOpts):
        BaseGenerator.beginFile(self, genOpts)

        write('#include "vulkan/vulkan.h"', file=self.outFile)
        self.newline()
        write('#include "util/defines.h"', file=self.outFile)
        write('#include "format/api_call_id.h"', file=self.outFile)
        write('#include "format/trace_manager.h"', file=self.outFile)
        write('#include "format/parameter_encoder.h"', file=self.outFile)
        self.newline()
        write('BRIMSTONE_BEGIN_NAMESPACE(brimstone)', file=self.outFile)

    # Method override
    def endFile(self):
        self.newline()
        write('BRIMSTONE_END_NAMESPACE(brimstone)', file=self.outFile)

        # Finish processing in superclass
        BaseGenerator.endFile(self)

    #
    # Indicates that the current feature has C++ code to generate.
    def needFeatureGeneration(self):
        if self.featureCmdParams:
            return True
        return False

    #
    # Performs C++ code generation for the feature.
    def generateFeature(self):
        first = True
        for cmd in self.featureCmdParams:
            info = self.featureCmdParams[cmd]
            returnType = info[0]
            proto = info[1]
            values = info[2]

            cmddef = '' if first else '\n'
            cmddef += self.makeCmdDecl(proto, values)
            cmddef += '{\n'
            cmddef += self.makeCmdBody(returnType, cmd, values)
            cmddef += '}'

            write(cmddef, file=self.outFile)
            first = False

    #
    # Generate function declaration for a command
    def makeCmdDecl(self, proto, values):
        paramDecls = []

        for value in values:
            valueName = value.name
            valueType = value.fullType if not value.platformFullType else value.platformFullType

            if value.isArray and not value.isDynamic:
                valueName += '[{}]'.format(value.arrayCapacity)

            paramDecl = self.makeAlignedParamDecl(valueType, valueName, self.INDENT_SIZE, self.genOpts.alignFuncParam)
            paramDecls.append(paramDecl)

        if paramDecls:
            return '{}(\n{})\n'.format(proto, ',\n'.join(paramDecls))

        return '{}()\n'.format(proto)

    #
    # Check for dispatchable handle types associated with the instance dispatch table.
    def useInstanceTable(self, typename):
        if typename in ['VkInstance', 'VkPhysicalDevice']:
            return True
        return False

    #
    # Generate the layer dispatch call invocation.
    def makeLayerDispatchCall(self, name, values):
        argList =  self.makeArgList(values)

        if name == 'vkCreateInstance':
            # CreateInstance requires special processing for VkLayerInstanceCreateInfo.
            return 'dispatch_CreateInstance({})'.format(argList)
        elif name == 'vkCreateDevice':
            # CreateDevice requires special processing for VkLayerDeviceCreateInfo.
            return 'dispatch_CreateDevice({})'.format(argList)

        dispatchfunc = 'get_instance_table' if self.useInstanceTable(values[0].baseType) else 'get_device_table'
        return '{}({})->{}({})'.format(dispatchfunc, values[0].name, name[2:], argList)

    #
    # Generate the parameter encoder method call invocation
    def makeEncoderMethodCall(self, value, values):
        args = [value.name]

        isStruct = False
        isString = False

        typeName = self.makeInvocationTypeName(value.baseType)

        if self.isStruct(typeName):
            methodCall = 'encode_struct'
            args = ['encoder'] + args
            isStruct = True
        else:
            methodCall = 'encoder->Encode' + typeName
            if typeName == 'String':
                isString = True
            elif typeName == 'HandleId':
                # TODO: Address Handle/HandleId inconsistency between decode and encode
                typeName = 'Handle'

        methodCall = 'encode_struct' if self.isStruct(value.baseType) else 'encoder->Encode' + typeName

        if value.isArray:
            if isStruct:
                methodCall += '_array'
            else:
                methodCall += 'Array'

            # Find the array length value in the list.
            lengthValue = next((v for v in values if v.name == value.arrayLength), None)

            if lengthValue and lengthValue.isPointer:
                args.append('({name} != nullptr) ? (*{name}) : 0'.format(name=lengthValue.name))
            else:
                args.append(value.arrayLength)
        elif isStruct:
            methodCall += '_ptr'
        elif not isString:
            # String function names do not have the Ptr/Value suffix
            if value.isPointer:
                methodCall += 'Ptr' * value.pointerCount
            else:
                methodCall += 'Value'

        return '{}({})'.format(methodCall, ', '.join(args))

    #
    # Command definition
    def makeCmdBody(self, returnType, name, values):
        body = ''

        # Get parameters and construct the function call to dispatch to the next layer.
        callExpr = self.makeLayerDispatchCall(name, values)

        if returnType and returnType != 'void':
            body += '    {} result = {};\n'.format(returnType, callExpr)
        else:
            body += '    {};\n'.format(callExpr)

        body += '\n'
        body += '    auto encoder = get_trace_manager()->BeginApiCallTrace(format::ApiCallId_{});\n'.format(name)
        body += '    if (encoder)\n'
        body += '    {\n'

        for value in values:
            methodCall = self.makeEncoderMethodCall(value, values)
            body += '        {};\n'.format(methodCall)

        if returnType and returnType != 'void':
            body += '        encoder->EncodeEnumValue(result);\n'

        body += '        get_trace_manager()->EndApiCallTrace(encoder);\n'
        body += '    }\n'

        if returnType and returnType != 'void':
            body += '\n'
            body += '    return result;\n'

        return body


