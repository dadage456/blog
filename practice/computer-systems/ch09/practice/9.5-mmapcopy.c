#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(0);
  }

  int fd = open(argv[1], O_RDONLY, 0);
  struct stat stat;
  fstat(fd, &stat);
  char *bufp = mmap(NULL, stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  write(1, bufp, stat.st_size);
  return 0;
}
