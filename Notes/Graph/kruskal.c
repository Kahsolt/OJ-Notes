#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100   // vertex num
#define M 500   // edge num

// 2018-08-02
// Kruskal：解决最小生成树，每次选最小边，合并一棵树
// *Boruvka：更古老的算法，每次选若干条最小边，合并一个森林

typedef struct edge {
  int x, y;
  int v;
} Edge;
Edge edges[M];
int cmp(const void* a, const void* b) { // '<'
  return ((Edge*)a)->v - ((Edge*)b)->v;
}

int set[N];
static inline int root(int x) {
  return set[x] != x ? set[x] = root(set[x]) : x;
}

int kruskal(int n, int m) {
  for(int i=0; i<=n; i++) set[i] = i;
  qsort(edges, m, sizeof(Edge), cmp);

  int ans = 0, p = 0;  // pick from edge-0
  n--;  // just need n-1 edge
  while (n && p<m) {
    int rx = root(edges[p].x);
    int ry = root(edges[p].y);
    if (rx != ry) {
      set[rx] = ry;
      ans += edges[p].v;
      n--;
    }
    p++;
  }
  return (!n) ? ans : -1; // -1 if not connected
}
void go(int n, int m) {
  srand(time(NULL));
	for (int i=0; i<m; i++) {
		edges[i].x = rand() % n;
		edges[i].y = rand() % n;
		edges[i].v = rand() % 100;
	}
	printf("MST = %d\n", kruskal(n, m));
}

int main() {
  go(3, 2);
  go(5, 10);
  go(7, 25);
  go(10, 50);
}