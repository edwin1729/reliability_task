#include <algorithm>

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;

namespace {
int countF = 0;
struct Info : public FunctionPass {
  static char ID;
  Info() : FunctionPass(ID) {}

  bool doInitialization(Module& mod) override {
    errs() << "Total number of functions: " << mod.size() << '\n';
    return false;
  }

  bool runOnFunction(Function& func) override {
    ++countF;
    int count = 0;
    for (const auto& x : func) {
      ++count;
    }
    errs() << "Foo: ";
    errs().write_escaped(func.getName()) << '\n';
    errs() << "Basic Blocks: " << func.size() << '\n';
    errs() << "Basic Blocks: " << count << '\n';
    return false;
  }

  bool doFinalization(Module &mod) override {
    errs() << "Total number of functions: " << countF << '\n';
    return false;
  }
}; // end of struct Info
}  // end of anonymous namespace

char Info::ID = 0;
static RegisterPass<Info> X("info", "Function and Basic Block info",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
