// 2021/10/11 

int dx[] = {0,0,1,-1},
    dy[] = {1,-1,0,0};

inline int chk(int N, int M, int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

void dfs(int **A, int N, int M, int x, int y, int id) {
  int sx[10000], sy[10000], top = -1;
  top++, sx[top] = x, sy[top] = y;
  while (top != -1) {
    int x = sx[top], y = sy[top]; top--;
    A[x][y] = 0;
    for (int d=0; d<4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (chk(N, M, nx, ny) && A[nx][ny] == id)
        top++, sx[top] = nx, sy[top] = ny;
    }
  }
}

int solution(int **A, int N, int M) {
  int r = 0;
  for (int i=0; i<N; i++)
    for (int j=0; j<M; j++)
      if (A[i][j]) {
        dfs(A, N, M, i, j, A[i][j]);
        r++;
      }
  return r;
}

