#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 101
#define INF 0x3f3f3f3f

int graph[N][N];
int prim(int n) {
  int ans = 0;
  int dis[n], vis[n];

  for(int i=1; i<=n; i++) {
    dis[i] = graph[1][i];
    vis[i] = false;
  }
  dis[1] = 0; vis[1] = true;

  for (int i=2; i<=n; i++) {
    int idx = -1, mindis = INF;
    for (int j=1; j<=n; j++)
      if (!vis[j] && dis[j]<mindis)
        mindis = dis[idx = j];
    if (idx == -1) return -1;
    ans += mindis;
    vis[idx] = true;
    for (int j=1; j<=n; j++)
      if (!vis[j] && dis[j]>graph[idx][j])
        dis[j] = graph[idx][j];
  }
  return ans;
}

int main() {
  int n, m; while (~scanf("%d%d", &m, &n)) {
    if (!m) break;
    memset(graph, INF, sizeof(graph));
    for (int i=1; i<=n; i++) graph[i][i] = 0;
    
    while (m--) {
      int x, y, v; scanf("%d%d%d", &x, &y, &v);
      if (v < graph[x][y] || v < graph[y][x])
        graph[x][y] = graph[y][x] = v;
    }
    int ans = prim(n);
    if (ans == -1) puts("?");
    else printf("%d\n", ans);
  }
}