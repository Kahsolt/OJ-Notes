#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#define N 100
#define M 500

// 2018/08/06
// Topo sort
//

bool graph[N][N];
int indeg[N];

bool kahn(int n) {
	int stack[n], top = -1; // either stack or queue is ok
	for (int i=0; i<n; i++)
		if (!indeg[i])
			stack[++top] = i;

	int cnt = 0;
	while (top != -1) {
		int v = stack[top--];
		printf("%d ", v); cnt++;
		for (int u=0; u<n; u++)
		  if (graph[v][u] && !--indeg[u])
				stack[++top] = u;
	}
  return cnt == n;
}
bool kahn_queue(int n) {
  int queue[N], head = 0, rear = 0;
  for (int i=0; i<n; i++)
    if (!indeg[i]) {
      queue[head] = i;
      head = (head + 1) % N;
    }
  
  int cnt = 0;  // count nodes that are sorted
  while (head != rear) {
    int from = queue[rear];
    rear = (rear + 1) % N;
    printf("%d ", from); cnt++;
    for (int to=0; to<n; to++)
      if (graph[from][to] && !--indeg[to]) {
        queue[head] = to;
        head = (head + 1) % N;
      }
  }
  return cnt == n;
}

void go(int n, int m) {
	memset(graph, false, sizeof(graph));
	memset(indeg, 0x00, sizeof(indeg));
	for (int i=0; i<m; i++) {
		int x = rand() % n;
		int y = rand() % n;
		graph[x][y] = true;
		indeg[y]++;
	}
  puts(kahn(n) ? "Yes" : "No");
}

int main() {
	srand(time(NULL));

  // undirected graph
	int t = rand() % 5 + 1;
	while (t--) {
		int n = rand() % 10 + 1;
		int m = n + 1;
		go(n, m);
	}
  putchar(10);

  // directed graph
	memset(graph, false, sizeof(graph));
	memset(indeg, 0x00, sizeof(indeg));
  int n = 5;
  #define add_edge(x, y) \
    graph[x][y] = true; indeg[y]++;
  add_edge(1, 3); add_edge(1, 4);
  add_edge(2, 3); add_edge(3, 0);
  add_edge(3, 4); add_edge(4, 0);
  puts(kahn_queue(n) ? "Yes" : "No");
}