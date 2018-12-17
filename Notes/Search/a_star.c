#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#define N 100
#define DIRECTIONS 4   // four direction choices

// 2018/08/09
// 基于DFS，选择估价最小的方向优先前进
//   估价函数 f() = h() + g()
//     h()为起点到当前点的代价估计，一般是当前行进步数dfn
//     g()为当前点到终点的代价估计，比如到终点的欧几里得/曼哈顿距离
//

int Sx, Sy, Tx, Ty, step;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}; // DIRECTIONS
int n = 5, m = 8; // graph[n][m]
char graph[N][N] = {
  ".S.#....",
  ".#.....#",
  "......#T",
  "....#...",
  "..#.....",
};
int h[N][N];  // h() for graph[i][j]
bool visit[N][N], found;
typedef struct step { // aux strcut representing next search step
  int x, y;
  int f;  // g() is the same, so f() equals to h()
} Step;
int cmp(const void* a, const void* b) { // '<'
  return ((Step*)a)->f - ((Step*)b)->f;
}

void print_graph(int x, int y) {
  step++;
  for (int i=0; i<n; i++) {
    printf("  ");
    for (int j=0; j<m; j++)
      printf("%c", i==x&&j==y ? 'o' : graph[i][j]);
    puts("");
  }
  for (int i=0; i<m+4; i++) putchar('-'); putchar('\n');
  Sleep(300);
}

void a_star(int x, int y) {
  print_graph(x, y);
  if (graph[x][y] == 'T') { found = true; return; }

  Step steps[DIRECTIONS];
  int step_cnt = 0;
  for (int k=0; k<DIRECTIONS; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (!visit[xx][yy] && graph[xx][yy]!='#' 
        && 0<=xx && xx<n && 0<=yy && yy<m) {
      steps[step_cnt].x = xx;
      steps[step_cnt].y = yy;
      steps[step_cnt].f = h[xx][yy];
      step_cnt++;
    }
  }
  qsort(steps, step_cnt, sizeof(Step), cmp); // sort according to f()
  for (int t=0; t<step_cnt; t++) {
    int x = steps[t].x;
    int y = steps[t].y;
    visit[x][y] = true;
    a_star(x, y);
    if (found) return;
    visit[x][y] = false;
  }
}

void dfs(int x, int y) {
  print_graph(x, y);
  step++;
  if (graph[x][y] == 'T') { found = true; return; }

  Step steps[DIRECTIONS];
  int step_cnt = 0;
  for (int k=0; k<DIRECTIONS; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (!visit[xx][yy] && graph[xx][yy]!='#' 
        && 0<=xx && xx<n && 0<=yy && yy<m) {
      steps[step_cnt].x = xx;
      steps[step_cnt].y = yy;
      step_cnt++;
    }
  }
  for (int p=1; p<step_cnt; p++) {  // random shuffle steps
    int t = rand() % p;
    steps[p].x ^= steps[t].x ^= steps[p].x ^= steps[t].x; 
    steps[p].y ^= steps[t].y ^= steps[p].y ^= steps[t].y; 
  }
  for (int t=0; t<step_cnt; t++) {
    int x = steps[t].x;
    int y = steps[t].y;
    visit[x][y] = true;
    dfs(x, y);
    if (found) return;
    visit[x][y] = false;
  }
}

int main() {
  srand(time(NULL));
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      if (graph[i][j] == 'S') { Sx = i; Sy = j;}
      else if (graph[i][j] == 'T') { Tx = i; Ty = j;}
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
     h[i][j] = abs(i-Tx) + abs(j-Ty);

  memset(visit, false, sizeof(visit));
  found = false; step = 0;
  puts("[a_star]");
  a_star(Sx, Sy);
  printf("a_star: %d", step);
  putchar('\n');

  memset(visit, false, sizeof(visit));
  found = false; step = 0;
  puts("[dfs]");
  dfs(Sx, Sy);
  printf("dfs: %d", step);
  putchar('\n');
}