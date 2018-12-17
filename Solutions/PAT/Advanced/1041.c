#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _n=n;while(_n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 10001
/* Be Unique (20) */

bool presence[N];
int main() {
  mset(presence, false);
  read(n); read(ans); presence[ans] = true;
  forr(i, 1, n) {
    read(x);
    if ()
  }
  bool flag = false;
  forr(i, 0, n-1)
    if (x[i] != -1) {
      bool found = false;
      forr(j, i+1, n)
        if (x[j] == x[i]) {
          x[j] = -1;  /* erase */
          found = true;
        }
      if (!found) { prti(x[i]); flag = true; break; }
    }
  if (!flag) puts("None");
}
