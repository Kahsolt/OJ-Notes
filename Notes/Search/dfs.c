#include <stdio.h>
#include <stdbool.h>
#define N 100

// 2018/08/09

bool graph[N][N] = { false };
bool visit[N] = { false };
int n;  // nodes number in fact

void dfs(int i) {
  visit[i] = true;
  printf("%d ",i);
  for (int j=0; j<n;j++)
    if (!visit[j] && graph[i][j])
      dfs(j);
  // visit[j] = false; // 根据应用场景确定是否恢复现场
}

int main() {
#define add_edge(x, y) \
  { graph[x][y] = graph[y][x] = true; }
  add_edge(0, 1);
  add_edge(0, 3);
  add_edge(1, 2);
  add_edge(1, 3);

  n = 4;
  dfs(0);
}