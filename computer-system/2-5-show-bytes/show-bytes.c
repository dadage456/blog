#include <stdio.h>

typedef unsigned char *bytePointer;

void showBytes(bytePointer start, int len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %x", start[i]);
  }
  printf("\n");
}

void showInt(int x) {
  showBytes((bytePointer) &x, sizeof(int));
}

void showFloat(float x) {
  showBytes((bytePointer) &x, sizeof(float));
}

void showPointer(void *x) {
  showBytes((bytePointer) &x, sizeof(void *));
}
