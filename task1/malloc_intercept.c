#include <stdio.h>
#include <dlfcn.h>

// total bytes allocated by malloc so far
int total_bytes=0;

void* (*original_malloc)(size_t size)  = NULL;

// Overriding malloc function
void* malloc(size_t size) {

  // Load the original malloc function
  // The if check is necessary so that we don't get older and older versions of malloc
  // This happens to not be a problem here since we are only defining the 2nd version
  if (original_malloc == NULL)
    original_malloc = dlsym(RTLD_NEXT, "malloc");

  // Print output
  total_bytes += size;
  fprintf(stderr, "Bytes allocated so far %d \n", total_bytes);

  // Actually malloc some bytes
  return original_malloc(size);
}
