#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 100000

int main() {
  int n, m; scanf("%d%d", &n, &m);

  int E = 0;
  for (int t=0; t<N; t++) {
    int x = n, y = m;
    int e = 0;
    while (y > 0) {
      double r = (double) rand() / RAND_MAX;
      if (r < (double) y / (x + y)) {
        e += 2;
        y--;
      } else e++;
    }
    E += e;
  }

  printf("%.2lf\n", (double) E / N);
}

