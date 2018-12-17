#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100001
#define M 10000
#define MIN(x, y) (((x)<=(y))?(x):(y))
/* Shortest Distance (20) */

int dp[N];  /* dist from 1 to i */
int main() {
  int n;
  scanf("%d", &n);
  dp[1] = 0;  /* init */
  for (int i=1; i<=n; i++) {
    int w;
    scanf("%d", &w);
    dp[i%n+1] = dp[(i-1+n)%n+1] + w;
  }
  int circle = dp[1]; /* circle is the round length */

  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    int r1 = abs(dp[x] - dp[y]);
    int r2 = circle - r1;
    printf("%d\n", MIN(r1, r2));
  }
}