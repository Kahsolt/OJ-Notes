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
#define N 500
/* Eulerian Path (25) */

int deg[N+1];
int set[N+1];
int root(int x) { return set[x]!=x ? set[x]=root(set[x]) : x; }
int main() {
  read(n); forp(i, 1, n) set[i] = i;
  read(m); times(m) {
    read(x); deg[x]++;
    read(y); deg[y]++;
    set[root(y)] = root(x);
  }
  int cntodd = 0;
  forp(i, 1, n) {
    if (i > 1) putchar(' '); prti(deg[i]);
    if (deg[i] & 0x01) cntodd++;
  }
  prtl();

  int cnt = 0;
  forp(i, 1, n) if (set[i] == i) cnt++;
  if (cnt > 1) cntodd = -1; // adjust, if graph not connected

  puts(!cntodd
    ? "Eulerian"
    : cntodd==2
      ? "Semi-Eulerian"
      : "Non-Eulerian");
}