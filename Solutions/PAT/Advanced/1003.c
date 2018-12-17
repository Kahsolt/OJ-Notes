#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define min(a,b) (((a)<=(b))?(a):(b))
#define MAXN 500
#define INF 0x3F3F3F3F
/* Emergency (25) */

int N, M, C1, C2;
int graph[MAXN][MAXN], weight[MAXN];  /* the weight of vertexes */

bool vis[MAXN];
int dis[MAXN], cnt[MAXN], w[MAXN];
void djikstra() {
  memset(vis, false, sizeof(vis)); 
  for (int i=0; i<N; i++) {
    dis[i] = graph[C1][i];
    cnt[i] = dis[i]!=INF ? 1 : 0;
    /* current weight of vertex-i during, shoud plus source weight[C1] */
    w[i] = weight[C1] + weight[i];
  }
  vis[C1] = true; dis[C1] = 0; cnt[C1] = 1;

  for (int t=1; t<N; t++) { /* N-1 rounds */
    int idx = -1, mindis = INF; /* find nearest */
    for (int i=0; i<N; i++)
      if (!vis[i] && mindis > dis[i])
        mindis = dis[idx=i];
    vis[idx] = true;

    for (int j=0; j<N; j++) /* detour */
      if (!vis[j])
        if (dis[j] > dis[idx] + graph[idx][j]) {
          dis[j] = dis[idx] + graph[idx][j];
          cnt[j] = cnt[idx];    /* replace if found shorter path */
          w[j] = w[idx] + weight[j]; /* replace */
        } else if (dis[j] == dis[idx] + graph[idx][j]) {
          cnt[j] += cnt[idx];   /* add path count */
          if (w[j] < w[idx] + weight[j]) /* update if larger */
            w[j] = w[idx] + weight[j];
        }
  }
  printf("%d %d", cnt[C2], w[C2]);
}
int main() {
  scanf("%d%d%d%d", &N, &M, &C1, &C2);
  for (int i=0; i<N; i++) scanf("%d", &weight[i]);
  memset(graph, INF, sizeof(graph));
  for (int i=0; i<M; i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    graph[y][x] = graph[x][y] = v;    /* FIXME?: no consider replicate arc */
  }
  djikstra();
}