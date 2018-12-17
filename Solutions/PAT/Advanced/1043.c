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
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 1000
/* Is It a Binary Search Tree (25) */

typedef struct node {
  int val;
  struct node *left, *right;
} Node;

int data[N], type = 0;  /* 0: not decided, 1: bst, -1: mirror bst */
bool ok = true;
Node* bst_create(int left, int right) {
  if (left == right) {
    Node* n = malloc(sizeof(Node));
    n->val = data[left];
    n->left = n->right = NULL;
    return n;
  }
  int root = data[left++], l, r;

  if (type != -1) {
    l = left; r = right;
    while (l<=right && data[l]<root) l++;
    while (r>=left && data[r]>=root) r--;
    if (r + 1 == l) { /* bst */
      if (!type) type = 1;
      else if (type != 1) { ok = false; return NULL; }
      Node* n = malloc(sizeof(Node));
      n->val = root;
      n->left = left<=r ? bst_create(left, r) : NULL;   // optimize
      n->right = l<=right ? bst_create(l, right) : NULL;
      return n;
    }
  }
  
  if (type != 1) {
    l = left; r = right;
    while (l<=right && data[l]>=root) l++;
    while (r>=left && data[r]<root) r--;
    if (r + 1 == l) { /* mirror bst */
      if (!type) type = -1;
      else if (type != -1) { ok = false; return NULL; }
      Node* n = malloc(sizeof(Node));
      n->val = root;
      n->left = left<=r ? bst_create(left, r) : NULL; // optimize
      n->right = l<=right ? bst_create(l, right) : NULL;
      return n;
    }
  }

  ok = false;
  return NULL;
}
bool prtflag = false;
void bst_postorder(Node* t) {
  if (!t) return;
  if (t->left) bst_postorder(t->left);
  if (t->right) bst_postorder(t->right);
  if (prtflag) putchar(' ');
  else prtflag = true;
  printf("%d", t->val);
}
int main() {
  read(n); forr(i, 0, n) input(data[i]);
  Node* t = bst_create(0, n-1);
  if (ok) {
    puts("YES");
    bst_postorder(t);
  } else puts("NO");
}
