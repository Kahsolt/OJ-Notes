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
#define MAXN 100000
#define MAXSTR 1000
#define MOD 7

// Number Sequence
static inline int f(int a, int b, int n) {
  if (n <= 2) return 1;
  int fm2 = 1, fm1 = 1, f;
  n -= 2; while (n--) {
    f = (a * fm1 + b * fm2) % 7;
    fm2 = fm1; fm1 = f;
  }
  return f;
}

int main() {
  int a, b, n; while(~scanf("%d%d%d", &a, &b, &n)) {
    if (!a & !b && !n) break;
    printf("%d\n", f(a % MOD, b % MOD, n));
  }
}