#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define N 10000

int x[N], dp[N], cnt[N];
int main() {
  int n; while (~scanf("%d", &n)) {
    if (!n) break;
    bool all_negetive = true;
    forr(i, 0, n) {
      input(x[i]);
      if (x[i] >= 0) all_negetive = false;
    }
    if (all_negetive) {
      printf("0 %d %d\n", x[0], x[n-1]);
      continue;
    }
    mset(cnt, 0x00); mset(dp, 0x00); dp[0] = x[0];
    int idx = 0, maxsum = x[0];
    forr(i, 1, n) {
      if (dp[i-1] > 0) {
        dp[i] = dp[i-1] + x[i];
        cnt[i] = cnt[i-1] + 1;
      } else dp[i] = x[i];
      if (dp[i] > maxsum)
        maxsum = dp[idx = i];
    }
    printf("%d %d %d\n", maxsum, x[idx-cnt[idx]], x[idx]);
  }
}