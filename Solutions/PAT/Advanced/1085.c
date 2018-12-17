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
#define N 100000
/* Perfect Sequence (25) */

int data[N];
int main() {
  int maxx, minn;
  read(n); read(p); forr(i, 0, n) {
    read(x); data[i] = x;
    if (!i) maxx = minn = x;
    else if (x > maxx) maxx = x;
    else if (x < minn) minn = x;
  }
  // TODO: problem desciption not comprehended
  prti((maxx<=minn*p) ? n : 0);
}