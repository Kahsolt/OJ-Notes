#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define N 100

// 2018/08/16
// 最长上升子串(连续)
//   F[i] = max(F[i], F[i-1]+1) if data[i]>=data[i-1]  ; i=[1,n)
//

int data[N];
int liss(int n) { // O(N)
  int dp[N]; dp[0] = 0;
	int ans = 1;    // at least 1

  for (int i=1; i<n; i++) {
		if (data[i] >= data[i-1])
      dp[i] = dp[i-1] + 1;
    ans = __max(ans, dp[i]);
  }

	return ans;
}

int main() {
  srand(time(NULL));

  int t = rand() % 5 + 1;
	while (t--) {
		int n = rand() % N;
		for (int i=0; i<n; i++)
      printf("%d ", data[i] = rand() % 100);
    putchar(10);
		printf("liss: %d\n", liss(n));
	}
}