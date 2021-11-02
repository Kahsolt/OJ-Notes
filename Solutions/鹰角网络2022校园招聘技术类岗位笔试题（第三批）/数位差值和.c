#include <stdio.h>
#include <stdlib.h>

inline long long D(long long x) {
  long r = 0;
  while (x) {
    r += x % 10;
    x /= 10;
  }
  return r;
}

long long getSum(int n) {
  if (n <= 9) return 0;
  long long R = 0;

  int i = 10;
  while (i + 10 <= n) {
    R += 10 * (i - D(i));
    i += 10;
  }
  if (i <= n) {
    int c = n - i + 1;
    R += c * (i - D(i));
  }

  return R;
}
