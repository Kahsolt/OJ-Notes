#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define COMPAROR >

/* 2018-07-31 */

typedef int DataType;
typedef struct heap {
  size_t size;    /* #data */
  DataType* data; /* data[0] unused */
} Heap;

void hp_adjust_up(Heap* heap, int cur) {
  /* while there's a father node to compare */
  while (cur > 1) {
    int father = cur >> 1;
    if(heap->data[cur] COMPAROR heap->data[father]) {
      /* swap: popup */
      heap->data[cur] ^= heap->data[father] 
        ^= heap->data[cur] ^= heap->data[father];
      cur = father;
    } else break; /* stop if no exchange */
  }
}
void hp_adjust_down(Heap* heap, int cur) {
  while (true) {
    int lchild = cur << 1;
    int rchild = lchild | 1;
    int maxval = heap->data[cur], maxidx = cur;
    if(lchild <= heap->size && heap->data[lchild] COMPAROR maxval)
      maxval = heap->data[maxidx = lchild];
    if(rchild <= heap->size && heap->data[rchild] COMPAROR maxval)
      maxval = heap->data[maxidx = rchild];
    /* found a child to exchange */
    if(maxidx != cur) {
      /* swap: falldown */
      heap->data[cur] ^= heap->data[maxidx]
        ^= heap->data[cur] ^= heap->data[maxidx];
      cur = maxidx;
    } else break; /* stop if no exchange */
  }
}
Heap* hp_heapify(int arr[], int size) {
  Heap* heap = malloc(sizeof(Heap));
  heap->size = size;
  /* let data[0] be dummy */
  heap->data = malloc((size + 1) * sizeof(DataType));
  /* copy data */
  memcpy(heap->data + 1, arr, size * sizeof(DataType));
  /* build a heap */
  for(int i=size<<1; i>=1 ;i--)
    hp_adjust_down(heap, i);
  return heap;
}
void hp_destroy(Heap* heap) {
  if (heap) {
    if (heap->data) free(heap->data);
    free(heap);
  }
}
DataType hp_gettop(Heap* heap) {
  /* pop top */
  DataType val = heap->data[1];
  /* move tail to top then decrease size */
  heap->data[1] = heap->data[heap->size--];
  /* let it falldown */
  hp_adjust_down(heap, 1);
  return val;
}
void hp_insert(Heap* heap, DataType value) {
  /* insert to tail then increase size */
  heap->data[++heap->size] = value;
  /* let it popup */
  hp_adjust_up(heap, heap->size);
}
void hp_sort(Heap* heap) {  /* after sort, no longer a heap */
  /* save whole size */
  size_t sz = heap->size;
  for(int i=1; i<=sz; i++) {
    /* swap top and tail */
    heap->data[1] ^= heap->data[heap->size] 
      ^= heap->data[1] ^= heap->data[heap->size];
    /* decrease unsorted area size */
    heap->size--;
    hp_adjust_down(heap, 1);
  }
  /* restore heap size */
  heap->size = sz;
}
void hp_print(Heap* heap) {
  printf("[%d] ", heap->size);
  for (int i=1; i<=heap->size; i++)
    printf("%d ", heap->data[i]);
  printf("\n");
}
void hp_test() {
  size_t sz = 10;
  DataType arr[] = {1,9,5,8,7,0,6,3,4,2};
  Heap* hp = hp_heapify(arr, sz);
  hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  hp_insert(hp, 7); hp_print(hp);
  hp_insert(hp, 4); hp_print(hp);
  hp_insert(hp, 9); hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  printf("top=%d\n", hp_gettop(hp)); hp_print(hp);
  hp_sort(hp); hp_print(hp);
  hp_destroy(hp);
}

int main() {
  hp_test();
  return 0;
}