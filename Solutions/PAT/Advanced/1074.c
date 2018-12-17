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
#define N 100000
/* Reversing Linked List (25) */

typedef struct node {
  int data, next;
} Node;
Node nodes[N];

int main() {
  read(addr0); read(n); read(k);
  forr(i, 0, n) {
    read(addr);
    input(nodes[addr].data);
    input(nodes[addr].next);
  }

  int addr = addr0, lastaddr = -1;
  while (addr != -1) {
    int p = addr, cnt = k;
    while (p!=-1 && cnt) {
      p = nodes[p].next;
      cnt--;
    }
    if (!cnt) { // reversible
      int q = addr;
      times (k) {
        int r = nodes[q].next;
        nodes[q].next = p;  // magic shifting
        p = q;              // p moves backward to head
        q = r;  // q moves forward to next addr
      }
      if (addr == addr0) addr0 = p; // update linklist head
      if (lastaddr != -1)   // magic fix linkage
        nodes[lastaddr].next = p;
      lastaddr = addr;
      addr = q;
    } else break;
  }

  int p = addr0;
  while (p != -1) {
    printf("%05d %d ", p, nodes[p].data);
    if (nodes[p].next != -1) printf("%05d", nodes[p].next);
    else printf("-1");
    prtl();
    p = nodes[p].next;
  }
}