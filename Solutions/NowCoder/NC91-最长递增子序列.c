// 2021/07/30 
// NOTE: 思路仿照LCS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* LIS(int* arr, int arrLen, int* returnSize) {
  int prev[arrLen], len[arrLen], maxlen = -1, idx = -1;
  for (int i=0; i<arrLen; i++) { prev[i] = i; len[i] = 1; }  // 初始化，避免判空

  for (int i=1; i<arrLen; i++) {    // 每次新增加一个arr[i]
    // 寻找一个最优目标
    int tgt = -1, mlen = len[i];
    for (int j=0; j<i; j++) {       // 就检查前面所有的状态，看把这个arr[i]追加到哪个状态上去
      if (arr[i] <= arr[j]) continue;  // 跳过，如果arr[i]不可追加

      // j态子序列更长, 或者一样长、但j态前驱的更小
      if (len[j]>mlen || len[j]==mlen && arr[prev[j]]<arr[prev[i]])
        mlen = len[tgt=j];
    }
    // 然后只更新一次
    if (tgt != -1) {
      prev[i] = tgt; len[i] = len[tgt] + 1;
      if (len[i]>maxlen || len[i]==maxlen && arr[i]<arr[idx])
        maxlen = len[idx=i];
    }
  }

  //for (int i=0; i<arrLen; i++) printf("%d ", prev[i]); putchar('\n');
  //for (int i=0; i<arrLen; i++) printf("%d ", len[i]); putchar('\n');
  //printf("%d %d\n", maxlen, idx);

  int *r = (int*)malloc(sizeof(int)*maxlen);
  for (int i=maxlen-1; i>=0; i--) {
    r[i] = arr[idx];
    idx = prev[idx];
  }
  *returnSize = maxlen;
  return r;
}

int main() {
  //int arr[] = {2,1,5,3,6,4,8,9,7}, arrLen = 9;
  int arr[] = {1,2,8,6,4}, arrLen = 5;
  int *returnSize;
  int *r = LIS(arr, arrLen, returnSize);
  for (int i=0; i<*returnSize; i++) printf("%d ", r[i]); putchar('\n');
}
