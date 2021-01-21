// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef LITE_KERNELS_METAL_IMAGE_OP_MUL_IMAGE_COMPUTE_H_
#define LITE_KERNELS_METAL_IMAGE_OP_MUL_IMAGE_COMPUTE_H_

#include <memory>

#include "lite/core/kernel.h"
#include "lite/core/tensor.h"
#include "lite/kernels/metal/image_op/reshape_image_compute.h"
#include "lite/operators/op_params.h"

#ifdef LITE_WITH_PROFILE
#include "lite/core/profile/profiler.h"
#endif

#include "lite/backends/metal/metal_context.h"
#include "lite/core/dim.h"

namespace paddle {
namespace lite {
namespace kernels {
namespace metal {

class mul_image_compute : public KernelLite<TARGET(kMetal),
                                            PRECISION(kFloat),
                                            DATALAYOUT(kMetalTexture2DArray)> {
  using param_t = operators::MulParam;
  using param_reshape_t = operators::ReshapeParam;

 public:
  void PrepareForRun() override;
  void Run() override;

 private:
  const metal_image* input_buffer_x_;
  const metal_image* input_buffer_y_;

  metal_image* output_buffer_;

  std::shared_ptr<metal_buffer> params_buffer_;

  std::shared_ptr<metal_kernel> kernel_;
  DDim inputXMulDim;

  reshape_image_compute reshape_;
  Tensor shape_out_dev;
  bool insert_shape = false;
};

class mul_image_compute_half
    : public KernelLite<TARGET(kMetal),
                        PRECISION(kFP16),
                        DATALAYOUT(kMetalTexture2DArray)> {
  using param_t = operators::MulParam;
  using param_reshape_t = operators::ReshapeParam;

 public:
  void PrepareForRun() override;
  void Run() override;

 private:
  const metal_image* input_buffer_x_;
  const metal_image* input_buffer_y_;

  metal_image* output_buffer_;
  std::shared_ptr<metal_buffer> params_buffer_;
  std::shared_ptr<metal_kernel> kernel_;

  DDim inputXMulDim;
  reshape_image_compute_half reshape_;
  Tensor shape_out_dev;
  bool insert_shape = false;
};

}  // namespace metal
}  // namespace kernels
}  // namespace lite
}  // namespace paddle

#endif  // LITE_KERNELS_METAL_IMAGE_OP_MUL_IMAGE_COMPUTE_H_