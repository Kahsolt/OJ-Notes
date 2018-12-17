#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 26

int a[N], b[N], c[N];
int base[] = {
  2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
  53,59,61,67,71,73,79,83,89,97,101
};

int main() {
//  while (true) {
    memset(a, 0x00, sizeof(a));
    memset(b, 0x00, sizeof(b));
    memset(c, 0x00, sizeof(c));

    int p = -1; while (true) {
      scanf("%d", &a[++p]);
      if (getchar() == ' ') break;
    }
    int q = -1; while (true) {
      scanf("%d", &b[++q]);
      if (getchar() == '\n') break;
    }
//    if (!p && !q && !(a[0]*b[0])) break;  // 0 0, exit

    int r = -1;
    while (p>=0 || q>=0) {  // add
      int na = 0, nb = 0;
      if (p>=0) na = a[p--];
      if (q>=0) nb = b[q--];
      c[++r] += na + nb;
      if (c[r] >= base[r]) {
        c[r+1] += c[r] / base[r];
        c[r] %= base[r];
      }
    }

    bool prtflag = false;
    r = N - 1; while (r>=0 && !c[r]) r--;
    while (r >= 0) {
      if (prtflag) putchar(',');
      else prtflag = true;
      printf("%d", c[r--]);
    }
    putchar(10);
//  }
}
