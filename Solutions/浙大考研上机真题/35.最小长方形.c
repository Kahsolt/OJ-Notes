#include <stdio.h>
#define INF 0x7fffffff

int main() {
  int Xmax = -INF, Xmin = INF, Ymax = -INF, Ymin = INF;
  int cnt = 0;
  int x, y; while (~scanf("%d%d", &x, &y)) {
    if (!x && !y) {
      if (!cnt) break;
      printf("%d %d %d %d\n", Xmin, Ymin, Xmax, Ymax);
      Xmax = Ymax = -INF; Xmin = Ymin = INF;
      cnt = 0;
    } else {
      if (x < Xmin) Xmin = x; if (x > Xmax) Xmax = x;
      if (y < Ymin) Ymin = y; if (y > Ymax) Ymax = y;
      cnt++;
    }
  }
}