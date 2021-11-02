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
#define MAXN 100000

// 2021/08/18 

int a[MAXN];

int main() {
  int n = 0, x;
  while (~scanf("%d", &x)) { a[n++] = x; getchar(); getchar(); }
  
  int res = a[0];
  forr (i, 1, n) {
    if (a[i-1] > 0) a[i] += a[i-1];
    if (a[i] > res) res = a[i];
  }
  prti(res);
}
