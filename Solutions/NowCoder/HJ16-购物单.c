#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define max(a, b) (((a)>=(b))?(a):(b))
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define MAXN 32000
#define MAXM 60

// 2021/08/14 

/*
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
*/

int v[MAXM+1] = { 0 },    // value
    p[MAXM+1] = { 0 },    // profit = priority*value
    f[MAXM+1] = { 0 };    // father relation

int main() {
  read(n); read(m);
  forp (i, 1, m) {
    scanf("%d%d%d", &v[i], &p[i], &f[i]);
    p[i] *= v[i];
  }

  int sz = (n + 1) * sizeof(int);
  int *dp = (int*) malloc(sz); memset(dp, 0, sz);
  forp (i, 1, m)
    // forp (j, v[i], n) {  // dp[j]: 用j这么多的钱能得到的最大价值
    for (int j=n; j>=v[i]; j--) {
      if (!f[i]) {    // for main artifact
        dp[j] = max(dp[j], dp[j-v[i]] + p[i]);
      } else if (j>=v[i]+v[f[i]]) {        // for accessory
        dp[j] = max(dp[j], dp[j-v[i]-v[f[i]]] + p[i]+p[f[i]]);
      }
    }

  prti(dp[n]);
}
