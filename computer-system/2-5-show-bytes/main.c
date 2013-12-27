#include <stdio.h>
#include "show-bytes.h"

int main() {
  int val = 0x87654321;
  bytePointer bp = (bytePointer) &val;

  showBytes(bp, 1);
  showBytes(bp, 2);
  showBytes(bp, 3);
  showBytes(bp, 4);

  return 0;
}
