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
#define N 1025
/* Invert a Binary Tree (25) */

int nodes[N];
int lchild[10], rchild[10];
void bt_create_invert(int cur, int id) {
  if (id == -1) return;
  nodes[cur] = id;
  if (lchild[id] != -1) // use left val to build right sub-tree
    bt_create_invert((cur<<1)+1, lchild[id]);
  if (rchild[id] != -1)
    bt_create_invert(cur<<1, rchild[id]);
}
void bt_levelorder(int n) {
  for (int i=1; n && i<=N; i++) {
    if (nodes[i] != -1) {
      prti(nodes[i]);
      if (--n) putchar(' '); 
    }
  }
}
bool prtflag = false;
void bt_inorder(int cur) {
  if (nodes[cur] == -1) return;
  int l = cur << 1, r = l | 0x01;
  if (nodes[l] != -1) bt_inorder(l);
  if (prtflag) putchar(' ');
  else prtflag = true;
  prti(nodes[cur]);
  if (nodes[r] != -1) bt_inorder(r);
}
int main() {
  mset(nodes, 0xFF); mset(rchild, 0xFF); mset(lchild, 0xFF);
  read(n); getchar();
  int root = n * (n-1) >> 1;  // magic algbra methods
  forr(i, 0, n) {
    char l, r; scanf("%c %c", &l, &r); getchar();
    if (l != '-') { int nl = l & 0x0F; lchild[i] = nl; root -= nl; }
    if (r != '-') { int nr = r & 0x0F; rchild[i] = nr; root -= nr; }
  }
  bt_create_invert(1, root);
  bt_levelorder(n);
  prtl();
  bt_inorder(1);
}