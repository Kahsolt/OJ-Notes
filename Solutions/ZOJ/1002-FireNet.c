#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 4

char graph[N][N];
bool visit[N][N];
int ans, n, tests;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void dfs(int conf) {
  if (tests == 0) {
    ans = __max(ans, conf);
    return;
  }

  for (int k=0; k<4; k++) {
    int x = 
  }
}

int main() {
  while (~scanf("%d", &n)) {
    tests = n;
    if (n == 0) break; getchar();
    memset(visit, false, sizeof(visit));
    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++) {
        scanf("%c", &graph[i][j]);
        visit[i][j] = true;
        tests--;
      }
      getchar();
    }
    ans = 0;
    dfs(0);
    printf("%d\n", ans);
  }
}