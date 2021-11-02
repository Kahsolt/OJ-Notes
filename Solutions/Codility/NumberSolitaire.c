// 2021/10/11 

#include <stdlib.h>
#define max(x,y) (x)>=(y)?(x):(y)

int solution(int A[], int N) {
  unsigned sz = sizeof(int) * N;
  int* dp = (int*) malloc(sz);

  for (int i=0; i<N; i++) {
    dp[i] = A[i];
    for (int j=1; j<=6; j++)
      if (i >= j)
        dp[i] = max(dp[i], A[i] + dp[i-j]);
  }
  
  return dp[N - 1];
}
