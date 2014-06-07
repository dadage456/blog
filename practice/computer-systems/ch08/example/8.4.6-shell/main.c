#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 128

void eval(char *cmdline, char **envp);

int main(int argc, char *argv[], char *envp[]) {
  char cmdline[MAXLINE];

  while (1) {
    printf("> ");
    fgets(cmdline, MAXLINE, stdin);
    if (feof(stdin)) {
      exit(0);
    }

    eval(cmdline, envp);
  }
}
