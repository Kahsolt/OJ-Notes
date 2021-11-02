// 2021/10/11 

#define abs(x) x>0?x:-x

int solution(int A[], int N) {
  for (int i=0; i<N; i++) A[i] = abs(A[i]);

  int i = 0, j = N-1;
  int r = 0;
  while (i <= j) {
    if (A[i] == A[j]) i++, j--, r++;
    else if (A[i] > A[j])
      while (i < j && A[i] > A[j]) i++, r++;
    else
      while (i < j && A[i] < A[j]) j--, r++;
  }
  return r;
}
