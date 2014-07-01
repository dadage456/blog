#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char *argcv[], char *envp[]) {
  int fd1;
  int fd2;
  char c;

  fd1 = open("./foobar.txt", O_RDONLY, 0);
  fd2 = open("./foobar.txt", O_RDONLY, 0);

  printf("%d, %d\n", fd1, fd2);
}
