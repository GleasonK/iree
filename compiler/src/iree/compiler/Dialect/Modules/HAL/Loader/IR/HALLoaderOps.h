// Copyright 2022 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_IR_HALLOADEROPS_H_
#define IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_IR_HALLOADEROPS_H_

#include <cstdint>

#include "iree/compiler/Dialect/HAL/IR/HALTypes.h"
#include "iree/compiler/Dialect/Util/IR/UtilTraits.h"
#include "mlir/IR/Attributes.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#define GET_OP_CLASSES
#include "iree/compiler/Dialect/Modules/HAL/Loader/IR/HALLoaderOps.h.inc"  // IWYU pragma: keep

#endif  // IREE_COMPILER_DIALECT_MODULES_HAL_LOADER_IR_HALLOADEROPS_H_
