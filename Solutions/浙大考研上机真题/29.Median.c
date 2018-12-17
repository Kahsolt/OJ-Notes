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
#define N 1000000

int x[N];
int main() {
  int n; while (~input(n)) {
    forr(i, 0, n) input(x[i]);
    read(m); int cnt = n + m;
    forr(i, n, cnt) input(x[i]);
    qsort(x, cnt, sizeof(int), cmp);
    printf("%d\n", cnt & 0x01
        ? x[cnt>>1]
        : x[(cnt>>1)-1]);
  }
}