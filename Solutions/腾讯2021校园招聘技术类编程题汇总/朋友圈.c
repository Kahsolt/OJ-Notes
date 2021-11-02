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
#define N 10000001

// 2021/08/16 

int f[10000001];

static inline int father(int i) {
  return (f[i] != i) ? f[i] = father(f[i]) : i;
} 

int main() {
  read(T); times(T) {
    read(n);
    forr (i, 0, N) f[i] = i;

    int maxid = 0;
    forp (i, 1, n) {
      read(x); read(y);
      if (x > maxid) maxid = x;
      if (y > maxid) maxid = y;
      int fx = father(x), fy = father(y);
      //printf("f(%d) = %d, f(%d) = %d\n", x, fx, y, fy);
      if (fx == fy) continue;
      if (fx < fy) f[fy] = fx;
      else f[fx] = fy;
    }

    forp (i, 1, maxid)
      f[i] = father(f[i]);
    
    qsort(f, maxid+1, sizeof(int), cmp);
    //forp (i, 1, maxid)
    //  printf("%d ", f[i]);
    //prtl();

    int maxcnt = 0, cnt = 1;
    forp (i, 2, maxid) {
      if (f[i] == f[i-1]) cnt++;
      else {
        if (cnt > maxcnt) maxcnt = cnt;
        cnt = 1;
      }
    }
    if (cnt > maxcnt) maxcnt = cnt;

    prti(maxcnt); prtl();
  }
}
