// 2021/10/10

int solution(int A[], int N) {
  int maxval = 0;
  for (int i=0; i<N-2; i++)
    for (int j=i+1; j<N-1; j++)
      for (int k=j+1; k<N; k++) {
        int val = A[i] * A[j] * A[k];
        maxval = val > maxval ? val : maxval;
      }
  return maxval;
}
