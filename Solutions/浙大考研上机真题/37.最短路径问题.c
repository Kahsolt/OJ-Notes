#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define read(x) int x;scanf("%d",&x)
#define INF 0x3F3F3F3F
#define N 1000
#define M 100000

int graph[N][N];  // the dist
int cost[N][N];
void djikstra(int n, int S, int D) {
  bool vis[N] = { false };
  int dis[N], cos[N];
  forp(i, 1, n) {
    dis[i] = graph[S][i];
    cos[i] = cost[S][i];
  }
  dis[S] = cos[S] = 0; vis[S] = true;

  forr(t, 1, n) { // n-1 turns
    int idx = -1, mindis = INF;
    forp(i, 1, n)
      if (!vis[i] && dis[i] < mindis)
        mindis = dis[idx = i];
    vis[idx] = true;

    forp(i, 1, n) if (!vis[i]) {
      int rd = dis[idx] + graph[idx][i];  // cached values
      int rc = cos[idx] + cost[idx][i];
      if (dis[i] > rd)
        { dis[i] = rd; cos[i] = rc; }
      else if (dis[i] == rd && cos[i] > rc)
        cos[i] = rc;
    }
  }
  printf("%d %d\n", dis[D], cos[D]);
}

int main() {
  mset(graph, INF); mset(cost, INF);
  read(n); read(m); {
    times(m) {
      int x, y, d, c; scanf("%d%d%d%d", &x, &y, &d, &c);
      if (d < graph[x][y]) {
        graph[x][y] = graph[y][x] = d;
        cost[x][y] = cost[y][x] = c;
      } else if (d == graph[x][y] && c < cost[x][y])
        cost[x][y] = cost[y][x] = c;
    }
    read(s); read(t); djikstra(n, s, t);
  }
}