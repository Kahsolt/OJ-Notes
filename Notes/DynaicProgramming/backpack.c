#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define N 30		// 物品数量
#define TT 1000	// 背包容积

// 2018/08/08
// 01背包: n个物品
// 完全背包: n种物品，每种无限个
// 满背包(可01可完全)：dp[]同时表示状态有效性，更新时检查
// 多重背包：加一层循环枚举个数；展开各类物品，转化成01背包；按二进制指数合并同类物品、产生一些新的"组合物品"
//
// F[i][j] = max(F[i-1][j], F[i-1][j-w[i]] + v[i])	(j>=w[i])
//   F[i][j]: 使用前i个物品占用空间j时能产生的最大价值
//      => max(不放物品i，放物品i且从某个可容的状态中占用空间w[i])
//   (物品体积w[], 物品价值v[])
//

int w[N], v[N], cnt[N];	// 每个物品的容积、价值、数量
int dp[TT+1];		// 动规数组

int backpack_01(int n, int T) {	// n个物品，背包容积为T
  memset(dp, 0x00, sizeof(dp));		// default 0
	for (int i=0; i<n; i++)					// foreach article
	  for (int j=T; j>=w[i]; j--)		// 逆序消除后效性，每个物品只有一件
		  dp[j] = __max(dp[j], dp[j - w[i]] + v[i]);	// 更新所有能够放下一个w[i]的状态
	return dp[T];
}
int backpack_complete(int n, int T) {	// n种物品，每种物品有无限件
  memset(dp, 0x00, sizeof(dp));
	for (int i=0; i<n; i++)
	  for (int j=w[i]; j<=T; j++)		// 顺序放置，利用后效性的累积
		  dp[j] = __max(dp[j], dp[j - w[i]] + v[i]);
	return dp[T];
}
int backpack_full(int n, int T) {	// 放不满返回-1
  memset(dp, 0xFF, sizeof(dp));		// default -1: invalid status
	dp[0] = 0;	// initial valid status: value of 0 articles is 0
	for (int i=0; i<n; i++)
	  for (int j=T; j>=w[i]; j--)		// case of 01
//  for (int j=w[i]; j<=T; j++)		// case of complete
		  if (dp[j - w[i]] != -1)			// only transfer on valid status
				dp[j] = __max(dp[j], dp[j - w[i]] + v[i]);
	return dp[T];
}
int backpack_multiple(int n, int T) {
	memset(dp, 0x00, sizeof(dp));
	for (int i=0; i<n; i++)
		for (int k=1; k<=cnt[i]; k++) { // 枚举个数
      int _v = k*v[i], _w = k*w[i]; // cached
		  for (int j=T; j>=_w; j--)		  // case of 01
				dp[j] = __max(dp[j], dp[j - _w] + _v);
    }
	return dp[T];
}
void print_dp(int T) {
	printf("dp: ");
	for (int i=0;i<=T; i++)
		printf("%d ", dp[i]);
	puts("");
}

int main() {
	srand(time(NULL));

  int n = 3, T = 10, r = 2;
	int _w[][3] = {{4, 5, 7}, {3, 5, 7}};
	int _v[][3] = {{5, 6, 10}, {5, 8, 10}};
	int _cnt[][3] = {{2, 1, 3}, {3, 2, 1}};
	while (r--) {
		for (int i=0; i<n; i++) { 
			w[i] = _w[r][i];
			v[i] = _v[r][i];
			cnt[i] = _cnt[r][i];
		}
		printf("backpack_01: [%d]\n", backpack_01(n, T)); print_dp(T);
		printf("backpack_complete: [%d]\n", backpack_complete(n, T)); print_dp(T);
		printf("backpack_full: [%d]\n", backpack_full(n, T)); print_dp(T);
		printf("backpack_multiple: [%d]\n", backpack_multiple(n, T)); print_dp(T);
		puts("=================================");
	}
	puts("");

	int t = rand() % 5 + 1;
	while (t--) {
		int n = rand() % N;
		int T = __max(rand() % TT, TT>>1);	// WARN: rand()不幂等
		for (int i=0; i<n; i++) {
			w[i] = rand() % 10;
			v[i] = rand() % 10;
			cnt[i] = rand() % 5 + 1;
		}
		printf("backpack_01: %d\n", backpack_01(n, T));
		printf("backpack_complete: %d\n", backpack_complete(n, T));
		printf("backpack_full: %d\n", backpack_full(n, T));
		printf("backpack_multiple: [%d]\n", backpack_multiple(n, T)); print_dp(T);
		puts("=================================");
	}

	return 0;
}