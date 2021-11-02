// 2021/10/02 
// Note: 二分


int findMedianinTwoSortedAray(int* arr1, int arr1Len, int* arr2, int arr2Len) {
  int L1 = 0, L2 = 0, R1 = arr1Len-1, R2 = arr2Len-1;
  while (L1<R1 && L2<R2) {
    int M1 = (L1 + R1) >> 1, M2 = (L2 + R2) >> 1;
    int x1 = arr1[M1], x2 = arr2[M2];
    if (x1 == x2) return x1;
    if (x1 < x2) {
      L1 = M1 + 1;      // FIXME: 需要仔细地处理奇偶，反正每次抛掉的长度必须相等
      R2 = M2 - 1;
    } else {
      R1 = M1 - 1;
      L2 = M2 + 1;
    }
  }
  return (arr1[L1] + arr2[L2]) >> 1;
}