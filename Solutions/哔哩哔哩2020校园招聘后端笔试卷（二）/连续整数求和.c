#include <stdio.h>
#include <math.h>
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)

// 2021/08/19 
//
// sum([i,j]) == N
//   => j(j+1) = 2N + i(i-1)
//

int main() {
  read(n);
  
  int ans = 0;
  forp (i, 1, n) {
    int d2 = 1 + 8 * n + 4 * i * (i - 1);
    int d = sqrt(d2);
    //printf("d2=%d d=%d\n", d2, d);
    if (d * d != d2) continue;
    ans += !((d - 1) & 0x1);    // test even
  }
  
  prti(ans);
}
