// 2021/08/15 

#include <stdio.h>
#include <stdlib.h>

static int ans;
static int *pos = NULL, cnt;

void calc(int* arr, int arrLen) {
  int r = 0;
  for (int i=0; i<arrLen; i++) {
    if (!arr[i]) {
      if (r > ans) ans = r;
      r = 0;
    } else r++;
  }
  if (r > ans) ans = r;
}

void search(int* arr, int arrLen, int p, int r) {
  if (!r) { calc(arr, arrLen); return; }

  for (int i=p; i<cnt; i++) {
    arr[pos[i]] = 1;
    if (p + 1 < cnt) search(arr, arrLen, p+1, r-1);
    arr[pos[i]] = 0;
    if (p + 1 < cnt) search(arr, arrLen, p+1, r);
  }
}

int GetMaxConsecutiveOnes(int* arr, int arrLen, int k) {
  cnt = ans = 0;
  pos = (int*) realloc(pos, sizeof(int)*k);
  for (int i=0; i<arrLen; i++)
    if (!arr[i]) pos[cnt++] = i;
  
  if (cnt <= k) return arrLen;
  search(arr, arrLen, 0, k);
  return ans;
}

int main() {
  int arr[] = {1,1,1,0,0,0,1,1,1,1,0}, arrLen = 10, k = 2;
  printf("%d\n", GetMaxConsecutiveOnes(arr, arrLen, k));
  int arr2[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, arrLen2 = 19, k2 = 3;
  printf("%d\n", GetMaxConsecutiveOnes(arr2, arrLen2, k2));
}