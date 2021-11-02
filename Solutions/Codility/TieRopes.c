// 2021/10/11 

int solution(int K, int A[], int N) {
  int k = 0, ans = 0;
  for (int i=0; i<N; i++) {
    k += A[i];
    if (k >= K) { k = 0; ans++; }
  }
  if (k >= K) ans++;
  return ans;
}
