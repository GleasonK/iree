// Copyright 2022 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_TRANSFORMS_PASS_DETAIL_H_
#define IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_TRANSFORMS_PASS_DETAIL_H_

#include "iree/compiler/Dialect/Modules/HAL/Loader/IR/HALLoaderOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/Pass.h"

namespace mlir {
namespace iree_compiler {
namespace IREE {
namespace HAL {
namespace Loader {

#define GEN_PASS_CLASSES
#include "iree/compiler/Dialect/Modules/HAL/Loader/Transforms/Passes.h.inc"

}  // namespace Loader
}  // namespace HAL
}  // namespace IREE
}  // namespace iree_compiler
}  // namespace mlir

#endif  // IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_TRANSFORMS_PASS_DETAIL_H_
