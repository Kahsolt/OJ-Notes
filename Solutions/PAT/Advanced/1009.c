#include <stdio.h>
#include <memory.h>
#define N 1001
#define N2 2001
#define esp 1e-5
/* Product of Polynomials (25) */

double poly[2][N], ans[N2]; // idx => exp, val => coeff

int main() {
  for (int i=0; i<N; i++)
    poly[0][i] = poly[1][i]
      = poly[0][i<<1] = poly[1][i<<1]
      = ans[i] = 0.0;
  for (int t=0; t<2; t++) {
    int n;
    scanf("%d", &n);
    while (n--) {
      int exp; double coeff;
      scanf("%d%lf", &exp, &coeff);
      poly[t][exp] += coeff;
    }
  }
  for (int i=N-1; i>=0; i--)
    for (int j=N-1; j>=0; j--) {
      if (poly[0][i] > esp && poly[1][j] > esp)
        ans[i+j] += poly[0][i] * poly[1][j];
      if (ans[i+j] < esp) ans[i+j] = 0.0;   /* clear */
    }
  
  int cnt = 0;
  for (int i=N2-1; i>=0; i--)
    if (ans[i] > esp) cnt++;
  printf("%d", cnt);
  if (cnt)
    for (int i=N2-1; i>=0 && cnt; i--)
      if (ans[i] > esp) {
        printf(" %d %.1f", i, ans[i]);
        cnt--;
      }
}