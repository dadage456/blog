#include <stdio.h>
#include <unistd.h>

int snooze(unsigned int secs) {
  int remained = sleep(secs);
  printf("Slept for %d of %d secs.\n", secs - remained, secs);
  return remained;
}

int main(int argc, char *argv[]) {
  snooze(5);
}
