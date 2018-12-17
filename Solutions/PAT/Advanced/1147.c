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
/* Heaps (30) */

int heap[N+1];
bool maxheap, minheap;
bool prtflag, ok;
void bt_heapchk(int cur, int n) {
  int left = cur << 1, right = left | 0x01;
  if (!ok && left <= n) {
    minheap |= heap[left] >= heap[cur];
    maxheap |= heap[left] <= heap[cur];
    if (maxheap ^ minheap) bt_heapchk(left, n);
    else ok = true;
  }
  if (!ok && right <= n) {
    minheap |= heap[right] >= heap[cur];
    maxheap |= heap[right] <= heap[cur];
    if (maxheap ^ minheap) bt_heapchk(right, n);
    else ok = true;
  }
}
void bt_postorder(int cur, int n) {
  int left = cur << 1, right = left | 0x01;
  if (left <= n) bt_postorder(left, n);
  if (right <= n) bt_postorder(right, n);
  if (prtflag) putchar(' ');
  else prtflag = true;
  prti(heap[cur]);
}
int main() {
  read(m); read(n); times(m) {
    forp(i, 1, n) input(heap[i]);
    maxheap = minheap = ok = false;
    bt_heapchk(1, n);
    if (maxheap && minheap) puts("Not Heap");
    else if (maxheap) puts("Max Heap"); 
    else puts("Min Heap");
    prtflag = false;
    bt_postorder(1, n);
    prtl();
  }
}
