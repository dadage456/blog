#include <stdlib.h>
#include <stdio.h>

#define MAX_HEAP (1<<16)

static void *mem_heap;
static void *mem_brk;
static void *mem_max_addr;

void mem_init() {
  mem_heap = malloc(MAX_HEAP);
  mem_brk = mem_heap;
  mem_max_addr = mem_heap + MAX_HEAP;
}

void *mem_sbrk(int incr) {
  char *old_brk = mem_brk;
  if (incr <= 0) {
    printf("ERROR: mem_brk failed. incr is not a positive integer.\n");
    return (void *) -1;
  }

  if (mem_brk + incr > mem_max_addr) {
    printf("ERROR: mem_brk failed. Ran out of memory.\n");
    return (void *) -1;
  }

  mem_brk += incr;
  return old_brk;
}
