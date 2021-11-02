// 2021/10/08 

int solution(int A[], int N) {
  // make sort A[i] == i+1
  for (int i=0; i<N; i++)
    if (A[i] != i + 1) {
      int from = A[i]; A[i] = -1;
      while (1 <= from && from <= N) {
        int to = A[from-1];
        if (from == to) break;
        else A[from-1] = from;
        from = to;
      }
    }

  for (int i=0; i<N; i++)
    if (A[i] != i + 1)
      return i + 1;
  return N + 1;
}
