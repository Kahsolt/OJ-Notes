// 2021/10/11 

int solution(int A[], int B[], int N) {
  int ans = 0, now = B[0] - 1;
  for (int i=0; i<N; i++) {
    if (A[i] < now) continue;
    ans++; now = B[i];
  }
  return ans;
}
