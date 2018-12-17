#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 2018/08/01
// 线段树，处理线性序列数据的区间查询
//

#define N 10
typedef struct node {
  int left, right;
  int data; /* here we save the max in this range*/
} Node;
Node tree[N<<1];  /* tree[0] unused */
int data[] = {-1,1,9,5,8,4,6,2,0,7,3};  /* dummy data[0] */

void st_create(int cur, int left, int right) {
  tree[cur].left = left;
  tree[cur].right = right;
  if (left == right) {
    /* leaf layer stores (usually) original data */
    tree[cur].data = data[left];
    return;
  }
  int mid = (left + right) >> 1;
  int lidx = cur << 1;  /* idx of left child */
  int ridx = lidx | 1;
  st_create(lidx, left, mid);
  st_create(ridx, mid+1, right);
  /* upper layer stores statistical data of its children */
  /* eg. sum()/max()/min() */
  tree[cur].data = __max(tree[lidx].data, tree[ridx].data);
}
int st_query(int cur, int left, int right) {
  if (tree[cur].left == left && tree[cur].right == right)
    return tree[cur].data;
  int mid = (tree[cur].left + tree[cur].right) >> 1;
  int lidx = cur << 1;
  int ridx = lidx | 1;
  if (right <= mid) return st_query(lidx, left, mid);
  else if (mid < left) return st_query(ridx, mid+1, right);
  else {
    int l = st_query(lidx, left, mid);
    int r = st_query(ridx, mid+1, right);
    return __max(l, r);
  }
}

int main() {
  st_create(1, 1, N);
  for (int i=1; i<=N; i++) printf("%d|", i); puts("");
  for (int i=1; i<=N; i++) printf("%d ", data[i]); puts("");
  puts("Input query range:");
  while (1) {
    int start, end;
    scanf("%d%d", &start, &end);
    printf("max in [%d, %d] = %d\n", start, end, 
          st_query(1, start, end));
  }
}