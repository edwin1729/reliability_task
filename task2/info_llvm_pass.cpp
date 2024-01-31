#include <cstdlib>
#include <algorithm>
#include <map>
#include <stdexcept>

#include "llvm/Pass.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
struct Info : public FunctionPass {
  int countF = 0;  // total number of functions
  int countBB = 0; // total number of basic blocks

  // histogram data: instr count -> basic block count
  std::map<int, int> countI_to_BB {}; 

  static char ID;
  Info() : FunctionPass(ID) {}

  bool runOnFunction(Function& F) override {
    ++countF;
    countBB += F.size(); // add number of basic blocks in current function
    for (const auto& BB : F) {
      int countI = BB.size(); // number of instructions in basic block
      if(countI_to_BB.find(countI) == countI_to_BB.end()) {
        countI_to_BB[countI] = 1;  // new entry in map
      } else {
        countI_to_BB[countI] += 1; // old entry update
      }
    }
    return false;
  }

  // Writing output to stderr and data file (for gnuplot)
  bool doFinalization(Module &M) override {
    // The outout for task 2a
    errs() << "Total number of functions: " << countF << '\n';
    errs() << "Total number of basic blocks: " << countBB << '\n';

    // task 2b. Currently I throw exception if IO errors occur
    // An environment variable specifies file to write to
    if (const char* file_name = std::getenv("DATA")) {
      std::error_code EC;
      raw_fd_ostream file(file_name, EC);
      if (EC) {
        throw std::runtime_error("Unexpected error creating a file");
      }
      
      for (auto const& [key, val] : countI_to_BB) {  
        file << key << ' ' << val << '\n';
      }
    }
    else {
      throw std::runtime_error("Erroneous Makefile: env var doesn't exist");
    }

    return false;
  }
};
}

char Info::ID = 0;
static RegisterPass<Info> X("info", "Function and Basic Block info",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
