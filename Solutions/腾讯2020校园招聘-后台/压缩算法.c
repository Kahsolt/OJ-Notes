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
#define MAXLEN 100000

// 2021/08/16 

char tmp[MAXLEN];


void solve() {
  read(cnt); getchar(); // absorb '|'
  process();
}

void process() {
  int c;
  while ((c = getwchar()) != -1) {
    if (c != '[') putchar(c);
    else solve();
  }
}

int main() {
  process();
}

"HG[3|B[2|CA]]F"
  "[3|B[2|CA]]F"
  "    [2|CA]]F"