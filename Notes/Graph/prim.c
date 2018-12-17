#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <time.h>
#define N 100   // vertex num
#define M 500   // edge num
#define INF 0x3F3F3F3F

// 2018-08-02
// Prim：解决最小生成树
//   判定MST唯一性：
//     1.标记所有拥有相同权值的边
//     2.第一次Kruskal或Prim求MST值；若未使用这些标记的边，则唯一
//     3.否则，删去使用了的被标记的边，第二次求MST；若MST值不变，则不唯一

int graph[N][N];
int prim(int n) {
  int ans = 0, dis[n];
  for (int i=1; i<n; i++)
    dis[i] = graph[0][i];
  dis[0] = 0;  // put node-0 in MST-tree

  for (int t=1; t<n; t++) {
    int mindis = INF, idx = -1;
    for (int j=0; j<n; j++)
      if (dis[j] && dis[j] < mindis)
        mindis = dis[idx=j];
    if (idx == -1) return -1;  // not connected
    dis[idx] = 0;
		ans += mindis;
		for (int k=0; k<n; k++)
		  if (dis[k] && dis[k] > graph[idx][k])
        dis[k] = graph[idx][k];
  }
  return ans;
}
void go(int n, int m) {
  memset(graph, INF, sizeof(graph));
	for (int i=0; i<m; i++) {
		int x = rand() % n;
		int y = rand() % n;
		graph[x][y] = graph[y][x] = rand() % 100;
	}
	printf("MST = %d\n", prim(n));
}

int main() {
  srand(time(NULL));

  go(3, 2);
  go(5, 10);
  go(7, 25);
  go(10, 50);
}