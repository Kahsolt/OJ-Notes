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
#define N 104
/* Birds in Forest (25) */

int set[N+1];
bool flag[N+1] = { false }; // mark presence
static inline int root(int x) {
  return set[x]!=x ? set[x]=root(set[x]) : x;
}
int main() {
  read(n); forp(i, 1, N) set[i] = i;
  times(n) {
    read(k); read(x); flag[x] = true;
    while (--k) {
      read(y); flag[y] = true;
      set[root(y)] = root(x);
    }
  }
  int tcnt = 0, bcnt = 0; // count trees and birds
  forp(i, 1, N)
    if (flag[i]) {
      bcnt++;
      if (root(i) == i) tcnt++;
    }
  printf("%d %d\n", tcnt, bcnt);
  
  read(q); times(q) {
    read(x); read(y);
    puts(root(x) == root(y) ? "Yes" : "No");
  }
}
