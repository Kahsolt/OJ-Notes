#include <stdio.h>
#include <string.h>
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)
#define MAXN 100000
#define MAXM 7
#define MOD 1000000007L

// 2021/09/14
// WA

int dp[MAXM][MAXM][MAXN] = { 0 };

int main() {
  read(n); read(m);

  memset(dp, 0xFF, sizeof(dp));   // -1 for invalid
  dp[0][0][0] = 0;
  for (int k=1; k<=m; k++)
    dp[0][0][k] = 1;

  for (int T=1; T<=n; T++)           // 讨论台阶T的可达性
    for (int k=1; k<=m && k<T; k++)  // 试着这次走k步
      for (int i=0; i<=m && i<T; i++) {     // 上一次走了i步
        if (i == k) continue;
        for (int j=0; j<=m && j<T; j++) {   // 上上次走了j步
          if (j == k) continue;
          if (dp[i][j][T-k] > 0) {
            if (dp[k][i][T] < 0) dp[k][i][T] = 0;
            dp[k][i][T] += dp[i][j][T-k];
            dp[k][i][T] %= MOD;
          }
        }
      }

  int ans = 0;
  for (int i=1; i<=m; i++)
    for (int j=1; j<=m; j++)
      if (dp[i][j][n] > 0)
        ans = (ans + dp[i][j][n]) % MOD;

  prti(ans);
}
