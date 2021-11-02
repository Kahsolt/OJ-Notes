// 2021/07/29 
// Note: 基础
 
int maxsumofSubarray(int* arr, int arrLen) {
  if (!arrLen) return 0;
  int r = arr[0];
  for (int i=1; i<arrLen; i++) {
    if (arr[i-1] > 0) arr[i] += arr[i-1];
    if (arr[i] > r) r = arr[i];
  }
  return r;
}