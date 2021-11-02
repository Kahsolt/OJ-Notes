// 2021/08/08 
// Note: 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// TLE
bool isMatch_rec(char* s, char* p) {
  while (*p) {
    switch (*p) {
    case '*':
      p++;                   // 吃掉一个*
      while (*s) {           // 用零个或多个s的字符来替换
        if (isMatch_rec(s, p)) return true;
        s++;
      }
      return isMatch_rec(s, p);  // 边缘情况，让p匹配空串
      break;
    case '?':
      if (*s) { s++; p++; }  // 吃掉一个字符
      else return false;     // 没字符可吃说明不匹配
      break;
    default:
      if (*s == *p) { s++; p++; }  // 吃掉相同字符
      else return false;           // 吃不掉说明不匹配
      break;
    }
  }
  return !*s && !*p;
}

bool isMatch(char* s, char* p) {
  if (!*s && !*p) return true;
  if (*s && !*p) return false;
    
  int lens = strlen(s), lenp = strlen(p);
  bool dp[lenp+1][lens+1]; memset(dp, false, sizeof(char)*(lenp+1)*(lens+1));

  dp[0][0] = true;    // dp[i][j]表示p[:i+1]是否能匹配s[:j+1]，dp[0][0]表示空串匹配空串
  for (int i=1; i<=lenp; i++)
    dp[i][0] = dp[i-1][0] && (p[i-1] == '*');
    
  for (int i=1; i<=lenp; i++)
    for (int j=1; j<=lens; j++) {
      if (p[i-1] == '?')
        dp[i][j] = dp[i-1][j-1];      // 只需要前面已经匹配好
      else if (p[i-1] == '*')
        dp[i][j] = dp[i-1][j] || dp[i][j-1];  // 只需要正上方已经匹配好
      else
        dp[i][j] = dp[i-1][j-1] && (p[i-1] == s[j-1]);  // 前面已经匹配好，且当前字符匹配
    }

  for (int i=0; i<=lenp; i++) {
    for (int j=0; j<=lens; j++)
      printf("%d ", dp[i][j]);
    putchar('\n');
  }
  
  return dp[lenp][lens];
}

int main() {
  char s[] = "hhhhhhhahhaahhahhhhaaahhahhahaaahhahahhhahhhahaaahaah";
  char p[] = "h*h*ah**ha*h**h***hha";
  printf("%d\n", isMatch(s, p));
}
