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
#define N 201
/* Hamiltonian Cycle (25) */

bool graph[N][N] = { false }, vis[N] = { false };
int main() {
  read(n); read(m); times(m) {
    read(x); read(y);
    graph[x][y] = graph[y][x] = true;
  }
  read(k); times(k) {
    read(cnt); if (cnt != n+1) {
      times(cnt) scanf("%*d");
      puts("NO");
    } else {
      read(S); int cur = S, D;
      mset(vis, false); vis[S] = true; bool ok = true;
      while (ok && --cnt) {
        input(D);
        if (graph[cur, D])
          vis[cur = D] = true;  // move forward
        else ok = false;
      }
      if (S != D) ok = false; // circle?
      for (int i=1; ok && i<=n; i++)  // all vertexes corvered?
        if (!vis[i]) ok = false;
      puts(ok ? "YES" : "NO");
    }
  } 
}