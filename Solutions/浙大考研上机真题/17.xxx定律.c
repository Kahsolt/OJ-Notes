#include <stdio.h>
#include <memory.h>
#define mset(d, v) memset(d,v,sizeof(d))
#define N 10001

int ans[N]; // memory cache
int _3n_m1(int x) { // 3*n-1 law
  if (ans[x] != -1) return ans[x];
  return (x & 0x01)
    ? (ans[x] = _3n_m1((3 * x + 1) >> 1) + 1)
    : (ans[x] = _3n_m1(x >> 1) + 1);
}
int main() {
  mset(ans, 0xFF); ans[1] = 0;

  int n; while (~scanf("%d", &n)) {
    if (!n) break;
    printf("%d\n", _3n_m1(n));
  }
}