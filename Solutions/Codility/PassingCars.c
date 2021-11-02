// 2021/10/10 

#include <stdlib.h>
#include <string.h>
#define MAXCNT 1000000000

int solution(int A[], int N) {
  unsigned sz = sizeof(int) * N;
  int *cnt = (int *) malloc(sz);
  memset(cnt, 0x00, sz);

  for (int i=N-1; i>=0; i--)
    cnt[i] = cnt[i+1] + A[i];
  
  unsigned long long r = 0;
  for (int i=0; i<N; i++)
    if (!A[i]) {
      r += cnt[i];
      if (r > MAXCNT) return -1;
    }
  return r;
}
