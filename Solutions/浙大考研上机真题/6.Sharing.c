#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define N 100000

int next[N];  // abstract 'link' field
int main() {
  int lla, llb, n; while (~scanf("%d%d%d", &lla, &llb, &n)) {
    memset(next, 0xFF, sizeof(next)); // default terminal
    while (n--) {
      int x, y; scanf("%d %*c %d", &x, &y);
      next[x] = y;
    }

    // get lengt of 'lla' and 'llb'
    int lena = 0, lenb = 0;
    int p = lla; while (next[p] != -1) { lena++; p = next[p]; }
    int q = llb; while (next[q] != -1) { lenb++; q = next[q]; }
    int diff = lena - lenb;
    // reset and align
    p = lla, q = llb;
    if (diff > 0) while (diff) { p = next[p]; diff--; } 
    else while (diff) { q = next[q]; diff++; }
    
    while (p != q) {
      if (next[p]==-1 || next[q]==-1) break;  // EOL meet
      p = next[p]; q = next[q];
    }
    if (p == q) printf("%05d\n", p);  // found common node
    else puts("-1");
  }
}
