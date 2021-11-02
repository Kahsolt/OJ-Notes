// 2021/07/29 
// Note: 最优算法是Manacher，廉价一点的是中心扩散

#include <iostream>
using namespace std;

class Solution {
public:
  int getLongestPalindrome(string A, int n) {
    if (!n) return 0;
      
    int len = n*2+1, maxL = 1;
    char S[len], *p = S; *p++ = '-';
    for (int i=0; i<n; i++) { *p++ = A[i]; *p++ = '-'; }
    
    for (int i=0; i<len; i++) {  // 中心扩散
      int L = 1;
      while (i-L>=0 && i+L<len && S[i-L]==S[i+L]) L++;
      if (L > maxL) maxL = L;
    }
    return maxL - 1;
  }
};

int main() {
  Solution().getLongestPalindrome("abc1234321ab", 12);
}
