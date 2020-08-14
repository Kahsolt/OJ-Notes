#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define MAXN 100000

int axis[MAXN+1];
int dp(int s, int t) {  // TLE
  int ans = abs(t - s);
  if (s < t) {
    memset(axis, 0x3F, sizeof(axis)); axis[s] = 0;
    int flag = 1;
    for (int i=0; i<ans && flag; i++) {
      flag = 0;
      for (int j=0; j<=MAXN; j++) {
        int nextj;
        nextj = j + 1; if (nextj <= MAXN && axis[j] + 1 < axis[nextj]) { axis[nextj] = axis[j] + 1; flag = 1; }
        nextj = j - 1; if (nextj >= 0    && axis[j] + 1 < axis[nextj]) { axis[nextj] = axis[j] + 1; flag = 1; }
        nextj = j * 2; if (nextj <= MAXN && axis[j] + 1 < axis[nextj]) { axis[nextj] = axis[j] + 1; flag = 1; }
      }
    }
    ans = axis[t];
  }
  return ans;
}

int queue[MAXN+1], head = 0, rear = 0;
int visit[MAXN+1] = { 0 }, step[MAXN+1] = { 0 };
static inline void enqueue(int pos) {
  visit[pos] = 1;
  queue[head++] = pos;
}
int bfs(int s, int t) {
  memset(visit, 0x00, sizeof(visit));
  memset(step, 0x00, sizeof(visit));
  head = rear = 0;

  enqueue(s);
  while (head != rear) {
    int pos = queue[rear++];
    if (pos == t) return step[pos];

    int npos;
    npos = pos + 1; if (npos <= MAXN && !visit[npos]) { enqueue(npos); step[npos] = step[pos] + 1; }
    npos = pos - 1; if (npos >= 0    && !visit[npos]) { enqueue(npos); step[npos] = step[pos] + 1; }
    npos = pos * 2; if (npos <= MAXN && !visit[npos]) { enqueue(npos); step[npos] = step[pos] + 1; }
  }
}

#ifdef D
int main() {
  srand(time(NULL));
  while (1) {
    int s = rand() % (MAXN + 1); 
    int t = rand() % (MAXN + 1);
    int ret1 = dp(s, t);
    int ret2 = bfs(s, t);
    if (ret1 != ret2)
      printf("diff on <%d, %d> dp=%d bfs=%d", s, t, ret1, ret2);
    else putchar('.');
  }
}
#else
int main() {
  int s, t;
  while (scanf("%d%d", &s, &t) != EOF)
    printf("%d\n", bfs(s, t));
}
#endif