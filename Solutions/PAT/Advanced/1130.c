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
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 20
/* Infix Expression (25) */

typedef struct node {
  char data[11];
  struct node *left, *right;
} Node;

int left[N+1], right[N+1];
char data[N+1][11];
#define bt_isleaf(n) (!n->left && !n->right)
Node* bt_create(int id) {
  if (id == -1) NULL;
  Node* n = malloc(sizeof(Node));
  strcpy(n->data, data[id]);
  n->left = left[id] != -1 ? bt_create(left[id]) : NULL;
  n->right = right[id] != -1 ? bt_create(right[id]) : NULL;
  return n;
}
void bt_inorder(Node* t, int depth) {
  if (!t) return;
  bool isleaf = bt_isleaf(t);
  if (depth && !isleaf) putchar('(');
  if (t->left) bt_inorder(t->left, depth+1);
  printf("%s", t->data);
  if (t->right) bt_inorder(t->right, depth+1);
  if (depth && !isleaf) putchar(')');
}

int main() {
  read(n); getchar();
  int rootid = (n + 1) * n >> 1;
  forp(i, 1, n) {
    scanf("%s", data[i]); read(l); read(r); getchar();
    if (l != -1) rootid -= l; left[i] = l;
    if (r != -1) rootid -= r; right[i] = r;
  }
  Node* t = bt_create(rootid);
  bt_inorder(t, 0);
}