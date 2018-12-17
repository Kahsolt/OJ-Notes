#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 10000
/* Maximum Subsequence Sum (25) */

int x[N], dp[N], cnt[N];
int main() {
  read(n);
  bool all_negative = true;
  forr(i, 0, n) {
    scanf("%d", &x[i]);
    if (x[i] >= 0) all_negative = false;
  }
  if (all_negative) {
    printf("0 %d %d\n", x[0], x[n-1]);
    return 0;
  }

  mset(dp, 0); dp[0] = x[0]; cnt[0] = 1;
  int idx = 0, maxsum = x[0];
  forr(i, 1, n) {
    if (dp[i-1] > 0) {
      dp[i] =  dp[i-1] + x[i]; /* max contiuous sum */
      cnt[i] = cnt[i-1] + 1;
    } else {
      dp[i] = x[i];
      cnt[i] = 1;
    }
    if (dp[i] > maxsum) maxsum = dp[idx=i];
  }
  
  if (!n) printf("0 0 0\n");  /* FIXME: redundant? */
  else printf("%d %d %d\n", maxsum, x[idx-cnt[idx]+1], x[idx]);
}