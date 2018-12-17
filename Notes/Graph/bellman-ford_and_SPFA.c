#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#include <windows.h>
#define N 10000   // vertex num
#define M 100000  // edge num
#define HINF 0x3F3F3F3F

// 2018-08-02
// Bellman-Ford: 最短路算法，纯粹从边入手；同理可求最长路
// SPFA: optmized version of BF using queue
//   注：也用于解差分约束系统，注意转化三角不等式为有向边，并增加一个虚拟源点x0

typedef struct edge {
  int x, y;
  int v;
} Edge; /* oriented graph, not adjacent presentation */
Edge edges[M];
int dis[N], path[N];

bool bellman_ford(int n, int m, int S) {
  memset(dis, HINF, sizeof(dis));
  for (int i=0; i<n; i++) path[i] = S;
  for (int j=0; j<m; j++)
    if (edges[j].x == S) {
      int y = edges[j].y;
      dis[y] = __min(dis[y], edges[j].v);
    }
  dis[S] = 0; // IMPORTANT!
  
  /* use all egdes to update at most (n-1) times
     on the n-th time, check negetive circle */
  while (n--) {
    bool flag = false;  // if updated in this iteration
    for (int j=0; j<m; j++) {
      int x = edges[j].x;
      int y = edges[j].y;
      int v = edges[j].v;
      if (dis[y] > dis[x] + v) {
        dis[y] = dis[x] + v;
        path[y] = x;  // detour
        flag = true;
      }
    }
    if (!flag) return true;
    else if (!n) return false;  /* n == 0: has negetive circle */
  }
  return true;
}
bool spfa(int n, int m, int S) {  // optimized bellman_ford
  for (int i=0; i<n; i++) path[i] = S;
  memset(dis, HINF, sizeof(dis)); dis[S] = 0;

  /* alike BFS form S
     if encounted vertex updated & not in queue then re-enqueue
     if one vertex enqueued n-times then has negetive circle */  
  size_t q_size = n + 1;        // with one dummy vacancy
  int q[q_size];                // the circle queue (vertex)
  int q_front = 0, q_rear = 0;  // queue cursor
  int q_cnt[n];                 // count enqueue times (should less than n)
  bool q_has[n];                // if vertex is in queue
  memset(q_cnt, 0x00, sizeof(q_cnt));
  memset(q_has, false, sizeof(q_has));
  // initially put S in queue
  q[q_front] = S;
  q_has[S] = true; q_cnt[S] = 1;
  q_front = (q_front + 1) % q_size;

  while (q_front != q_rear) {
    int vex = q[q_rear];
    q_has[vex] = false;
    q_rear = (q_rear + 1) % q_size;

    /* relax each edge that starts from vex */
    for (int j=0; j<m; j++) {
      if (vex != edges[j].x) continue; // TODO: should use adjacent table
      int y = edges[j].y;
      int v = edges[j].v;
      if (dis[y] > dis[vex] + v) {
        dis[y] = dis[vex] + v;
        path[y] = vex;  // detour to vex before y
        if (!q_has[y]) {
          // the nth-enqueue, has negetive circle
          if (q_cnt[y] == n-1) return false;
          // re-enqueue
          q[q_front] = y;
          q_has[y] = true; q_cnt[y] += 1;
          q_front = (q_front + 1) % q_size;
        }
      }
    }
  }
  return true;
}
void print_path(int x) {
  if (path[x] != x)
    print_path(path[x]);
  printf("%d ", x);
}
void prt(int n, int S) {
  if (n > 10) return;

  printf("S:\t%d\n", S);
  printf("dis:\t");
  for (int i=0; i<n; i++)
    printf("%d ", dis[i]==HINF ? -1 : dis[i]);
  printf("\n");
  printf("path:\t");
  for (int i=0; i<n; i++)
    printf("%d ", path[i]);
  printf("\n");

  for (int i=0; i<n; i++) {
    printf("[%d] ", i);
    if (dis[i] != HINF)
      print_path(i);
    printf("\n");
  }
}
int go(int n, int m) {
  int S = rand() % n;
  for (int j=0; j<m ;j++) {
    edges[j].x = rand() % n;
    edges[j].y = rand() % n;
    edges[j].v = rand() % 100;
  }

  clock_t t;
  t = clock();
  bellman_ford(n, m, S);
  printf("bellman_ford: [%d]\n", clock() - t);
  prt(n, S); printf("-----------------------\n");
  t = clock();
  spfa(n, m, S);
  printf("spfa: [%d]\n", clock() - t);
  prt(n, S); printf("=======================\n");
}

int main() {
  srand(time(NULL) + GetCurrentProcessId());

  go(4, 7);
  go(10, 35);

  go(5000, 100);    // sparse graph
  go(5000, 25000);  // dense graph
  go(9500, 1000);
  go(9500, 25000);

  return 0;
}