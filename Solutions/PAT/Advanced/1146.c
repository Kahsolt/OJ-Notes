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
#define M 10000
/* Topological Order (25) */

typedef struct edge {
  int to;
  struct edge* next;
} Edge;
Edge edges[M], *edges_cur = edges, *head[N+1] = { NULL };
void add_edge(int from, int to) {
  edges_cur->to = to;
  edges_cur->next = head[from];
  head[from] = edges_cur++;
}

int indeg[N+1] = { 0 };
int main() {
  read(n); read(m); times(m) {
    read(from); read(to);
    add_edge(from, to);
    indeg[to]++;
  }

  bool prtflag = false;
  read(k); forr(i, 0, k) {
    int id[N+1]; memcpy(id, indeg, (n + 1)*sizeof(int));
    bool ok = true;
    times(n) {
      read(x);
      if (!ok) continue;
      if (!id[x])
        for (Edge* e=head[x]; e; e=e->next)
          id[e->to]--;
      else ok = false;
    }
    if (!ok) {
      if (prtflag) putchar(' ');
      else prtflag = true;
      prti(i);
    }
  }
}