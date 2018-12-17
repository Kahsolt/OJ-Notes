#include <stdio.h>
#include <stdbool.h>
#define N 10001
/* String Subtraction (20) */

char str[N];
bool flag[1<<7] = { false };  // mark presence
int main() {
  gets(str);
  int c; while (c = getchar()) {
    if (c == '\n') break;
    else flag[c] = true;
  }
  char* p = str; while (*p != '\0') {
    if (!flag[*p])
      putchar(*p);
    p++;
  }
}