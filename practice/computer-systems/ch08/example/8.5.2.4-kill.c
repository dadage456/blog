#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/fork.h"

int main(int argc, char *argv[], char *evnp[]) {
  pid_t pid;

  if ((pid = Fork()) == 0) {
    pause();
    printf("Control should never reach here!\n");
    exit(0);
  }

  kill(pid, SIGKILL);
  exit(0);
}
