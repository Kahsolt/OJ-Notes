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
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 102
/* Are They Equal (25) */

char A[N], B[N];
int main() {
  read(n); scanf("%s%s", A, B);
  int lena = strlen(A), lenb = strlen(B);

  bool eql = true;
  char *p = A, *q = B;
  int k = n;
  while (eql && k) {
    if (*p != *q) eql = false;
    else if (*p == '.') k++;
    k--;
  }
  if (eql) printf("YES %s")
  
}