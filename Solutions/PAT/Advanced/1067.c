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
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 100000
/* Sort with Swap(0,*) (25) */

int x[N], idx[N];
int main() {
  read(n);
  int cnt = 0;
  forr(i, 0, n) {
    read(v); if (v != i) cnt++;
    idx[x[i] = v] = i;
  }
  int ans = 0;
  cnt++; while (cnt) { /* at most cnt+1 rounds */
    // prta(x, 0, n); prtl();
    if (!idx[0]) {
      bool found = false;
      forr(i, 0, n)
        if (x[i] != i) {
          idx[x[0] = x[i]] = 0;
          idx[x[i] = 0] = i;
          ans++; found = true;
          break;
        }
      if (!found) break;
    }
    int idx0 = idx[0];
    x[idx[0] = idx[idx0]] = 0; 
    x[idx[idx0] = idx0] = idx0;
    ans++; cnt--;
  }
  prti(ans);
}
