// 2021/10/10 

#include <stdlib.h>

int cmp(const void *a, const void *b) { return (int*) a - (int*) b; }

int solution(int A[], int N) {
  if (!N) return 0;
  //qsort(A, N, sizeof(int), cmp);

  for (int i=0; i<N-1; i++)
    for (int j=i+1; j<N; j++)
      if (A[i] > A[j])
        A[i]^=A[j], A[j]^=A[i], A[i]^=A[j];
  
  int cnt = 1, cur = A[0];
  for (int i=1; i<N; i++)
    if (A[i] != cur) {
      cur = A[i];
      cnt++;
    }
  return cnt;
}
