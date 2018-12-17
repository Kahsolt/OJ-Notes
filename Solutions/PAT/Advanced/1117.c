#include <stdio.h>
#define times(n) int _##n=n; while(_##n--)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)
#define N 100000
/* Eddington Number (25) */

#define lowbit(k) (k & -k)
#define add(e, n, k, val) \
  for (; k<=n; k+=lowbit(k)) \
    e[k] += val;
static inline int sum(int e[], int k) {  // how many numbers that less-equal than k
  int ret = 0;
  for (; k; k-=lowbit(k)) 
    ret += e[k];
  return ret;
}

int main() {
  int e[N+1];  // a[i]: i precense counter
  read(n); times(n) {
    read(x); add(e, n, x, 1);  // add presence
  }
  for (int i=n; i>=0; i--)
    if (n - sum(e, i) >= i)  // if (counts greater than i) >= i
      { prti(i); return 0; }
}