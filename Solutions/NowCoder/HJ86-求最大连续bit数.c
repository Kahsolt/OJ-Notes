// 2021/08/11 
// Note: 硬数

#include <stdio.h>

int main() {
  int x; while (~scanf("%d", &x)) {
    int res = 0, cnt = 0;
    while (x) {
      if (x & 1) cnt++;
      else { if (res < cnt) res = cnt; cnt = 0; }
      x >>= 1;
    }
    if (res < cnt) res = cnt;    // tailling
    printf("%d\n", res);
  }
}