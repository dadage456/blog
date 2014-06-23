#include <sys/types.h>
#include <stdio.h>
#include "./memlib.h"

#define WSIZE 4
#define DSIZE 8
#define CHUNCKSIZE (1<<12)

#define PACK(size, alloc)  ((size) | (alloc))

#define GET(p)             (*(unsigned int *)(p))
#define PUT(p, val)        (*(unsigned int *)(p) = (val))

#define GET_SIZE(p)        (GET(p) & ~0x7)
#define GET_ALLOC(p)       (GET(p) & 0x1)

#define HDRP(bp)           ((bp) - WSIZE)
#define FTRP(bp)           ((bp) + GET_SIZE(HDRP(bp)) - DSIZE)

#define NEXT_BLKP(bp)      ((bp) + GET_SIZE((bp) - WSIZE))
#define PREV_BLKP(bp)      ((bp) - GET_SIZE((bp) - DSIZE))


static void *extend_heap(size_t size);
static void *coalesce(void *bp);
static void *find_fit(size_t size);
static void place(void *bp, size_t size);


static void *heap_listp;


int mm_init() {
  mem_init();

  if ((heap_listp = mem_sbrk(4 * WSIZE)) == (void *) -1) {
    return -1;
  }

  PUT(heap_listp, 0);
  PUT(heap_listp + 1 * WSIZE, PACK(DSIZE, 1));
  PUT(heap_listp + 2 * WSIZE, PACK(DSIZE, 1));
  PUT(heap_listp + 3 * WSIZE, PACK(0, 1));
  heap_listp += 2 * WSIZE;

  if (extend_heap(CHUNCKSIZE) == NULL) {
    return -1;
  }
  return 0;
}


static void *extend_heap(size_t size) {
  char *bp;

  if ((long)(bp = mem_sbrk(size)) == -1) return NULL;

  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

  return coalesce(bp);
}


void mm_free(void *bp) {
  size_t size = GET_SIZE(HDRP(bp));
  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  coalesce(bp);
}


static void *coalesce(void *bp) {
  size_t prev_alloc = GET_ALLOC(HDRP(PREV_BLKP(bp)));
  size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));

  if (prev_alloc && next_alloc) {
    return bp;

  } else if (prev_alloc && !next_alloc) {
    size += GET_SIZE(HDRP(NEXT_BLKP(bp)));

  } else if (!prev_alloc && next_alloc) {
    size += GET_SIZE(HDRP(PREV_BLKP(bp)));
    bp = PREV_BLKP(bp);

  } else {
    size += GET_SIZE(HDRP(NEXT_BLKP(bp)))
          + GET_SIZE(HDRP(PREV_BLKP(bp)));
    bp = PREV_BLKP(bp);
  }

  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  return bp;
}


void *mm_malloc(size_t size) {
  size_t asize;
  char *bp;

  if (size == 0) return NULL;

  asize = DSIZE + (size % DSIZE ? size / DSIZE * DSIZE + DSIZE : size);

  if (asize > CHUNCKSIZE) {
    printf("Error: requested memory size is too big.");
    return NULL;
  }


  if ((bp = find_fit(asize)) == NULL) {
    if ((bp = extend_heap(asize)) == NULL) {
      return NULL;
    }
  }

  place(bp, asize);
  return bp;
}


static void *find_fit(size_t size) {
  char *bp = heap_listp;
  while (GET_SIZE(HDRP(bp))) {
    if (!GET_ALLOC(HDRP(bp)) && GET_SIZE(HDRP(bp)) >= size) {
      return bp;
    }
    bp = NEXT_BLKP(bp);
  }
  return NULL;
}


static void place(void *bp, size_t size) {
  size_t left_size = GET_SIZE(HDRP(bp)) - size;

  PUT(HDRP(bp), PACK(size, 1));
  PUT(FTRP(bp), PACK(size, 1));

  char *next_bp = NEXT_BLKP(bp);
  PUT(HDRP(next_bp), PACK(left_size, 0));
  PUT(FTRP(next_bp), PACK(left_size, 0));
}


void mm_monitor() {
  char *bp = heap_listp;
  printf("-----printf start------\n");
  while (GET_SIZE(HDRP(bp))) {
    printf("%08x, %x\n", GET_SIZE(HDRP(bp)), GET_ALLOC(HDRP(bp)));
    bp = NEXT_BLKP(bp);
  }
  printf("-----printf end------\n");
}











