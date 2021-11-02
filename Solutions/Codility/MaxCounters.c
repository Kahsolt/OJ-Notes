// 2021/10/10 

#include <stdlib.h>
#include <string.h>

struct Results solution(int N, int A[], int M) {
  unsigned sz = sizeof(int) * N;
  int *C = (int *) malloc(sz), maxC = 0;
  memset(C, 0x00, sz);

  for (int i=0; i<M; i++) {
    int id = A[i];
    if (id == N + 1) {
      for (int j=0; j<N; j++)
        C[j] = maxC;
    } else {
      C[id - 1]++;
      maxC = C[id - 1] > maxC ? C[id - 1] : maxC;
    }
  }

  struct Results result;
  result.C = C;
  result.L = N;
  return result;
}
