/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once
#include "lite/backends/metal/metal_common.h"

namespace paddle {
namespace lite {

metal_half MetalFloat2Half(float f);

float MetalHalf2Float(metal_half h);

void MetalFloatArray2HalfArray(float *f_array, metal_half *h_array, int count);

void MetalHalfArray2FloatArray(metal_half *h_array, float *f_array, int count);

}  // namespace lite
}  // namespace paddle