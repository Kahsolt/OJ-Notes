#include <stdio.h>
/* A+B Format (20) */

void prt(int a) {
  int res = a % 1000;
  a /= 1000;
  if (a) { prt(a); printf(",%03d", res); }
  else printf("%d", res);
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  a += b;
  if (a < 0) { printf("-"); a = -a; }
  prt(a);
  printf("\n");
}