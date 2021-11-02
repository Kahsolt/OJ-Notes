// 2021/10/10 

#include <math.h>

int solution(int A[], int N) {
  int L = 0, R = 0;
  for (int i=0; i<N; i++) R += abs(A[i]);

  int mindiff = R;
  for (int i=0; i<N-1; i++) {
    L += A[i], R -= A[i];
    int diff = abs(L - R);
    mindiff = diff < mindiff ? diff : mindiff;
  }
  return mindiff;
}
