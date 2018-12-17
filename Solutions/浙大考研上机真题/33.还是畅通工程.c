#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 101
#define INF 0x3f3f3f3f

// 3.继续畅通工程 的简化版

int graph[N][N];
int prim(int n) {
  int ans = 0;
  int dis[N], vis[N];

  for(int i=1; i<=n; i++) {
    dis[i] = graph[1][i];
    vis[i] = false;
  }
  dis[1] = 0; vis[1] = true;

  for (int i=2; i<=n; i++) {
    int idx = -1, mindis = INF;
    for (int j=1; j<=n; j++)
      if (!vis[j] && mindis>dis[j])
        mindis = dis[idx = j];
    ans += mindis;
    vis[idx] = true;
    for (int j=1; j<=n; j++)
      if (!vis[j] && dis[j]>graph[idx][j])
        dis[j] = graph[idx][j];
  }
  return ans;
}

int main() {
  int n; while (~scanf("%d", &n)) {
    if (!n) break;
    memset(graph, INF, sizeof(graph));
    
    int m = n * (n - 1) >> 1;
    while (m--) {
      int x, y, v; scanf("%d%d%d", &x, &y, &v);
      graph[x][y] = graph[y][x] = v;
    }
    printf("%d\n", prim(n));
  }
}
