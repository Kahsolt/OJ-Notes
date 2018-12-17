#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 1000
/* Forwards on Weibo (30) */

#define METHOD1

#ifdef METHOD1  /* BFS + save edge */
typedef struct edge {
  int to;
  struct edge* next;
} Edge;
Edge edges[N*(N-1)], *edges_cur = edges, *head[N+1] = { NULL };
void add_edge(int from, int to) {
  edges_cur->to = to;
  edges_cur->next = head[from];
  head[from] = edges_cur++;
}

bool visit[N+1];
void bfs(int n, int cur, int depth) {
  typedef struct queue_node {
    int cur;    // id
    int dep;  // depth allow
  } QNode;
  QNode queue[N];
  int q_head = 0, q_rear = 0;
  queue[q_head].cur = cur;
  queue[q_head].dep = depth;
  q_head++;
  visit[cur] = true;

  while (q_head != q_rear) {
    int cur = queue[q_rear].cur;
    int dep = queue[q_rear].dep;
    q_rear = (q_rear + 1) % N;
    if (dep) for (Edge* e=head[cur]; e; e=e->next)
      if (!visit[e->to]) {
        visit[e->to] = true;
        queue[q_head].cur = e->to;
        queue[q_head].dep = dep-1;
        q_head = (q_head + 1) % N;
      }
  }
}

int main() {
  read(n); read(l); forp(i, 1, n) {
    read(k); times(k) {
      read(j); if (i != j) add_edge(j, i);
    }
  }
  read(k); times(k) {
    read(q); mset(visit, false);
    bfs(n, q, l);
    int cnt = 0;
    forp(i, 1, n) if (visit[i]) cnt++;
    prti(cnt-1), prtl();
  }
}
#endif

#ifdef METHOD2  /* DFS + save graph (TLE) */
bool follow[N+1][N+1] = { false };
int follow_cnt[N+1] = { 0 };
bool visit[N+1];
void dfs(int n, int cur, int depth) {
  visit[cur] = true;
  int vis_cnt = follow_cnt[cur];
  if (depth) for (int i=1; vis_cnt && i<=n; i++)
    if (i!=cur && follow[cur][i]) {
      dfs(n, i, depth-1);
      vis_cnt--;
    }
}

int main() {
  read(n); read(l); forp(i, 1, n) {
    read(k); times(k) {
      read(j); follow_cnt[j]++;
      follow[j][i] = true;
    }
  }
  read(k); times(k) {
    read(q); mset(visit, false);
    dfs(n, q, l);
    int cnt = 0;
    forp(i, 1, n) if (visit[i]) cnt++;
    prti(cnt-1), prtl();
  }
}
#endif