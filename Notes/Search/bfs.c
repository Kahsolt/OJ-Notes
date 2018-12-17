#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#define N 100

// 2018/08/09

bool graph[N][N];
bool visit[N];
int n;  // fact nodes number

void bfs() {
  int* queue = malloc(n * sizeof(int)), head = 0, rear = 0;
  memset(visit, false, sizeof(visit));
  queue[head++] = 0;
  visit[0] = true;

  while (head != rear) {
    int i = queue[rear];
    rear = (rear + 1) % n;
    printf("%d ", i);
    for (int j=0; j<n;j++)
      if (!visit[j] && graph[i][j]) {
        visit[j] = true;
        queue[head] = j;
        head = (head + 1) % n;
      }
  }

  free(queue);
}

#define add_edge(x, y) \
  {graph[x][y] = graph[y][x] = true;}

int main() {
  memset(graph, false, sizeof(graph));

  add_edge(0, 1);
  add_edge(0, 3);
  add_edge(1, 2);
  add_edge(1, 3);
  n = 4;
  bfs();
}