#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 1000
/* N Queens Puzzle (20) */

int main() {
  int k; scanf("%d", &k);
  while (k--) {
    int n; scanf("%d", &n);
    bool horiz[N+1], mdiag[N<<1+1], cdiag[N<<1+1]; /* safe on this line */
    size_t sz = (n + 1) * sizeof(bool);
    size_t sz2 = (n << 1 + 1) * sizeof(bool);
    memset(horiz, true, sz);  /* horizontal */
    memset(mdiag, true, sz2); /* main diagonal: left up to righ down */
    memset(cdiag, true, sz2); /* counter diagonal: right up to left down */
    bool valid = true;
    for (int j=1; j<=n; j++) {  /* j: column */
      int i; scanf("%d", &i);   /* i: line */
      if (!valid) continue;
      if (horiz[i]) horiz[i] = false;
      else valid = false;
      if (mdiag[i-j+n]) mdiag[i-j+n] = false;
      else valid = false;
      if (cdiag[i+j-1]) cdiag[i+j-1] = false;
      else valid = false;
    }
    puts(valid ? "YES" : "NO");
  }
}
