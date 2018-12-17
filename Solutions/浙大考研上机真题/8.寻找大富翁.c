#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100000

int cmp(const void* a, const void *b)
  { return *(int*)b - *(int*)a; }

int x[N];
int main() {
  int n, m; while (~scanf("%d%d", &n, &m)) {
    for (int i=0; i<n; i++) scanf("%d", &x[i]);
    qsort(x, n, sizeof(int), cmp);
    bool prtflag = false;
    for(int i=0; i<m && i<n; i++) {
      if (prtflag) putchar(32);
      else prtflag = true;
      printf("%d", x[i]);
    }
    putchar(10);
  }
}