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
#define N 100
#define NBUF 1000000
/* Build A Binary Search Tree (30) */

int nodes[NBUF];  // FIX: maybe use linkage
int lchild[N], rchild[N];
int data[N], idx = 0;

void bst_create(int cur, int id) {
  int l = cur << 1, r = l | 0x01;
  if (lchild[id] != -1) bst_create(l, lchild[id]);
  nodes[cur] = data[idx++];
  if (rchild[id] != -1) bst_create(r, rchild[id]);
}
bool prtflag = false;
void bst_levelorder(int n) {
  for (int i=1; n && i<NBUF; i++)
    if (nodes[i] != -1) {
      if (prtflag) putchar(' ');
      else prtflag = true;
      prti(nodes[i]);
      n--;
    }
}
int main() {
  mset(nodes, 0xFF); mset(lchild, 0xFF); mset(rchild, 0xFF);
  read(n); forr(i, 0, n) { input(lchild[i]); input(rchild[i]); }
  forr(i, 0, n) input(data[i]); qsort(data, n, sizeof(int), cmp);
  bst_create(1, 0);
  bst_levelorder(n);
}