// 2021/07/29 
// Note: 
 
class Solution {
public:
  int NumberOf1Between1AndN_Solution(int n) {
    int d = n % 10; n /= 10;
    int R = 0, r = 0, h = 0, p = 1, last = 0;
    while (n) {
      if (d >=1) r = (h + 1) + (d - 1) * last;
      d = n % 10; n /= 10;
      p *= 10; h += d * p;
      last = r;
    }
    return R;
  }
};