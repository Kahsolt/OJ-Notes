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
#define MAX_N 10000

// 2021/08/15 

#include <stdio.h>
#include <stdbool.h>

bool flag[MAX_N+1] = { 0 };   // 0 for primes, 1 for factorable
int primes[MAX_N>>2] = { 0 }, cnt = 0;
int ans = 0;

void preprocess() {
  forp (i, 2, MAX_N>>1)
    if (!flag[i]) {
      int k = 2;
      while (i*k<=MAX_N) {
        flag[i*k] = 1;
        k++;
      }
    }
  forp (i, 2, MAX_N)
    if (!flag[i])
      primes[cnt++] = i;
}

int main() {
  int n; scanf("%d", &n);
  preprocess();

  forr (i, 0, cnt) {    // 从第i个素数开始的序列能否构成目标
    int j = i, tgt = n;
    if (primes[j] > tgt) break;   // stop early
    while (j < cnt && tgt > 0)
      tgt -= primes[j++];
    if (!tgt) ans++;
  }

  printf("%d\n", ans);
}
