// 2021/10/11 

#define abs(x) x>0?x:-x

int solution(int A[], int N) {
  int r;
  for (int i=0; i<N-1; i++)
    for (int j=i+1; j<N; j++) {
      int x = abs(A[i] + A[j]);
      if (x < r) r = x;
    }
  return r;
}
