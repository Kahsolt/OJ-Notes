#include <stdio.h>
#include <stdlib.h>
/* Pop Sequence (25) */

int main() {
  int M, N, K; scanf("%d%d%d", &M, &N, &K);
  int stack[1000], top;

  while (K--) {
    int n = 1; /* push n from 1 to N */
    top = -1;
    for (int i=1; i<=N; i++) {
      int k; scanf("%d", &k);
      if (top == M - 1) continue;
      if (top!=-1 && k==stack[top]) top--;
      else {
        while (k!=n && top<M-1 && n<=N) stack[++top] = n++;
        if (k==n && n<N) n++;
      }
    }
    if (top != -1) puts("NO");
    else puts("YES");
  }
}