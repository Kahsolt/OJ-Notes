// 2021/10/08 

int solution(int N) {
  int cnt = 0, maxcnt = 0;
  while (N && !(N & 0x1)) N >>= 1;
  while (N) {
    int b = N & 0x1; N >>= 1;
    if (!b) cnt++;
    else {
      maxcnt = cnt > maxcnt ? cnt : maxcnt;
      cnt = 0;
    }
  }
  return maxcnt;
}
