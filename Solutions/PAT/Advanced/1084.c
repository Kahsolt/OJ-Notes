#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <ctype.h>
#define N 1000
/* Broken Keyboard (20) */

char str[N];
bool flag[1<<7];
#define test(p) { \
  if (!flag[*p]) { \
    flag[*p] = true; \
    putchar(*p); \
  } p++; }

int main() {
  memset(flag, false, sizeof(flag));
  gets(str);
  char *p = str;
  while (*p != '\0') { *p = toupper(*p); p++; }

  char c; p = str;
  while (c = getchar()) {
    if (c == '\n') break;
    c = toupper(c);
    while (*p != c && *p != '\0')
      test(p);
    if (*p != '\0') p++;
  }
  while (*p != '\0')  /* the leftovers in str */
    test(p);
}