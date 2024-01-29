#include <stdio.h>
#include <dlfcn.h>

// total bytes allocated by malloc so far
int total_bytes=0;

// Overriding malloc function
void* malloc(size_t size) {

  // Load the original malloc function
  typedef void* (*malloc_t)(size_t size); //Pointer to malloc func type
  malloc_t original_malloc = (malloc_t)dlsym(RTLD_NEXT, "malloc");

  void* ptr = original_malloc(size);
  total_bytes += size;
  fprintf(stderr, "Bytes allocated so far %d \n", total_bytes);

  return ptr;
}
