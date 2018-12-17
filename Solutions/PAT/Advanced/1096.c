#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prti(x) printf("%d", x)
#define prtl() putchar('\n')
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar('*');printf("%d",x[i]);}
#define N 100000
/* Consecutive Factors (20) */

int fac[N], cur = 0;
int main() {
  read(n); mset(fac, 0xFF);
  forr(i, 2, n<<1)
    if (!(n%i))
      fac[cur++] = i;
  
  int len = 1, base = 0, maxlen = 0, maxbase = -1;
  int tmp = fac[base];
  forr (j, 0, cur)
    if (fac[j] == fac[j-1]+1) {
      tmp *= fac[j];
      if (tmp <= n) len++;
    } else {
      if (len > maxlen) {
        maxlen = len;
        maxbase = base;
      }
      len = 1; tmp = fac[base=j];  /* reset */
    }

  prti(maxlen); prtl();
  prta(fac, maxbase, maxbase+maxlen)
}