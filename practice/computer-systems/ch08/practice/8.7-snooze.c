#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


int snooze(unsigned int secs) {
  int remained = sleep(secs);
  printf("Slept for %d of %d secs.\n", secs - remained, secs);
  return remained;
}

void handler(int sig) {
  return;
}

int main(int argc, char *argv[]) {
  signal(SIGINT, handler);
  snooze(5);
}
