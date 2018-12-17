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
#define N 1000
/* Complete Binary Search Tree (30) */

int data[N], nodes[N+1]; // root: nodes[1]
int cur = 0;
void cbst_create(int t, int n) {  // inorder traversal and put data
  int left = t << 1;
  int right = left | 0x01;
  if (left <= n) cbst_create(left, n);
  nodes[t] = data[cur++];
  if (right <= n) cbst_create(right, n);
}
int main() {
  read(n); forr(i, 0, n) input(data[i]);  // shape of CBST is fixed
  qsort(data, n, sizeof(int), cmp); // inorder of BST is full ordered
  cbst_create(1, n);
  prta(nodes, 1, n+1);  // level traversal of array-presented full BT is esay...
}
