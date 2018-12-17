#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100   // vertex num
#define M 500   // edge num
#define INF 0x3F3F3F3F

// 2018-08-02

int graph[N][N], path[N][N];
void floyd(int n) { /* no negetive circle */
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      path[i][j] == graph[i][j]!=INF ? i : -1;

  for (int k=0; k<n; k++) // the detour vertex
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
        if (k==i || k==j || i==j) continue;
        else {
  				graph[i][j] = __min(graph[i][j], graph[i][k] + graph[k][j]);
          path[i][j] = path[k][j];  // from i detour to k then go j
        }
}
void go(int n, int m) {
  memset(graph, INF, sizeof(graph));
	for (int i=0; i<m; i++) {
		int x = rand() % n;
		int y = rand() % n;
		graph[x][y] = graph[y][x] = rand() % 100;
	}
	floyd(n);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			printf("%3d ", graph[i][j]==INF ? -1 : graph[i][j]);
    putchar(10);
	}
	puts("============================");
}

int main() {
	srand(time(NULL));

	go(4, 3);
	go(4, 6);
	go(6, 10);
}