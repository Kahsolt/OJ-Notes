// 2021/10/10 

int solution(int A[], int N) {
   long long sum = (N + 2) * (N + 1) >> 1;
   for (int i=0; i<N; i++) sum -= A[i];
   return sum;
}
