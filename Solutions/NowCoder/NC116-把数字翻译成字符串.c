// 2021/07/31 
// Note: 注意0这个坑

int solve(char* nums) {
  int len = 0;
  while (nums[len]) { nums[len] -= '0'; len++; }
  if (!len) return 0;

  int dp[len]; //memset(dp, 0, sizeof(int)*len);
  dp[0] = nums[0] ? 1 : 0;
  
  for (int i=1; i<len; i++) {
    dp[i] = nums[i] ? dp[i-1] : 0;
    int n = nums[i-1] * 10 + nums[i];
    if (10<=n && n<=26) dp[i] += i >= 2 ? dp[i-2] : 1;      // 这里是[10,26]，不是[1,26]!!
  }
    
  for (int i=0; i<len; i++)
    printf("%d ", dp[i]);
  putchar('\n');

  return dp[len-1];
}