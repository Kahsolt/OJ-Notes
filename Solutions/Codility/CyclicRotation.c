// 2021/10/08

void swap_range(int A[], int L, int R) {
  int i = L, j = R;
  while (i < j) {
    A[i] ^= A[j], A[j] ^= A[i], A[i] ^= A[j];
    i++; j--;
  }
}

struct Results solution(int A[], int N, int K) {
  if (N) {
    K %= N;
    if (K) {
      swap_range(A, 0, N-K-1);
      swap_range(A, N-K, N-1);
      swap_range(A, 0, N-1);
    }
  }

  struct Results result;
  result.A = A;
  result.N = N;
  return result;
}
