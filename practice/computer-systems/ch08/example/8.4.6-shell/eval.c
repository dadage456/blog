#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXARGS 128
#define MAXLINE 128

int parseline(char *buf, char **argv);
int builtin_command(char **argv);

void eval(char *cmdline, char **envp) {
  char *argv[MAXARGS];
  char buf[MAXLINE];
  int bg;
  pid_t pid;

  strcpy(buf, cmdline);
  bg = parseline(buf, argv);

  if (argv[0] == NULL) {
    return;
  }

  if (!builtin_command(argv)) {
    if ((pid = fork()) == 0) {
      if (execve(argv[0], argv, envp) < 0) {
        printf("%s: Command not found.\n", argv[0]);
        exit(0);
      }
    }

    if (!bg) {
      int status;
      if (waitpid(pid, &status, 0) < 0) {
        printf("waitfg: waitpid error");
        exit(1);
      }
    } else {
      printf("%d %s", pid, cmdline);
    }
  }

  return;
}


int builtin_command(char **argv) {
  if (!strcmp(argv[0], "quit")) {
    exit(0);
  }

  if (!strcmp(argv[0], "&")) {
    return 1;
  }

  return 0;
}
