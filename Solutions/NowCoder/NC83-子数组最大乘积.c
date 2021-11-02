// 2021/07/31 
// Note: 
 
double maxProduct(double* arr, int arrLen) {
  if (!arrLen) return 0.0;
  if (arrLen == 1) return arr[0];

  double max = arr[0];
  double dp[arrLen]; dp[0] = arr[0];
  for (int i=1; i<arrLen; i++) {     // 构造连续累乘dp[i] = prod(arr[0:i])
    dp[i] = dp[i-1] * arr[i];
    if (dp[i] > max) max = dp[i];
  }

  for (int i=1; i<arrLen-1; i++)
    for (int j=i+1; j<arrLen; j++) { // 缩减区间到dp[j] = prod(arr[i:j])
      int seq = dp[j] / dp[i];
      if (seq > max) max = seq;
    }

  return max;
}
