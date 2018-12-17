#include <stdio.h>
#include <stdbool.h>

int main() {
  char s, c;  // sign, test char
  while (true) {
    s = getchar(); if (s != '-') ungetc(s, stdin);
    int a = 0; while (true) {
      int tmp; scanf("%d", &tmp); a = a * 1000 + tmp;
      c = getchar(); if (c == ' ') break;
    }
    if (s == '-') a = -a;
    s = getchar(); if (s != '-') ungetc(s, stdin);
    int b = 0; while (true) {
      int tmp; scanf("%d", &tmp); b = b * 1000 + tmp;
      c = getchar(); if (c == '\n') break;
    }
    if (s == '-') b = -b;
    printf("%d\n", a + b);
    c = getchar();
    if (c == EOF) break;
    else ungetc(c, stdin);
  }
}
