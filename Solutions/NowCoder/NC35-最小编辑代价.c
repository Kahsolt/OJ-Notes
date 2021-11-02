// 2021/07/29 
// Note: 

inline int min(int a, int b, int c) {
  if (b < a) a = b;
  if (c < a) a = c;
  return a;
}

int minEditCost(char* str1, char* str2, int ic, int dc, int rc) {
  int len1 = strlen(str1), len2 = strlen(str2);
  // dp[i][j]: 将str1[:i]编辑成str[:j]的最小代价(不含右端点), dp[0][0]表示空串到空串
  int dp[len1+1][len2+1];
  memset(dp, 0, sizeof(int)*(len1+1)*(len2+1));     // 必须+1，因为要从空串开始动规
  for (int i=0; i<len1; i++) dp[i][0] = i * dc;     // 当j==1时, dp[i][0] 意为 将str1[:i]删空, 代价为 i*dc
  for (int j=0; j<len2; j++) dp[0][j] = j * ic;     // 当i==1时, dp[0][j] 意为 从空构造str2[:j], 代价为 j*ic

  for (int i=1; i<=len1; i++)
    for (int j=1; j<=len2; j++)
      dp[i][j] = (str1[i-1] == str2[j-1]) 
                      ? dp[i-1][j-1]                // 若字符相同则无代价
                      : min(dp[i-1][j-1] + rc,      // 否则取三者最小
                            dp[i][j-1] + ic,
                            dp[i-1][j] + dc);
  return dp[len1][len2];
}
