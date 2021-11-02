// 2021/10/10 

#include <stdlib.h>
#include <string.h>

int solution(int X, int A[], int N) {
  unsigned int sz = sizeof(char) * (X + 1);
  char *flag = (char*) malloc(sz);
  memset(flag, 0x00, sz);

  int i = 0, r = X;
  for (; r && i<N; i++) {
    if (1 <= A[i] && A[i] <= X)
      if (!flag[A[i]]) {
        flag[A[i]] = 1;
        r--;
      }
  }

  // free(flag);
  return r ? -1 : i - 1;
}
