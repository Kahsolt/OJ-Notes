#include <stdio.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define max(a, b) (((a)>=(b))?(a):(b))
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)
#define MAXN 100000
#define MAXM 100000

// 2021/08/18 

int w[MAXN], v[MAXN];
int dp[MAXM+1] = { 0 };

int main() {
  read(n); read(m);
  forr (i, 0, n) input(w[i]);
  forr (i, 0, n) input(v[i]);

  forr (i, 0, n)
    for (int j=m; j>=w[i]; j--)
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
  
  prti(dp[m]);
}
