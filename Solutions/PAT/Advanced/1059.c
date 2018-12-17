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
#define input(x) scanf("%lu",&x)
#define read(x) UL x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 100000
/* Prime Factors (25) */

typedef unsigned long int UL;
UL factors[N];
int factors_cur = -1, factors_cnt[N] = { 0 };
int main() {
  read(n); 
  if (n==1 || n==2 || n==3 || n==5 || n==7) { // special case
    printf("%d=%d", n, n);
    return 0;
  }

  UL m = n;
  UL lastfac = 2;
  while (n >= 2) {
    for (UL i=lastfac; i<(n<<1); i++) {
      if (!(n%i)) {
        if (i!=lastfac || factors_cur==-1)
          factors[++factors_cur] = i;
        factors_cnt[factors_cur]++;
        n /= i;
        lastfac = i;
        break;
      }
    }
  }
  bool prtflag = false;
  printf("%ld=", m);
  forp(i, 0, factors_cur) {
    if (prtflag) putchar('*');
    else prtflag = true;
    printf("%lu", factors[i]);
    if (factors_cnt[i] > 1) printf("^%lu", factors_cnt[i]);
  }
}
