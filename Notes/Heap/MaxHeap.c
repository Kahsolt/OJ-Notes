#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 5

int* initHeap(int n) {
  size_t sz = (n + 1) * sizeof(int);
  int* heap = malloc(sz); memset(heap, 0x00, sz);
  heap[0] = 0;/* use as counter */
  return heap;
}

int insertHeap(int* heap, int val) {
  if(heap[0]>=MAXN) { printf("Heap is full.\n"); return -1; }
  int idx=++heap[0]; /*heap[idx]=val;*/ /* 新元素准备加入末尾，跟踪序号 */
  /* 从末尾元素开始向上调整 */
  while(idx>1 && val>heap[idx>>1]) { /* 只要父节点存在且比新元素小 */
    heap[idx]=heap[idx>>1]; /* 父节点下沉 */
    idx>>=1;
  }
  heap[idx]=val;
  printf("Inserted into idx #%d\n", idx);
  return idx;
}

int deleteHeap(int* heap) {
  if(heap[0]<=0) { printf("Heap is empty.\n"); return -1; }
  int data=heap[1]; heap[1]=heap[heap[0]--];	/* 取走原根，末尾元素填充根 */
  /* 从根开始向下调整 */
  int root=1, maxidx=root<<1;
  while(maxidx <= heap[0]) { /* 只要至少还有一个儿子(左)可讨论交换性 */
    if(maxidx+1 <= heap[0] && heap[maxidx+1]>heap[maxidx]) maxidx++;	/* 右儿子存在且较大 */
    int tmp=heap[root]; heap[root]=heap[maxidx]; heap[maxidx]=tmp;	/* 交换根和大儿子 */
    root=maxidx; maxidx=root<<1;	/* 移动到大儿子 */
  }
  printf("Retrieved value %d\n", data);
  return data;
}

int main() {
  int *heap = initHeap(MAXN);

  deleteHeap(heap);
  insertHeap(heap, 1);
  insertHeap(heap, 7);
  insertHeap(heap, 2);
  insertHeap(heap, 2);
  deleteHeap(heap);
  insertHeap(heap, 0);
  insertHeap(heap, 3);
  insertHeap(heap, -1); /* FULL */
  deleteHeap(heap);
  deleteHeap(heap);
  deleteHeap(heap);
  deleteHeap(heap);
  deleteHeap(heap);
  deleteHeap(heap);
}
