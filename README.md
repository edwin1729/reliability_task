# Tasks for UROP in Software Reliability Group

The two tasks are in their respective directories.
**Running `make all` inside each task1 and task2, quickly shows results.**

## Task 1
*malloc\_intercept.c* contains the function hook to malloc. <br>
I use the `<dlfcn>` library to dynamically read the address of the original malloc fucntion. <br>
The bytes allocated is tracked and printed during calls to `original_malloc` <br>

*make* generates *malloc_intercept.so* which can be used in <br>
`LD_PRELOAD=./malloc_intercept.so seq 1 5` <br>
The make file uses the same program `seq 1 5` as in the example <br>

#### Known problem: 
`RTLD_NEXT` doesn't seem to work on a virtual machine(ubuntu). `dlsym` gives the newly defined function instead of the original resulting in infinte recursion. Nevertheless task1 works well on my PC and lab machines. This is a problem I didn't have time to investigate thoroughly.

## Task 2
Inside the directory, `make llvm_pass` prints the number of functions and blocks, as well as generating data for gnuplot. <br>
`make plot_histogram` will create `Basic Blocks Histogram.pdf` <br>
The program being used can be changed by changing the Makefile variable and copying the `<program>.c` into the directory.

Dependencies: Clang and LLVM (with header files) and gnuplot. <br>
I've made shared object which `opt` can use to make an `analyze` (no mutation) pass. <br>
I've decided to subclass `FunctionPass`, with state stored in the members. <br>
(I had tried to subclass `ModulePass (but that included `#include`s which was problematic).
 It is also more granular than necessary)


Also I can share ssh access to a DoC virtual machine (which I tested everything on) given a username.
