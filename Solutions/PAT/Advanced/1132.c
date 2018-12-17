#include <stdio.h>
#include <math.h>
/* Cut Integer (20) */

typedef unsigned int UI;
int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    UI Z;
    scanf("%d", &Z);
    int digs = 1 + (int)log10(Z) >> 1;
    UI p = pow(10, digs);
    UI prod = (Z / p) * (Z % p);
    puts(prod && !(Z%prod) ? "Yes" : "No");
  }
}