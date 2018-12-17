#include <stdio.h>
#include <stdlib.h>
#define N 100000
/* The Missing Number (20)*/

int cmp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}
int x[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
    scanf("%d", &x[i]);
  qsort(&x, n, sizeof(int), cmp);

  int i = 0, expect = 1;
  while (x[i] < 0) i++; /* skip negatives */
  while (i < n) {
    if (x[i++] == expect) {
      expect++;
      while (x[i] == x[i-1]) i++; /* skip redudant */
    }
    else break;
  }
  printf("%d\n", expect);
}