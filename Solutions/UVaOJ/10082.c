#include <stdio.h>

char* keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char map[128] = { 0 };

/* 10082. WERTYU */
int main() {
  char *p = keyboard; p++;
  while (*p) {
    map[*p] = *(p - 1);
    p++;
  }

  char c;
  while ((c = getchar()) != EOF)
    if (map[c]) putchar(map[c]);
}