#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define N 10

// 2018/08/08
// 最长上升子序列
//   F[i] = max(F[i], F[j]+1) if data[i]>data[j]  ; i=[0,n), j=[0,i)
//     F[i]: 表示以第i个数作为子序列末元素时，最大的lis长度
//

int data[N];
int lis(int n) {  // 朴素方法, O(N^2)
  int dp[N];
  int ans = 1;    // at least 1
  
  for (int i=0; i<n; i++) {
    dp[i] = 1;    // 初值：最短显然是单个数
    for (int j=0; j<i; j++)   // 检查加入第i个数后，i之前的dp能否更新
      if (data[i] > data[j])  // 不下降
        dp[i] = __max(dp[i], dp[j]+1);
    ans = __max(ans, dp[i]);
  }
  return ans;
}

int main() {
  srand(time(NULL));

  int t = rand() % 5 + 1;
	while (t--) {
		int n = rand() % N + 1;
		for (int i=0; i<n; i++)
      printf("%d ", data[i] = rand() % 100);
    putchar(10);
		printf("lis: %d\n", lis(n));
	}
}