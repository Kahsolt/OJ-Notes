#include <stdio.h>
#include <stdbool.h>
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define min(a,b) a<=b?a:b
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)

#define MAXN 100000

// 2021/08/21 

bool a[MAXN+1] = { 0 }, b[MAXN+1] = { 0 };
bool dpa[MAXN+1] = { 0 }, dpb[MAXN+1] = { 0 };

int main() {
  read(n);
  forp (i, 1, n) input(a[i]);
  forp (i, 1, n) input(b[i]);

  dpa[0] = dpb[0] = 1;
  forp (i, 1, n) {
    dpa[i] = !a[i] + min(a[i-1] ? dpa[i-2] : dpa[i-1], dpb[i-1]);
    dpb[i] = !b[i] + min(b[i-1] ? dpb[i-2] : dpb[i-1], dpa[i-1]);
  }

  prti(min(dpa[n], dpb[n]));
}
