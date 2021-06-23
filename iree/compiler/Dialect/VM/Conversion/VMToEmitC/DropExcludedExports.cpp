// Copyright 2021 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "iree/compiler/Dialect/VM/Conversion/VMToEmitC/DropExcludedExports.h"

#include "mlir/Pass/Pass.h"

namespace mlir {
namespace iree_compiler {
namespace IREE {
namespace VM {

class DropExcludedExportsPass
    : public PassWrapper<DropExcludedExportsPass,
                         OperationPass<IREE::VM::ModuleOp>> {
 public:
  void runOnOperation() override {
    // Remove exports annotated with emitc.exclude.
    SmallVector<Operation *, 4> opsToRemove;
    getOperation()->walk([&](IREE::VM::ExportOp exportOp) {
      Operation *op = exportOp.getOperation();
      if (op->hasAttr("emitc.exclude")) {
        exportOp.emitRemark("Dropping excluded export");
        opsToRemove.push_back(op);
      }
    });

    for (auto op : opsToRemove) {
      op->erase();
    }
  }
};

std::unique_ptr<OperationPass<IREE::VM::ModuleOp>>
createDropExcludedExportsPass() {
  return std::make_unique<DropExcludedExportsPass>();
}

static PassRegistration<DropExcludedExportsPass> pass(
    "iree-vm-drop-excluded-exports",
    "Deletes exports if annotated with emitc.exclude.");

}  // namespace VM
}  // namespace IREE
}  // namespace iree_compiler
}  // namespace mlir