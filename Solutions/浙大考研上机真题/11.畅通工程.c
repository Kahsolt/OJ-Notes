#include <stdio.h>
#define N 1001

int set[N];
int root(int x) { return set[x]!=x ? set[x]=root(set[x]) : x; }
int main() {
  int n; while (~scanf("%d", &n)) {
    if (!n) break;
    int m; scanf("%d", &m);

    for (int i=1; i<=n; i++) set[i] = i;
    while (m--) {
      int x, y; scanf("%d%d", &x, &y);
      set[root(x)] = root(y);
    }
    int cnt = 0;
    for (int i=1; i<=N; i++)
      if (root(i) == i) cnt++;
    printf("%d\n", cnt - 1);
  }
}
