#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define N 30		// 物品数量
#define TT 1000	// 背包容积

// 2018/08/08
// 解决区间最值查询RMQ: Range Minimum/Maximum Query
// F[i][j] = min(F[i][j-1], F[i+2^(j-1)][j-1])
//   F[i][j]：表示data[i..i+2^j-1]间的最值
//   init: F[i][0] = data[i]，注意是填充第0列

int data[N];	// 原始数据
int dp[N][N];	// 动规数组
int pow2[N];	// 辅助数组
void sparse_table(int n) {
	memset(dp, 0x00, sizeof(dp));
	for (int i=0; i<n; i++) dp[i][0] = data[i];
	for (int i=1; i<n; i++) pow2[i] = log((double)i) / log(2); 
  
	int k = 1;	// 区间长度，初始为1
	for (int i=1; i<=n; k<<=1, i++)	// 每次区间长度翻倍
	  for (int j=0; j+k<=n; j++)		// 按列更新
		  dp[j][i] = __min(dp[j][i-1], dp[j+k][i-1]);
}
int query(int s, int t) {	// min(data[s..t])
	int x = pow2[t-s+1];
	return __min(dp[s][x], dp[t-(1<<x)+1][x]);
}

int main() {
	// TODO: 又是什么po算法???

	return 0;
}