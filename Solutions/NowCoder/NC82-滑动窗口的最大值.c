// 2021/10/02 
// Note: 要求时空复杂度都是O(n)

// 但我们还是先写个线段树版本O(nlogn)

#include <stdio.h>
#include <stdlib.h>

#define INF 100000
#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef struct node {
  int l, r;
  int x;        // maxval of range [l, r]
  struct node *left, *right;
} Node;

Node* new_node(int l, int r, int x) {
  printf("new_node: [%d, %d] of %d\n", l, r, x);

  Node* n = (Node*) malloc(sizeof(Node));
  n->l = l, n->r = r, n->x = x;
  n->left = n->right = NULL;
  return n;
}

Node* create_segtree(int* num, int L, int R) {
  if (L == R) return new_node(L, R, num[L]);

  int M = (L + R) >> 1;
  Node* nl = create_segtree(num, L, M);
  Node* nr = create_segtree(num, M+1, R);
  Node* n  = new_node(L, R, max(nl->x, nr->x));
  n->left = nl, n->right = nr;
  return n;
}

int query_segtree(Node* p, int L, int R) {
  printf("query: [%d, %d] for [%d, %d]\n", p->l, p->r, L, R);
  if (L <= p->l && p->r <= R) return p->x;    // NOTE: 只要 当前区间 被 目标区间 覆盖，就尽其所能地给出值

  int m = (p->l + p->r) >> 1;
  int ret = -INF;
  if (L <= m) {
    int r = query_segtree(p->left, L, R);     // NOTE: 保持这个[L,R]端点
    ret = max(ret, r);
  }
  if (m+1 <= R) {
    int r = query_segtree(p->right, L, R);
    ret = max(ret, r);
  }
  return ret;
}

int* maxInWindows(int* num, int numLen, int size, int* returnSize) {
  *returnSize = 0;
  if (!size || numLen < size) return NULL;

  Node* root = create_segtree(num, 0, numLen-1);

  *returnSize = numLen - size + 1;
  int *r = (int*) malloc (sizeof(int) * (*returnSize));

  for (int i=0; i<*returnSize; i++)
    r[i] = query_segtree(root, i, i+size-1);
  return r;
}

int main() {
  int num[] = {2,3,4,2,6,2,5,1};
  int retsz;
  int *r = maxInWindows(num, 8, 3, &retsz);
  for (int i=0; i<retsz; i++)
    printf("%d ", r[i]);
}
