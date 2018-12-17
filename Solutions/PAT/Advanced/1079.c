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
#define inputf(x) scanf("%lf",&x)
#define readf(x) double x;inputf(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 100000
/* Total Sales of Supply Chain (25) */

int father[N], dist[N];
int orders[N][2], orders_cur = 0;
int getdist(int n) {
  if (dist[n] != -1) return dist[n];
  int fn = father[n];
  return fn ? getdist(fn) + 1 : 1;
}
int main() {
  read(n); readf(p); readf(r); r = 1.0 + r / 100.0; // refine 'r'
  forr(i, 0, n) dist[father[i] = i] = -1; dist[0] = 0;  // init dist[0]
  forr(i, 0, n) {
    read(k); if (!k) {
      input(orders[orders_cur][1]);
      orders[orders_cur++][0] = i;
    } else while (k--) {
      read(s); father[s] = i;
      if (dist[i] != -1)
        dist[s] = dist[i] + 1;  // OPT: compress dist if possible 
    }
  }
  double ans = 0.0;
  forr(i, 0, orders_cur) {
    int n = orders[i][0];
    int dis = dist[n]!=-1 ? dist[n] : getdist(n);
    ans += p * orders[i][1] * pow(r, dis);
  }
  printf("%.1f" ,ans);
}
