#include <stdio.h>
#include <memory.h>
#define N 1001

int deg[N];
int main() {
  int n; while(~scanf("%d", &n)) {
    if (!n) break;
    memset(deg, 0x00, sizeof(deg));
    int m; scanf("%d", &m);
    while (m--) {
      int x, y; scanf("%d%d", &x, &y);
      deg[x]++; deg[y]++;
    }
    int oddcnt = 0;
    for (int i=0; i<n; i++)
      if (deg[i] & 0x1) oddcnt++;
    putchar(!oddcnt?'1':'0');
  }
}
