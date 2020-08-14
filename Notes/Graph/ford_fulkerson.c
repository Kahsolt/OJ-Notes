#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#define N 100   // vertex num
#define M 500   // edge num

// 2018/08/08
// 求解网络最大流
// 
// ford_fulkerson：从源点开始DFS灌水一直流到汇点，可以把该路径上最小水管容量的水送到汇点，
//   把该容量加入结果值，然后该路径上的水管全部减小这个值；重复，直到无水可到汇点
//   （注意构造反向边，表示可以反悔）

typedef struct edge {
  int to;
  int cap;           // 边剩余容量
  struct edge* rev;  // 反向边引用
  struct edge* next;
} Edge;
Edge edges[M<<1], *edge_cur = edges, *head[N] = { NULL };
static inline void add_edge(int from, int to, int cap) {  // double side
  edge_cur->to = to;
  edge_cur->cap = cap;
  edge_cur->rev = edge_cur + 1; // 其反向边为下一条
  edge_cur->next = head[from];
  head[from] = edge_cur++;

  edge_cur->to = from;        // 反向边
  edge_cur->cap = 0;          // 默认可回退0
  edge_cur->rev = edge_cur - 1; // 其反向边为上一条
  edge_cur->next = head[to];
  head[to] = edge_cur++;
}

bool visit[N]; // mark node visit in each iteration
int dfs(int v, int t, int f) {  // v: current vertex that approaching t
  if (v == t) return f;         // reached DST
  visit[v] = true;
  for (Edge* e=head[v]; e; e=e->next)
    if (!visit[e->to] && e->cap>0) { // 该水管还没流经 且 还可以通过一定容量的水
      // 带着流量通过该水管：取传来的流量f或流经的该边上限e->cap的较小值
      int d = dfs(e->to, t, __min(f, e->cap));
      if (d > 0) {          // 该路径可以增加流量d
        e->cap -= d;        // 占用d的流量，减小水管
        e->rev->cap += d;   // 反向边表示可以回退的流量，增加d
        return d;           // 见好就收、跳出for循环
      }
    }
  return 0;
}
int ford_fulkerson(int s, int t) {  // wrapper for dfs()
  int flow = 0, f = 0;
  do {
    memset(visit, false, sizeof(visit));
    f = dfs(s, t, INT_MAX);   // 给源点无限水源INT_MAX
    flow += f;
  } while (f);
  return flow;
}

int main() {
  int n = 6, m = 8, s = 0, t = 5;
  int edge[8][3] = {  // 经典的两行交叉网络(ans=16)
    {0, 1, 10}, {0, 3, 10},
    {1, 2, 9},  {1, 4, 5},
    {3, 2, 15}, {3, 4, 7},
    {2, 5, 7},  {4, 5, 9},
  };
  memset(head, 0x00, sizeof(head));
  while (m--) add_edge(edge[m][0], edge[m][1], edge[m][2]);
  printf("Max Flow = %d\n", ford_fulkerson(s, t));
  puts("============================");

  srand(time(NULL));
  n = rand() % (N - 5)+ 5;
  m = n << 2;
  edge_cur = edges; memset(head, 0x00, sizeof(head)); // reset
  printf("[Network] n=%d m=%d\n", n, m);
  while (m--) add_edge(rand() % N, rand() % N, rand() % 100);
  int r = rand() % 10 + 1;
  while (r--) {
    s = rand() % N;
    t = rand() % N;
    printf("Max Flow (%d, %d) = %d\n",
      s, t, ford_fulkerson(s, t));
  }
}