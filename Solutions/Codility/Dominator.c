// 2021/10/08 

int solution(int A[], int N) {
  int it = 0, maxit = 0, cnt = 0, maxcnt = 0;
  for (int i=1; i<N; i++)
    if (A[i] == A[it]) cnt++;
    else {
      if (cnt > maxcnt) {
        maxcnt = cnt;
        maxit = it;
      }
      cnt = 0;
      it = i;
    }
  return maxit;
}
