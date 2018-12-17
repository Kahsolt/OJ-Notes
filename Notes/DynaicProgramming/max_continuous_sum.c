#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define N 100

// 2018/08/18
// 最大连续子序列和
// F[i] = data[i] + max(0, F[i-1])
//   F[0] = data[0], 可以就地规划

int data[N];
int max_continuous_sum(int n) {
  int dp[N]; dp[0] = data[0];
  int maxsum = data[0];
  for (int i=1; i<n; i++) {
    dp[i] = data[i] + __max(0, dp[i-1]);  // 如果能继承正残量dp[i-1]
    maxsum = __max(maxsum, dp[i]);
  }
  return maxsum;
}
int max_continuous_sum_inplace(int n) {
  int maxsum = data[0];
  for (int i=1; i<n; i++) {
    data[i] = data[i] + __max(0, data[i-1]);
    maxsum = __max(maxsum, data[i]);
  }
  return maxsum;
}
int main() {

}