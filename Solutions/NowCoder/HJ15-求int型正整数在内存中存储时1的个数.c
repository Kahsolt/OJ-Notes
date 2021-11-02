// 2021/08/11 
// Note: 位运算经典方法，记住即可

#include <stdio.h>

int main() {
  int x; scanf("%d", &x);
  int cnt = 0;
  while (x) {
    x &= (x-1);
    cnt++;
  }
  printf("%d", cnt);
}