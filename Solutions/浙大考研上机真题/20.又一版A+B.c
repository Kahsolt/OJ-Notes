#include <stdio.h>

typedef unsigned long UL;
static inline void prt_inbase(UL x, int b) {
  UL high = x / b;
  if (high) prt_inbase(high, b);
  printf("%d", x % b, b);
}
int main() {
  int m; while (~scanf("%d", &m)) {
    if (!m) break;
    UL a, b; scanf("%lu%lu", &a, &b);
    prt_inbase(a + b, m); putchar(10);
  }
}