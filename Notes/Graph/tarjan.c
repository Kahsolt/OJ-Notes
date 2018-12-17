#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#define min(a, b) (((a)<=(b))?(a):(b))
#define prta(x, a, b) \
  printf("["#x"]: "); \
  for (int i=a; i<=b; i++) \
    printf("%d ", x[i]); \
  putchar('\n');
#define N (100+1)
#define M 500

// 2018-08-05
// Tarjan: 求强连通分量SCC、割点Cut、割边Bridge

typedef struct edge { /* linking forward star */
  int to;
  struct edge* next;
} Edge;
// head[]: the pointer to first edge starts from vertex-i in edges
Edge edges[M], *edge_cur = edges, *head[N] = { NULL };
static inline void add_edge(int from, int to) {
  edge_cur->to = to;
  edge_cur->next = head[from];  // insert at list head
  head[from] = edge_cur++;
}
int n, cnt = 0;  // ans

// dfn[] default 0 (no dfn allocated, not visited); low[] aka. lowest_dfn[]
int dfn[N] = { 0 }, low[N], dfn_cnt = 0;
// stack to record scc vertexes
int stack[N], top = -1;
bool stack_has[N] = { false };
// count subnets if remove vertex-i, default should be 1
// subnets[i]+1: if cut vertex-i, the graph will be split into how many parts
int subnets[N] = { 0 };
// record parent in the search tree, filter cases of low[u] = min(low[u], dfn[v]);
int parent[N] = { 0 };

/* 求SCC思想：DFS深搜到底后回退，若该点无回边则砍断 */
void tarjan(int u) {
  dfn[u] = low[u] = ++dfn_cnt;  // allocate dfn: the serial number in dfs search tree
  stack_has[stack[++top]=u] = true;
  for (Edge* e=head[u]; e; e=e->next) { /* try each edge starts from u */
    int v = e->to;
    if (!dfn[v]) { /* v not visited yet, continue dfs() */
      tarjan(v);
      low[u] = min(low[u], low[v]); /* backport update 'u' */
    } else if (stack_has[v])  /* v is visited and in stack */
      low[u] = min(low[u], dfn[v]); /* it's a back edge */
  }

  if (dfn[u] == low[u]) {   /* found a SCC, u is the root */
    int v; cnt++; printf(">>");
    do {
      stack_has[stack[top]] = false;
      v = stack[top--];
      printf(" %d", v);
    } while (v != u);     // pop until u (the root)
    putchar('\n');
  }
}

/* 求割点割边思想：根节点的子树是否多于1、非根节点的low[v]是否降到了dfn[n]以下 */
void tarjan_cutting(int u) {
  dfn[u] = low[u] = ++dfn_cnt;  // allocate dfn
  int root_childcnt = 0;        // used iff 'u' is root
  for (Edge* e=head[u]; e; e=e->next) {
    int v = e->to;
    if (!dfn[v]) {
      if (!parent[u]) root_childcnt++;  // u is root
      parent[v] = u;
      tarjan_cutting(v);
      low[u] = min(low[u], low[v]);
      // if u is not root && low[v] did not decrease under dfn[u]
      // or u is root && has more than two children
      if (parent[u] && low[v]>=dfn[u]
          || !parent[u] && root_childcnt>=2) {  // u is a cutting point
        printf("Cut: %d\n", u);
        subnets[u]++;       // increase the subnets if cut vertex-u
      }
      if (low[v] > dfn[u])  // (u, v) is a cutting edge
        printf("Bridge: (%d, %d)\n", u, v);
    } else if (v != parent[u])  // (u, v) is a non-father-son *back* edge, and v is not father of u
      low[u] = min(low[u], dfn[v]);
  }
}

int main() {
  n = 6; int  m = 8;
  int edges[8][2] = {
    {1, 2}, {1, 4},
    {2, 3}, {2, 5},
    {3, 6}, {4, 5},
    {5, 1}, {5, 6},
  };
  for (int i=0; i<m; i++)
    add_edge(edges[i][0], edges[i][1]);

  for (int i=1; i<=n; i++)    // 一次tarjan不一定遍历完图
    if (!dfn[i]) tarjan(i);   // if not visited
  printf("SCC cnt = %d\n", cnt);

  memset(dfn, 0x00, sizeof(dfn)); dfn_cnt = 0;
  for (int i=1; i<=n; i++) subnets[i] = 1;
  for (int i=1; i<=n; i++)
    if (!dfn[i]) tarjan_cutting(i);
  prta(subnets, 1, n);
}