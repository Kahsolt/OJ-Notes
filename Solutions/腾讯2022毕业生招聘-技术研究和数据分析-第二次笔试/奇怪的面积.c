#include <stdio.h>
#include <math.h>
#define N 1e6
#define EPS 1e-6
#define min(a, b) (a<=b?a:b)

int main() {
  int k, b; scanf("%d%d", &k, &b);

  double dx = (double) b / N;
  //printf("dx = %lf\n", dx);

  double ans = 0.0;
  for (double  x=0; x<b; x+=dx) {
    double y1 = pow(x, k),
           y2 = b - x;
    ans += min(y1, y2) * dx;
  }

  printf("%.10lf\n", ans);
}

