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
#define max(a, b) (((a)>=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define inputs(x) scanf("%s",&x);getchar()
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define MAXN 5

// 2021/08/18 
int x[MAXN];

int main() {
  forr (i, 0, MAXN) input(x[i]);
  int ans = 0;
  bool found = true;
  while (found) {
    found = false;
    int cnt = 3;
    if (x[0] > 0) { x[0]--; cnt--; }
    else if (x[1] > 0) { x[0]--; cnt--; }

    if (x[4] > 0) { x[4]--; cnt--; }
    else if (x[3] > 0) { x[3]--; cnt--; }

    if (x[2] > 0) { x[2]--; cnt--; }
    else {
      if (x[1] == x[3]) {
        if (x[0] >= x[4]) {
          if (x[1] > 0) { x[1]--; cnt--; }
        } else {
          if (x[3] > 0) { x[3]--; cnt--; }
        }
      } else if (x[1] > x[3]) {
        if (x[1] > 0) { x[1]--; cnt--; }
      } else {
        if (x[3] > 0) { x[3]--; cnt--; }
      }
    }

    if (!cnt) { found = true; ans++; }
  }
  prti(ans);
}
