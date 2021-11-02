// 2021/08/11 
// Note: 贪心O(n)， 找左右最高的柱子做墙

static inline int max(int a, int b) { return a>=b ? a : b; }
static inline int min(int a, int b) { return a<=b ? a : b; }

long long maxWater(int* arr, int arrLen) {
  int *accleft = (int*) malloc(sizeof(int)*arrLen),
      *accright = (int*) malloc(sizeof(int)*arrLen);

  accleft[0] = arr[0];
  for (int i=1; i<arrLen; i++)
    accleft[i] = max(arr[i], accleft[i-1]);
  accright[arrLen-1] = arr[arrLen-1];
  for (int i=arrLen-2; i>=0; i--)
    accright[i] = max(arr[i], accright[i+1]);

  long long ans = 0;
  for (int i=0; i<arrLen; i++)
    ans += min(accleft[i], accright[i]) - arr[i];

  return ans;
}