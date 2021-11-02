#include <stdio.h>
#define MAXN 1000

/*
2 2
3 4
*/

int dp[MAXN+1][MAXN+1] = { 0 };

int main() {
  int n, t; scanf("%d%d", &n, &t);
  if (!t) { puts("0"); return 0; }
  else if (t == 1) { puts("1"); return 0; }

  int ans = 1, exp = 1;
  dp[1][1] = 1;
  for (int i=2; i<=n; i++) {
		exp <<= 1;
		int found = 0;
		for (int j=1; j<=i; j++) {
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			// printf("exp=%d dp[i][j]=%d /=%.2f\n", exp, dp[i][j], (float) exp / dp[i][j]);
			if (exp <= dp[i][j] * (t - i)) { ans++; found = 1; }
		}
		//if (!found) break;		// stop early
  }

	printf("%d\n", ans);
}