// 2021/10/08 

int solution(int A[], int N) {
  int r = A[0];
  for (int i=1; i<N; i++)
    r ^= A[i];
  return r;
}
