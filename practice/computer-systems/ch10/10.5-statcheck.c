#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


int main(int argc, char *argv[], char *envp[]) {
  struct stat s;
  char *type;
  char *readok;

  stat(argv[1], &s);

  /*
  printf("%d, %llu, %d, %d\n%d, %d, %d, %lld\n%d, %lld, %ld, %ld, %ld\n",
      s.st_dev, s.st_ino, s.st_mode, s.st_nlink,
      s.st_uid, s.st_gid, s.st_rdev, s.st_size,
      s.st_blksize, s.st_blocks, s.st_atime, s.st_mtime, s.st_ctime);
  */

  if (S_ISREG(s.st_mode)) {
    type = "regular";
  } else if (S_ISDIR(s.st_mode)) {
    type = "directory";
  } else {
    type = "other";
  }

  if ((s.st_mode & S_IRUSR)) {
    readok = "yes";
  } else {
    readok = "no";
  }

  printf("type: %s, readok: %s\n", type, readok);
  return 0;
}
