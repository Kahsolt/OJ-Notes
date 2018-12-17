#include <stdio.h>
#include <stdlib.h>
#define read(x) int x; scanf("%d", &x)
#define N 100000
/* Sum of Number Segments (20) */

double x[N];
int main() {
  read(n);
  for (int i=0; i<n; i++)
    scanf("%lf", &x[i]);
  double sum = 0.0f;
  int cnt = n;
  for (int i=0; i<(n+1)>>1; i++) {
    if (i == n-i-1) sum += x[i] * cnt;
    else sum += (x[i] + x[n-i-1]) * cnt;
    cnt += (n - 2);
  }
  printf("%.2lf", sum);
}