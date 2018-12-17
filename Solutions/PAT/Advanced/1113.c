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
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 100000
/* Integer Set Partition (25) */

int x[N];
int main() {
  int sum = 0;
  read(n); forr(i, 0, n) { input(x[i]); sum += x[i]; }
  qsort(x, n, sizeof(int), cmp);
  int halfsum = 0, anothersum = 0;
  forr(i, 0, n>>1) halfsum += x[i]; anothersum = sum - halfsum; 
  if (n & 0x01) {
    int diff1 = anothersum - halfsum;
    int halfsum2 = halfsum + x[n>>1];
    int anothersum2 = anothersum - x[n>>1];
    int diff2 = abs(anothersum2 - halfsum2);
    printf("1 %d", max(diff1, diff2));
  } else printf("0 %d", anothersum - halfsum);
}
