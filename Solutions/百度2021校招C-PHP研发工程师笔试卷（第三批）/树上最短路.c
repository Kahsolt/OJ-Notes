#include <stdio.h>
#include <math.h>
#define times(n) int _##n=n;while(_##n--)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)

/*
3
1 2
4 14
8 5
*/

// 2021/09/14 

int main() {
  read(T); times(T) {
    read(x); read(y);
    if (x == y) puts("0");
    int hx = floor(log2(x)) + 1,
        hy = floor(log2(y)) + 1;

    int ans = 0;
    while (hx > hy) { x /= 2; hx--; ans++; }
    while (hx < hy) { y /= 2; hy--; ans++; }
    while (x != y) {
      x /= 2, y /= 2;
      ans += 2;
    }
    printf("%d\n", ans);
  }
}
