#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _n=n;while(_n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 10001
/* Deepest Root (25) */

int set[N], depth[N]; /* depth to its root */
int dist[N][N];
bool ans[N];
int root(int x) {
  return set[x] != x ? set[x] != root(set[x]): x;
}
int root2(int x) {
  /* no path compression, to reserve path chain */
  while (x != set[x]) x = set[x];
  return x;
}
bool inchain(int x, int y) {  /* y is in the chain to x */
  if (x == y) return true;
  else if (x > y) x ^= y ^= x ^= y;  /* keep lesser order */
  while (y != set[y]) {
    if (y == x) return true;
    y = set[y];
  }
  return y == x;
}
int main() {
  read(n);
  forp(i, 1, n) depth[set[i] = i] = 0;  /* init depth = 0 */
  int maxdepth = 0;
  times(n-1) {
    read(x); read(y);
    int rx = root(x), ry = root(y);
    /* keep order: small id is near root */
    if (rx >= ry) { set[rx] = y; depth[x] = depth[y] + 1; }
    else { set[ry] = x; depth[y] = depth[x] + 1; }
  }

  prta(set, 1, n+1); prtl();
  prta(depth, 1, n+1); prtl();

  int cnt = 0;
  forp(i, 1, n) if (root(i) == i) cnt++;
  if (cnt != 1) printf("Error: %d components", cnt);
  else {
    int maxdis = -1;
    forp(i, 1, n-1)
      forp(j, i+1, n) {
        dist[i][j] = inchain(i, j) 
          ? depth[j] - depth[i] 
          : depth[j] + depth[i];
        if (maxdis < dist[i][j])
          maxdis = dist[i][j];
      }
    mset(ans, false);
    forp(i, 1, n-1)
      forp(j, i+1, n)
        if (dist[i][j] == maxdis)
          ans[i] = ans[j] = true;
    forp(i, 1, n)
      if (ans[i])
        { prti(i); prtl(); }
  }
}
