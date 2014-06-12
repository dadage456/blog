#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>

jmp_buf buf;

int err1 = 0;
int err2 = 1;

void bar() {
  if (err2) {
    longjmp(buf, 2);
  }
}

void foo() {
  if (err1) {
    longjmp(buf, 1);
  }
  bar();
}

int main(int argc, char *argv[], char *envp[]) {
  int rc;
  rc = setjmp(buf);

  if (rc == 0) {
    foo();
  } else if (rc == 1) {
    printf("detected err1\n");
  } else if (rc == 2) {
    printf("detected err2\n");
  } else {
    printf("unkown err\n");
  }
  exit(0);
}
