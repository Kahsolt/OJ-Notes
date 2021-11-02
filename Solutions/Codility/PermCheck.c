// 2021/10/10 

int solution(int A[], int N) {
  for (int i=0; i<N; i++)
    if (A[i] != i + 1) {
      int from = A[i]; A[i] = -1;
      while (1 <= from && from <= N) {
        int to = A[from - 1]; A[from - 1] = from;
        if (from == to) break;
        from = to;
      }
    }
  
  for (int i=0; i<N; i++)
    if (A[i] != i + 1)
      return 0;
  return 1;
}
