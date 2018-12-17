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
int cmp(const void* a, const void *b) { return *((int*)a) - *((int*)b); }
#define N 100000
#define M 1000
/* Find Coins (25) */

int val[N];
int cnt[M] = { 0 };
int main() {
  read(n); read(m);
  forr(i, 0, n) {
    read(x);
    cnt[val[i]=x]++;
  }
  qsort(val, n, sizeof(int), cmp);
  bool found = false;
  forr(i, 0, n) {
    int a = val[i], b = m - a;
    if (a > b) break;
    if (b <= 500) {
      if (a==b && cnt[a]>=2
          || a<b && cnt[b]>=1) {
        printf("%d %d\n", a, b);
        found = true;
        break;
      }
    }
  }
  if (!found) puts("No Solution");
}
