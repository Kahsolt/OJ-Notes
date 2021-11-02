// 2021/10/10 

int solution(int A, int B, int K) {
  int L = A, R = B;
  while (L % K) L++;
  while (R % K) R--;
  if (L > R) return 0;
  return (R - L) / K + 1;
}
