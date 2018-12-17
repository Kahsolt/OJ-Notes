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
#define N 50001
/* Postorder Traversal (25) */

bool ok = false;
int preorder[N], inorder[N];
void bt_parse(int ps, int pe, int is, int ie) { // just find the first leaf node
  int root = preorder[ps];
  int idx = -1;
  forp(i, is, ie)
    if (inorder[i] == root)
      { idx = i; break; }
  if (idx == -1) abort();
  
  //printf("root = %d, idx = %d | pre: <%d %d>, in: <%d %d>\n",
  //      root, idx, ps, pe, is, ie);

  int leftcnt = idx - is;
  int rightcnt = ie - idx;
  if (!leftcnt && !rightcnt)
    { prti(root); ok = true; }
  if (!ok && leftcnt) bt_parse(ps+1, ps+leftcnt, is, idx-1);
  if (!ok && rightcnt) bt_parse(ps+1+leftcnt, pe, idx+1, ie);
}

int main() {
  read(n);
  forp(i, 1, n) input(preorder[i]);
  forp(i, 1, n) input(inorder[i]);
  bt_parse(1, n, 1, n);
}
