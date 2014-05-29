#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  int i = 0;
  char *v;

  printf("Command line arguments:\n");
  while((v = argv[i++]) != NULL) {
    printf("  argv[%d]: %s\n", i, v);
  }

  i = 0;
  printf("Environment variable:\n");
  while((v = envp[i++]) != NULL) {
    printf("  envp[%d]: %s\n", i, v);
  }
}
