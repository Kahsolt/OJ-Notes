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
#define inputf(x) scanf("%lf",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prtf(x) printf("%.2f", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prtf(x[i]);}
int cmp(const void* a,const void *b){return *((double*)a)-*((double*)b);}
#define N 10000
/* Chain the Ropes (25) */

double x[N];
int main() {
  read(n); forr(i, 0, n) inputf(x[i]);
  qsort(x, n, sizeof(double), cmp);
  double ans = 0.0;
  forr(i, 1, n)
    x[i] = (x[i-1] + x[i]) / 2;
  prti((int)floor(x[n-1]));
}
