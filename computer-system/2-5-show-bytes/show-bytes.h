#ifndef _SHOW_BYTES_H_
#define _SHOW_BYTES_H_

typedef unsigned char *bytePointer;

void showBytes(bytePointer start, int len);
void showInt(int x);
void showFloat(float x);
void showPointer(void *x);
#endif
