#include <stdio.h>
/* The Black Hole of Numbers (20) */

int go(int x) {
  int d[4] = {
    x % 10,
    x / 10 % 10,
    x / 100 % 10,
    x / 1000 % 10
  };
  for (int i=0; i<3; i++)   /* bubble sort */
    for (int j=i+1; j<4; j++)
      if (d[i] < d[j])
        d[i] ^= d[j] ^= d[i] ^= d[j];

  int x1 = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
  int x2 = d[3] * 1000 + d[2] * 100 + d[1] * 10 + d[0];
  int diff = x1 - x2;
  printf("%04d - %04d = %04d\n", x1, x2, diff);

  return diff;
}

int main() {
  int n;
  scanf("%d", &n);
  do { n = go(n); }
    while (n && n != 6174);
}