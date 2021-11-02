// 2021/07/29 
// Note: 经典二位dp, 可以尽量优化

char* LCS(char* str1, char* str2) {
  short len1 = strlen(str1), len2 = strlen(str2);
  short dp[len1][len2], max = 0, idx = -1;
  memset(dp, 0, sizeof(char) * len1 * len2);
  
  for (short i=0; i<len1; i++)
    for (short j=0; j<len2; j++) {
      dp[i][j] = str1[i] == str2[j] ? (i>=1&&j>=1 ? dp[i-1][j-1] : 0) + 1 : 0;
      if (dp[i][j] > max) max = dp[idx=i][j];
    }
  char *p = &str1[idx]; *(p+1) = '\0';  // make string inplace
  return p - max + 1;
}

// why this is wrong??
char* LCS(char* str1, char* str2) {
  int len1 = strlen(str1), len2 = strlen(str2);
  char* p;
  if (len1 > len2) p = str1, str1 = str2, str2 = p;   // assure str1 is shorter

  int dp[len1], max = 0, idx = -1;
  memset(dp, 0, sizeof(char) * len1);         // 1-dim dp array
  
  for (int i=0; i<len2; i++)
    for (int j=len1-1; j>=0; j--) {
      dp[j] = str1[j] == str2[i] ? (j>=1 ? dp[j-1] : 0) + 1 : 0;
      if (dp[j] > max) max = dp[idx=j];
    }
  p = &str1[idx]; *(p+1) = '\0';              // make string inplace
  return p - max + 1;
}
