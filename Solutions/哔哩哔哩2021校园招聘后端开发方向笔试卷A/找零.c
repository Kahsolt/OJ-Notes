// 2021/08/14 

#include <stdio.h>

int GetCoinCount(int N) {
  N = 1024 - N;
  int ans = 0;
  ans += N / 64; N %= 64;
  ans += N / 16; N %= 16;
  ans += N / 4; N %= 4;
  ans += N;
  return ans;
}
