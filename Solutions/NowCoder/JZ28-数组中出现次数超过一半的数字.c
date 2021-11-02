// 2021/07/29 
// Note: 因为过半，所以直接统计连续地出现最多次数的那个数字即可
//     *最坏的情况: 0 1 0 2 0 3 0 4 0 5 ... 0 0，因为严格0过半，所以必然至少有一个连续的 0 0

int MoreThanHalfNum_Solution(int* num, int len) {
  int cur = num[0], cnt = 1, r = cur, maxcnt = 1;
  for (int i=1; i<len; i++) {
    if (num[i] == cur) cnt++;
    else {
      if (cnt >= maxcnt) maxcnt = cnt, r = cur;
      cur = num[i], cnt = 1;   // renew
    }
  }
  if (cnt >= maxcnt) r = cur; // fix end
  return r;
}
