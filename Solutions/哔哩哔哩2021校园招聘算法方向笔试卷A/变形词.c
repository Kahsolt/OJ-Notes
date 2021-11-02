#include <stdio.h>
#include <string.h>

#define N 100000
#define CHAR_MAX 256

char s[N+1], t[N+1];
int cnts[CHAR_MAX] = { 0 }, cntt[CHAR_MAX] = { 0 };

int main() {
  scanf("%s", s); getchar(); scanf("%s", t);

  char *p = s; while (*p) { cnts[*p]++; p++; }
  char *q = t; while (*q) { cntt[*q]++; q++; }
  if (p-s != q-t) { putchar('0'); return 0; }

  for (int i=0; i<CHAR_MAX; i++)
    if (cnts[i] != cntt[i])
      { putchar('0'); return 0; }
  
  { putchar('1'); return 0; }
}
