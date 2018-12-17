#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define min(a, b) (((a)<=(b))?(a):(b))
#define N 1000+1
#define M 1000*999
/* Battle Over Cities (25) */

#define METHOD1

#ifdef METHOD1  // tarjan
typedef struct edge {
  int to;
  struct edge* next;
} Edge;
Edge edges[M], *edges_cnt = edges, *head[N] = { NULL };
static inline void add_edge(int from, int to) {
  edges_cnt->to = to;
  edges_cnt->next = head[from];
  head[from] = edges_cnt++;
}
int dfn[N] = { 0 }, low[N], dfn_cnt = 0;
int subnets[N] = { 0 }; // already baised
int parent[N] = { 0 };  // record parent in the search tree
void tarjan(int u) {
  dfn[u] = low[u] = ++dfn_cnt;  // allocate dfn
  int child_cnt = 0;
  for (Edge* e=head[u]; e; e=e->next) {
    int v = e->to;
    if (!dfn[v]) {
      if (!parent[u]) child_cnt++; parent[v] = u;
      tarjan(v);
      low[u] = min(low[u], low[v]);
      // if u is not root and low[v] did not decrease under dfn[u]
      // or u is root and has more than two children
      if (parent[u] && low[v]>=dfn[u]
          || !parent[u] && child_cnt>=2)
        subnets[u]++; // u is a cutting point
    } else if (v != parent[u])  // (u, v) is a back edge, and v is not father of u
      low[u] = min(low[u], dfn[v]);
  }
}
int main() {
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  while (m--) {
    int x, y; scanf("%d%d", &x, &y);
    add_edge(x, y); add_edge(y, x);
  }

  for (int i=1; i<=n; i++)
    if(!dfn[i]) tarjan(i);

  while (k--) {
    int z; scanf("%d", &z);
    printf("%d\n", subnets[z]);
  }
}
#endif

#ifdef METHOD2  // brute-force dfs
bool graph[N+1][N+1], visit[N+1];
void dfs(int cur, int n) {
  visit[cur] = true; 
  for (int i=1; i<=n; i++)
    if (!visit[i] && graph[cur][i])
      dfs(i, n);
}
int main() {
  memset(graph, false, sizeof(graph));
  int n, m, k; scanf("%d%d%d", &n, &m, &k);
  while (m--) {
    int x, y; scanf("%d%d", &x, &y);
    graph[x][y] = graph[y][x] = true;
  }
  
  while (k--) {
    int z; scanf("%d", &z);
    memset(visit, false, sizeof(visit));
    visit[z] = true;  /* mark unavailable */
    int cnt = -1; /* magic offset for ans */
    for (int i=1; i<=n; i++)  /* brute-force dfs for connective componet */
      if (!visit[i])
        { cnt++; dfs(i, n); }
    printf("%d\n", cnt);
  }
}
#endif