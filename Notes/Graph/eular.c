#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 100   // vertex num
#define M 500   // edge num

// 2018/08/08
// 欧拉(回)路存在条件：
//   0.图连通
//   无向图：
//     1.所有顶点度数为偶，有欧拉回路；从任意顶点出发
//     2.仅有两个顶点度数为奇，有欧拉路；从任意奇度顶点出发
//   有向图：
//     1.所有顶点入度等于出度，有欧拉回路；从任意顶点出发
//     2.仅有一个顶点入度比出度大1、一个顶点出度比入度大1；从出度大1的顶点出发
// 欧拉笔画数：
//   无向图，需要笔画数 = min(1, 奇度顶点数/2)
//   有向图：枚举，每次dfs减去对应的度，直到空图
//
// *Fleury算法：优先走不是桥的边，减少dfs的回溯
//

typedef struct edge {
  int id;   // for visit marking
  int to;
  struct edge* next;
} Edge;
Edge edges[M], *edge_cur = edges, *head[N]; // linking forward star
int degree_in[N], degree_out[N];
void add_edge(int from, int to) {
  edge_cur->id = edge_cur - edges;
  edge_cur->to = to;
  edge_cur->next = head[from];
  head[from] = edge_cur++;

  degree_out[from]++;
  degree_in[to]++;
}
int S = 0, T = 0;     // start/terminal, default vertex-0
void init_ST(int n) { // find S and T
  while (n--)
    if (degree_in[n] == degree_out[n] + 1) T = n;
    else if (degree_out[n] == degree_in[n] + 1) S = n;
}

bool via[M];  // mark edges that vias
int path[M], path_cur = -1;
void dfs(int u) {
  path[++path_cur] = u; // append vertex to ans 
  for (Edge* e=head[u]; e; e=e->next) {
    int id = e->id;
    if (!via[id]) {
      via[id] = true;
      dfs(e->to);
    }
  }
}
void eular(int n) {  // wrapper for dfs(), 略去了连通性判断
  memset(via, false, sizeof(via));
  memset(path, 0xFF, sizeof(path));
  init_ST(n);
  if (S == T) puts("Eular Circuit:");
  else puts("Eular Path:");
  dfs(S);
}
void print_eular() {
  for (int i=0; i<=path_cur; i++)
    printf("%d ", path[i]);
  puts("");
}

void go(int n, int m, int edge[][2]) {
  memset(head, 0x00, sizeof(head));           // default NULL
  memset(degree_in, 0x00, sizeof(degree_in)); // default 0
  memset(degree_out, 0x00, sizeof(degree_out));
  edge_cur = edges; path_cur = -1; S = T = 0;

  while (m--)
    add_edge(edge[m][0], edge[m][1]);
  eular(n); print_eular();
}

int main() {
  int n, m;
  
  n = 5, m = 15;
  int edges[][2] = {  // 画一个带框五角星
    {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0},
    {0, 2}, {2, 4}, {4, 1}, {1, 3}, {3, 0},
    {0, 4}, {4, 3}, {3, 2}, {2, 1}, {1, 0},
  };
  go(n, m, edges);

  n = 4, m = 6;
  int edges2[][2] = {
    {0, 1}, {1, 2}, {2, 1}, 
    {1, 0}, {0, 3}, {3, 1}
  };
  go(n, m, edges2);

  n = 4, m = 5;
  int edges3[][2] = {
    {0, 1}, {1, 2}, {2, 1}, 
    {2, 3}, {3, 2},
  };
  go(n, m, edges3);
}