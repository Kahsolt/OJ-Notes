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
#define M 10000
/* Damn Single (25) */

typedef struct couple {
  int x, y;
} Couple;
Couple couples[N], *couple_cur = couples;
bool presence[N] = { false }; // mark who presence
int main() {
  read(n); times(n) {
    read(x); read(y);
    couple_cur->x = x;
    couple_cur->y = y;
    couple_cur++;
  }
  int minid = M, maxid = -1;  // opt
  read(m); forr(i, 0, m) {
    read(id); presence[id] = true;
    if (id > maxid) maxid = id;
    else if (id < minid) minid = id;
  }

  Couple* p = couples;
  while (p != couple_cur) {
    if (presence[p->x] && presence[p->y]) {
      presence[p->x] = presence[p->y] = false;
      m -= 2;
    }
    p++;
  }
  
  prti(m); prtl();
  bool prtflag = false;
  forp(i, minid, maxid) if (presence[i]) {
    if (prtflag) putchar(' ');
    else prtflag = true;
    printf("%05d", i);
  }
}
