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
#define N 10000
#define C 50
#define DEBUG false

// 2021/08/09

bool cnt[C+1][N+2];

int main() {
  mset(cnt, false);
  read(n); read(m); read(c);
  forp (j, 1, n) {
    read(num_i); times(num_i) {
      read(cc); cnt[cc][j] = true;
    }
  }
  forp (i, 1, c) cnt[i][n+1] = cnt[i][1];     // make circle
  
  if (DEBUG)
  forp (i, 1, c) {
    forp (j, 1, n+1) {
      prti(cnt[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }

  int ans = 0;
  forp (i, 1, c) {   // check each color
    bool found = false;
    int p = 1, q = 2, cursum = 0;

    for (; q <= m && !found; q++) {
      cursum += cnt[i][q-1];
      if (cursum >= 2)
        found = true;
    }
    if (DEBUG) printf(">> i=%d, p=%d, q=%d\n", i, p, q);
    if (found) { ans++; continue; }

    for (; q <= n+1 && !found; q++, p++) {
      cursum += cnt[i][q];
      cursum -= cnt[i][p];
      if (cursum >= 2)
        found = true;
    }
    if (DEBUG) printf(">> i=%d, p=%d, q=%d\n", i, p, q);
    if (found) { ans++; continue; }
  }

  prti(ans);
}
