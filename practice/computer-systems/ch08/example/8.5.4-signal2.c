#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define MAXBUF 128

void handler(int sig) {
  pid_t pid;
  printf("---->\n");

  while ((pid = waitpid(-1, NULL, 0)) > 0) {
    printf("Handler reaped child %d\n", (int) pid);
  }

  if (errno != ECHILD) {
    printf("Waitpid error.\n");
    exit(1);
  }


  sleep(2);
  exit(0);
}

int main(int argc, char *argv[], char *envp[]) {
  int i, n;
  char buf[MAXBUF];

  signal(SIGCHLD, handler);

  for (i = 0; i < 3; i++) {
    if (fork() == 0) {
      printf("Hello from child %d\n", (int) getpid());
      sleep(1);
      exit(0);
    }
  }

  if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
    printf("Read error.\n");
    exit(1);
  }

  printf("Parent processing input\n");
  while (1) {}
  exit(0);
}








