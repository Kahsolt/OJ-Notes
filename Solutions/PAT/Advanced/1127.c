#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define N 31
/* ZigZagging on a Tree (30) */

typedef struct node {
  int data;
  struct node *left, *right;
} Node;
int inorder[N], postorder[N];

Node* bt_create(int ps, int pe, int is, int ie) {
  int root = postorder[pe], idx = -1;
  forp(i, is, ie)
    if (inorder[i] == root)
      { idx = i; break; }

  // printf("root = %d, idx = %d | pre: <%d %d>, in: <%d %d>\n",
  //      root, idx, ps, pe, is, ie);

  Node* n = malloc(sizeof(Node));
  n->data = root;
  n->left = is<=idx-1 ? bt_create(ps, ps+idx-is-1, is, idx-1) : NULL;
  n->right = idx+1<=ie ? bt_create(ps+idx-is, pe-1, idx+1, ie) : NULL;
  return n;
}
void bt_zigzagorder(Node* t) {
  int src = 0, top[2] = { 0, 0 };
  Node* stack[2][N];
  stack[src][top[src]++] = t; // push root

  bool prtflag = false;
  while (top[src]) {
    int dst = src ^ 1;
    while (top[src]) {
      Node* n = stack[src][--top[src]];
      if (prtflag) putchar(' ');
      else prtflag = true;
      prti(n->data);
      if (src) {  // swap order
        if (n->left) stack[dst][top[dst]++] = n->left;
        if (n->right) stack[dst][top[dst]++] = n->right;
      } else {
        if (n->right) stack[dst][top[dst]++] = n->right;
        if (n->left) stack[dst][top[dst]++] = n->left;
      }
    }
    src = dst;
  }
}
int main() {
  read(n);
  forp(i, 1, n) input(inorder[i]);
  forp(i, 1, n) input(postorder[i]);
  Node* t = bt_create(1, n, 1, n);
  bt_zigzagorder(t);
}