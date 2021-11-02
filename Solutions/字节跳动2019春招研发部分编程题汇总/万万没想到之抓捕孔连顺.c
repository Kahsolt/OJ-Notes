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
#define MOD 99997867 

// 2021/08/09 

int x[N];
bool f[N];
int ans = 0;
int leftend = -1;

void dfs(int x[], int n, int p, int d, int r) {
  //printf("n=%d, p=%d, d=%d, r=%d\n", n, p, d, r);

  forr (i, p+1, n)
    if (!f[i] && (!i || x[i] - leftend <= d)) {
      //printf("select idx=%d x[i]=%d\n", i, x[i]);
      f[i] = true;   // set a person
      if (r == 3) leftend = x[i];  // if the first choice, save leftend loc
      if (r > 1) dfs(x, n, i, d, r - 1);  // if still need choice, rec!
      else ans = (ans + 1) % MOD; 
      f[i] = false;  // clear the set
    }
    else if (x[i] - x[p] > d) break;
}

int main() {
  mset(f, false);
  read(n); read(d);
  forr(i, 0, n) input(x[i]);
  qsort(x, n, sizeof(int), cmp);
  dfs(x, n, -1, d, 3);
  prti(ans);
}
