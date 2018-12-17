#include <stdio.h>
#define N 100

// 2018/08/27
// 完全错排公式
//   F[i] = (n-1) * (F[i-1] + F[i-2])
//   (F[1] = 0, F[2] = 1)

int staggered(int n) {
  int dp[N];
  dp[1] = 0; dp[2] = 1;
  for (int i=0; i<=n; i++)
    dp[i] = (n - 1) * (dp[i-1] + dp[i-2]);
  return dp[n];
}
int main() {
  
}
