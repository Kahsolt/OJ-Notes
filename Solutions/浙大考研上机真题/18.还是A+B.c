#include <stdio.h>

static inline int test(int a, int b, int k) {
  int mod = 1; while (k--) mod *= 10;
  return a % mod == b % mod;
}
int main() {
  int a, b, k; while (~scanf("%d%d%d", &a, &b, &k)) {
    if (!a && !b) break;
    if (test(a, b, k)) puts("-1");
    else printf("%d\n", a + b);
  }
}