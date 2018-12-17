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
#define N 20
#define NSTR 3
/* Complete Binary Tree (25) */

bool ok = true;
int nodes[N+1], left[N], right[N];
void bt_create(int cur, int id, int n) {
  int l = cur << 1, r = l | 0x01;
  nodes[cur] = id;
  if (left[id] != -1) {
    if (l > n) ok = false;
    else bt_create(l, left[id], n);
  }
  if (ok && right[id] != -1) {
    if (r > n) ok = false;
    else bt_create(r, right[id], n);
  }
}

int main() {
  mset(nodes, 0xFF); mset(left, 0xFF); mset(right,0xFF);

  read(n); getchar(); int root = n * (n - 1) >> 1;
  forr(i, 0, n) {
    char l[NSTR], r[NSTR]; scanf("%s %s", l, r); getchar();
    int lidx = -1, ridx = -1;
    if (l[0] != '-') sscanf(l, "%d", &lidx);
    if (r[0] != '-') sscanf(r, "%d", &ridx);
    if (lidx==-1 ^ ridx==-1) ok = false;
    if (lidx != -1) root -= left[i] = lidx;
    if (ridx != -1) root -= right[i] = ridx;
  }
  if (ok) bt_create(1, root, n);
  for (int i=1; ok && i<=n; i++)
    if (nodes[i] == -1) ok = false;

  if (ok) printf("YES %d", nodes[n]);
  else printf("NO %d", root);
}