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
#define read(x) int x;scanf("%ld",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%ld", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 1000001
/* Median (25) */

int main() {
  long int* x = malloc(N * sizeof(long int)); if (!x) return 0;
  read(n); forr(i, N-n, N) scanf("%ld", &x[i]);  // put to end
  long int *p = &x[N-n], *q = x, *end = &x[N];
  read(m); forr(i, 0, m) {
    read(z);
    while (p!=end && *p<=z) *q++ = *p++;  // merge
    *q++ = z;
  }
  while (p != end) *q++ = *p++;   // fill the rest
  n += m;
  // prta(x, 0, n); prtl();
  prti((n&1) ? x[n>>1] : (x[n>>1]+x[(n>>1)-1])>>1);
}
/*
int main() {
  read(n); int* x = malloc(n * sizeof(long int));
  forr(i, 0, n) scanf("%d", &x[i]);
  read(m); int* y = malloc((n + m) * sizeof(long int));
  int *p = x, *q = y;
  forr(i, 0, m) {
    read(z);
    while ((p-x<n) && *p <= z) *q++ = *p++;  // merge
    *q++ = z;
  }
  while (p - x < n) *q++ = *p++;
  n += m;
  prti((n&1) ? y[(n-1)>>1] : (y[n>>1]+y[(n>>1)-1])>>1);
}
*/
/*
long int x[N], y[N];
int main() {
  read(n); forr(i, 0, n) scanf("%d", &x[i]);
  read(m); forr(i, 0, n) scanf("%d", &y[i]);
  int xleft = 0, xright = n - 1, xlen = n;
  int yleft = 0, yright = m - 1, ylen = m;
  while (xlen>=1 && ylen>=1) {
    int xidx = (xleft + xright) >> 1;
    int xhalf = xidx - xleft + 1;
    double xmid = (xlen & 1) ? x[xidx] : (x[xidx] + x[xidx+1]) / 2;
    int yidx = (yleft + yright) >> 1;
    int yhalf = yidx - yleft + 1;
    double ymid = (ylen & 1) ? y[yidx] : (y[yidx] + y[yidx+1]) / 2;
    int half = min(xhalf, yhalf);
    if (xmid <= ymid) { xleft += half; yright -= half; }
    else { yleft += half; xright -= half; }
  }
}
*/