// 2021/07/29 
// Note: 连续和，经典动规

int FindGreatestSumOfSubArray(int* array, int arrayLen ) {
  if (!arrayLen) return 0;
  int r = array[0];
  for (int i=1; i<arrayLen; i++) {
    if (array[i-1] > 0) array[i] += array[i-1];
    if (array[i] > r) r = array[i];
  }
  return r;
}
