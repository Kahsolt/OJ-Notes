#include <stdio.h>
#define min(a, b) (((a)<=(b))?(a):(b))

// 2021/08/09 
// WA: 0/1

int x[7];   // x[0] is dummy

int solve() {
  int ans = 0, r;

  // handle 6x6
  ans += x[6];

  // handle 5x5
  ans += x[5];
  x[1] -= 11 * x[5];

  // handle 4*4
  ans += x[4];
  x[2] -= 5 * x[4];

  // handle 3*3
  ans += x[3] / 4;
  r = x[3] % 4;
  if (r) {
    ans++;
    if (x[2] > 0) {
      int use2 = min(r, x[2]);
      x[2] -= r;
      x[1] -= 36 - 3*3*r - 2*2*use2;
    }
  }

  // handle 2*2
  if (x[2] > 0) {
    ans += x[2] / 9;
    r = x[2] % 9;
    if (r) {
      x[1] -= 36 - 2*2*r;
    }
  }

  if (x[1] > 0) {
    ans += x[1] / 36;
    r = x[1] % 36;
    if (r) ans++;
  }

  return ans;
}

int main() {
  while (~scanf("%d%d%d%d%d%d", &x[1], &x[2], &x[3], &x[4], &x[5], &x[6]))
    printf("%d\n" , solve());
}
