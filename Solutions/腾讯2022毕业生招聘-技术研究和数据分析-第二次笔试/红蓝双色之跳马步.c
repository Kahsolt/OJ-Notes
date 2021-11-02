#include <stdio.h>
#include <math.h>
#define MAXN 1001

/*
3 3
bbb
bbb
rbr
1 2
*/

typedef struct point {
  int x, y;
} Point;

int n, m, x, y;
char map[MAXN][MAXN] = { 0 }, vis[MAXN][MAXN] = { 0 };
Point stack[MAXN*MAXN];
int top = -1;
int ans = 0;
int dx[] = {-2,-2,-1,-1,+1,+1,+2,+2},
    dy[] = {-1,+1,-2,+2,-2,+2,-1,+1};

static inline int chk(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

void dfs(int x, int y) {
  top++; stack[top].x = x, stack[top].y = y;

  while (top != -1) {
    int x = stack[top].x, y = stack[top].y; top--;
    
    for (int d=0; d<8; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (!vis[nx][ny] && chk(nx, ny) && map[x][y] != map[nx][ny]) {
        vis[nx][ny] = 1; ans++;
        top++; stack[top].x = nx, stack[top].y = ny;
      }
    }
  }
}

void dfs_rec(int x, int y) {
  for (int d=0; d<8; d++) {
    int nx = x + dx[d], ny = y + dy[d];
    if (!vis[nx][ny] && chk(nx, ny) && map[x][y] != map[nx][ny]) {
      vis[nx][ny] = 1; ans++;
      dfs_rec(nx, ny);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m); getchar();
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++)
      map[i][j] = getchar();
    getchar();
  }
  scanf("%d%d", &x, &y);
  
  vis[x][y] = 1; ans++;


  dfs(x, y);
/*
  dfs_rec(x, y);
*/
  printf("%d\n", ans);
}

