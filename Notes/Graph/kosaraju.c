#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#define prta(x, a, b) \
  printf("[%3s]: ", ""#x""); \
  for (int i=a; i<=b; i++) \
    printf("%d ", x[i]); \
  putchar('\n');
#define N (100+1)
#define M 500

// 2018/08/25
// Kosaraju思想：正图搜索、给各点编号dfn，反图搜索、SSC计数
//   原理：如果G的子图G'是强连通的，则将G的各边反向后，G'应该仍然强连通
//

typedef struct edge {
  int to;
  struct edge* next;
} Edge;
Edge edges[M<<1], *edge_cur = edges;
Edge *head[N] = { NULL }, *invhead[N] = { NULL };
static inline void add_edge(int from, int to) { // double side
  edge_cur->to = to;      // 正图
  edge_cur->next = head[from];
  head[from] = edge_cur++;

  edge_cur->to = from;    // 反图
  edge_cur->next = invhead[to];
  invhead[to] = edge_cur++;
}

int dfn[N] = { 0 }, dfn_cnt = 0;  // dfn: 1~n; mapping vertex-id => dfn
int id[N];  // mapping dfn => vertex-id
void dfs(int u) {
  dfn[u] = -1;  // alloc dummy dfn, just mark visit
  for (Edge* e=head[u]; e; e=e->next)
    if (!dfn[e->to]) dfs(e->to);    // if dfn not visited
  ++dfn_cnt;  // alloc real dfn (post dfs())
  dfn[id[dfn_cnt] = u] = dfn_cnt;
}
void invdfs(int u) {
  dfn[u] = 0;  // clear dfn
  printf(" %d", u);
  for (Edge* e=invhead[u]; e; e=e->next)
    if (dfn[e->to]) invdfs(e->to);  // if dfn not cleared
}
int kosaraju(int n) {
  for (int i=1; i<=n; i++)
    if (!dfn[i]) dfs(i);  // if not visited

  prta(dfn, 1, n);
  prta(id, 1, n);

  int cnt = 0;
  for (int i=n; i>=1; i--) // by decreasing order of dfn
    if (dfn[id[i]]) {
      printf(">>"); invdfs(id[i]); putchar('\n');
      cnt++;
    }
  return cnt;
}

int main() {
  int n = 6, m = 8;
  int edges[8][2] = {
    {1, 2}, {1, 4},
    {2, 3}, {2, 5},
    {3, 6}, {4, 5},
    {5, 1}, {5, 6},
  };
  for (int i=0; i<m; i++)
    add_edge(edges[i][0], edges[i][1]); // bias adjust

  printf("SCC cnt = %d\n", kosaraju(n));
}