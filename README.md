# Tasks for UROP in Software Reliability Group

The two tasks are in their respective directories. <br>
**Running `make all` inside each of task1 and task2, quickly shows results.** <br>
For task2 the required pdf will be generated inside in the directory.

The rest of the README is just info on my implementation

## Task 1
`malloc\_intercept.c` contains a wrapper around `original_malloc`. <br>
I use the `<dlfcn>` library to dynamically read the address of the original malloc fucntion. <br>
The bytes allocated is tracked and printed during calls to `original_malloc`. <br>

`make` generates `malloc_intercept.so` which can be used with `LD_PRELOAD`. <br>
The make file uses the same program `seq 1 5` as in the example. <br>

#### Known problem: 
`RTLD_NEXT` doesn't seem to work on a virtual machine (ubuntu). `dlsym` gives the newly defined function instead of the original, resulting in infinte recursion. Nevertheless task1 works well on my PC and lab machines.

## Task 2
Inside the directory, `make llvm_pass` prints the number of functions and blocks, as well as generating data for gnuplot. <br>
`make plot_histogram` will create `Basic Blocks Histogram.pdf` <br>
The program being used can be changed by changing the Makefile variable and copying the `<program>.c` into the directory.

**Dependencies**: Clang and LLVM (with header files) and gnuplot. <br>
I've made a shared object, which `opt` can use to make an `analyze` (no mutation) pass. <br>
I've decided to subclass `FunctionPass`, with state stored in the members. <br>

The pass is registed as `info`. In each function, it iterates through the basic blocks and updating a map. The map is given by `x->y` where there are `y` basic blocks with `x` instructions each. The total block and functions count is also getting incremented. <br>
`doFinalization` is overriden to write the outputs using the information collected. <br>

(I had tried to subclass `ModulePass` (but that included `#include`s which was problematic).
 It is also more granular than necessary)


Also I can share ssh access to my DoC virtual machine (which I tested everything on) given a username.
