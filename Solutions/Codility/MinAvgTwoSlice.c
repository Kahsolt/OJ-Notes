// 2021/10/10 

int solution(int A[], int N) {
  double minavg = 100000;
  int minidx = -1;
  for (int i=0; i<N; i++) {
    int sum = A[i], len = 1;
    for (int j=i+1; j<N; j++)
      if (A[j] <= A[j-1]) {
        sum += A[j], len++;
        double avg = (double) sum / len;
        if (avg < minavg) {
          minavg = avg;
          minidx = i;
        }
      } else break;
  }
  
  return minidx;
}
