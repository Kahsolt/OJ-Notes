// 2021/07/30 
// Note: 只分析合法的子结构就行，注意计算的顺序是递增串长、递增串起始点

#include <iostream>
#include <cstring>
using namespace std;


class Solution {
public:
  int longestValidParentheses(string s) {
    int len = s.length(), maxlen = -1;
    if (!len) return 0;

    bool** dp = new bool*[len];     // dp[i][j]: is s[i:j] valid?
    for (int i=0; i<len; i++) {
      dp[i] = new bool[len];
      memset(dp[i], false, sizeof(bool)*len);
    }

    for (int L=2; L<=len; L++)          // L for len
      for (int i=0; i<len-L+1; i++) {  // i for start point
        int j = i + L - 1;             // j for end point
        //printf("i=%d, j=%d, L=%d\n", i, j, L);
        if (s[i] == '(' && s[j] == ')')                  // case of '(x)'
          dp[i][j] |= (i < j - 1 ? dp[i+1][j-1] : true);
        if (!dp[i][j] &&s[j-1] == '(' && s[j] == ')')    // case of 'x()'
          dp[i][j] |= dp[i][j-2];
        if (!dp[i][j] && s[i] == '(' && s[i+1] == ')')   // case of '()x'
          dp[i][j] |= dp[i+2][j];
        
        if (dp[i][j]) maxlen = max(maxlen, j - i);
      }
    
    for (int i=0; i<len; i++) {
      for (int j=0; j<len; j++)
        cout << dp[i][j] << ' ';
      cout << endl;
    }

    return maxlen + 1;    // fix offset
  }
};

int main() {
  Solution sol = Solution();
  cout << sol.longestValidParentheses("()") << endl;
  cout << sol.longestValidParentheses("(()") << endl;
  cout << sol.longestValidParentheses("(())") << endl;
  cout << sol.longestValidParentheses("()()") << endl;
}
