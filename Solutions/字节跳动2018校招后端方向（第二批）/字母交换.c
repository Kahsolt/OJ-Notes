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
#define inputs(x) scanf("%s",x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define N 1000
#define NCHAR 26

// 2021/08/09 
// 有点像并查集??

typedef struct group {
  char c;
  int cnt;
} Group;

Group groups[NCHAR][1000];

char s[N+1] = { 0 };
int accseq[N] = { 0 };

int main() {
  inputs(s); read(m);
  char *p = s; while (*p) s[*p]++;
  
}
