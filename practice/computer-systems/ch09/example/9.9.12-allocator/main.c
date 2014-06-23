#include "./mm.h"

int main(int argc, char *argv[], char *envp[]) {
  mm_init();
  mm_monitor();

  void *bp1 = mm_malloc(9);
  mm_monitor();

  void *bp2 = mm_malloc(1);
  mm_monitor();

  mm_free(bp1);
  mm_monitor();

  mm_free(bp2);
  mm_monitor();
}
