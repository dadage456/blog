#include <stdio.h>

char *map[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
               "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

void tobinary(char *s) {
  int i;
  char c;
  while ((c = *s++) != '\0') {
    if (c <= '9') {
      printf("%s", map[c - '0']);
    } else {
      printf("%s", map[c - 'a' + 10]);
    }
  }
  printf("\n");
}

int main(){
  char s1[] = "00359141";
  char s2[] = "4a564504";
  tobinary(s1);
  printf("  ");
  tobinary(s2);
}
