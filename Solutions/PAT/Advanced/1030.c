#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 500
#define INF 0x3F3F3F3F
/* Travel Plan (30) */

int graph[N][N], path[N], ansdist, anscost;
void dijkstra(int n, int s, int d) {
  bool vis[N]; memset(vis, false, n * sizeof(bool));
  int dis[N], cost[N];
  for (int i=0; i<n; i++) {
    graph[i][i] = 0;  /* dist/cost for self loop shoud be 0 */
    dis[i]  = s < i ? graph[s][i] : graph[i][s];
    cost[i] = s > i ? graph[s][i] : graph[i][s];
    path[i] = s;
  }
  dis[s] = cost[s] = 0; vis[s] = true;

  for (int i=1; i<n; i++) { /* n-1 rounds */
    int idx = -1, mindis = INF;
    for (int j=0; j<n; j++)
      if (!vis[j] && dis[j] < mindis)
        mindis = dis[idx=j];
    vis[idx] = true;
    for (int j=0; j<n; j++) if (!vis[j]) {
      int d = j < idx ? graph[j][idx] : graph[idx][j];
      int c = j > idx ? graph[j][idx] : graph[idx][j];
      if (dis[j] > dis[idx] + d) {
        dis[j] = dis[idx] + d;
        cost[j] = cost[path[j]=idx] + c;
      } else if (dis[j] == dis[idx] + d 
                && cost[j] > cost[idx] + c)
        cost[j] = cost[path[j]=idx] + c;
    }
  }
  ansdist = dis[d];
  anscost = cost[d];
}
void print_path(int d) {
  if (path[d] != d)
    print_path(path[d]);
  printf("%d ", d);
}

int main() {
  memset(graph, INF, sizeof(graph));
  int n, m, s, d; scanf("%d%d%d%d", &n, &m, &s, &d);
  while (m--) {
    int x, y, d, c; scanf("%d%d%d%d", &x, &y, &d, &c);
    /* Assure x<y, Let graph[x][y]=d, graph[y][x]=c, aka.
        Upper Triangle => Distance
        Lower Traingle => Cost     */
    if (x > y) x ^= y ^= x ^= y;
    graph[x][y] = d; graph[y][x] = c;
  }

  dijkstra(n, s, d);
  print_path(d); printf("%d %d", ansdist, anscost);
}