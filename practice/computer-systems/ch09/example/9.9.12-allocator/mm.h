#ifndef _MM_H_
#define _MM_H_

#include <sys/types.h>

int mm_init();
void *mm_malloc(size_t size);
void mm_free(void *bp);
void mm_monitor();

#endif
