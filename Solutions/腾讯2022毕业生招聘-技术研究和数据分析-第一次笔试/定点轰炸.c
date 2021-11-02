#include <stdio.h>
#define MAXN 10000

/*
3
0 0 0
0 0 1
0 1 1
6
0 1 0 0 1 0
1 0 1 1 0 1
0 1 0 0 1 0
0 1 0 0 1 0
1 0 1 1 0 1
0 1 0 0 1 0
*/

int n;
char m[MAXN][MAXN] = { 0 };
int dx[] = {0, 0, 1, -1},
    dy[] = {1, -1, 0, 0};

static inline int chk(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

void dfs(int x, int y) {
  m[x][y] = 3;                 // mark bad
  for (int d=0; d<4; d++) {
    int nx = x + dx[d],
        ny = y + dy[d];
    if (chk(nx, ny) && m[nx][ny] == 0)
      dfs(nx, ny);
  }
}

int main() {
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      scanf("%d", &m[i][j]);

  for (int i=0; i<n; i++) {
    if (m[0][i] == 0)   dfs(0, i);
    if (m[i][0] == 0)   dfs(i, 0);
    if (m[n-1][i] == 0) dfs(n-1, i);
    if (m[i][n-1] == 0) dfs(i, n-1);
  }

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (m[i][j] == 0) m[i][j] = 2;

  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
      if (m[i][j] == 3) m[i][j] = 0;

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++)
      printf("%d ", m[i][j]);
    putchar(10);
  }
}