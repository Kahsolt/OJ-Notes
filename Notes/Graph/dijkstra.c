#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 100   // vertex num
#define M 500   // edge num
#define INF 0x3F3F3F3F

int graph[N][N];
int dis[N], path[N], cnt[N];

void dijkstra(int n, int S)	{ // no negtive edge
	int vis[n]; memset(vis, false, sizeof(vis));
	for (int i=0; i<n; i++) {
	  dis[i] = graph[path[i]=S][i];
		cnt[i] = graph[S][i] == INF ? 0 : 1;
	}
	dis[S] = 0; vis[S] = true;

	for (int t=n-1; t>0; t--) {	// n-1 vertex to consider
		int mindis = INT_MAX, idx = -1;
		for (int j=0; j<n; j++)
		  if (!vis[j] && dis[j] < mindis)
			  mindis = dis[idx=j];
		vis[idx] = true;				// find nearest vertex
		for (int j=0; j<n; j++)	// update any triangle
		  if (!vis[j])
				if (dis[j] > dis[idx] + graph[idx][j]) {
				  dis[j] = dis[idx] + graph[idx][j];
					cnt[j] = cnt[idx];	// replace
					path[j] = idx;			// detour to idx then j
				} else if (dis[j] == dis[idx] + graph[idx][j])
					cnt[j] += cnt[idx];	// add up
	}
}
void print_path(int D) {
	if (path[D] != D)
		print_path(path[D]);	// detour to path[D]
	printf("%d ", D);				// now go D
}
void go(int n, int m, int S, int edges[][3]) {
	memset(graph, INF, sizeof(graph));
	for (int i=0; i<m; i++)
		graph[edges[i][0]][edges[i][1]] 
		 	= graph[edges[i][1]][edges[i][0]]
		  = edges[i][2];
	dijkstra(n, S);
	for (int i=0; i<n; i++) {
		printf("[%d]->[%d]: ", S, i);
		print_path(i); printf("\n");
	}
	puts("========================");
}

int main() {
	int n, S;

	int edges[7][3] = {
		{0, 2, 10},
		{0, 4, 2},
		{1, 2, 5},
		{1, 3, 1},
		{2, 3, 2},
		{4, 1, 1},
		{4, 3, 3},
	};
	go(5, 7, 2, edges);
	
	int edges2[3][3] = {
		{2, 0, 3},
		{2, 1, 2},
		{2, 3, 1},
	};
	go(4, 3, 1, edges2);

	return 0;
}