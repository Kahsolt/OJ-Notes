#include <stdio.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define deforp(i, a, b) for(int i=a;i>=b;i--)
#define max(a, b) (((a)>=(b))?(a):(b))
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)
#define MAX_N 100
#define MAX_M 120

// 2021/08/15 

int m[MAX_N], r[MAX_N];
int dp[MAX_M+1] = { 0 };

int main() {
  read(N); read(M);
  forr (i, 0, N) { input(m[i]); input(r[i]); }

  forr (i, 0, N)
    deforp (j, M, m[i])
      dp[j] = max(dp[j], dp[j-m[i]] + r[i]);

  prti(dp[M]);
}
