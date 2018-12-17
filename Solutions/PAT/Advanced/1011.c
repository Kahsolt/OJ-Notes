#include <stdio.h>
/* World Cup Betting (20) */

int main() {
  int t = 3;
  float a, b, c, prod = 1.0f;

  while (t--) {
    scanf("%f%f%f", &a, &b, &c);
    if (a>b && a>c) { printf("W "); prod *= a; }
    else if (b>a && b>c) { printf("T "); prod *= b; }
    else { printf("L "); prod *= c; }
  }
  printf("%.2f\n", ((prod * 0.65) - 1) * 2);
}