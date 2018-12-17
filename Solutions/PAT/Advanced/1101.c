#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define max(a, b) (((a)>=(b))?(a):(b))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define N 100000
/* Quick Sort (25) */

int data[N];
int left_max[N], right_min[N];  // dp[]
int ans[N], ans_cnt = 0;
int main() {
  read(n); forr(i, 0, n) input(data[i]);

  left_max[0] = data[0];
  forr(i, 1, n) 
    left_max[i] = max(data[i], left_max[i-1]);
  right_min[n-1] = data[n-1];
  for (int i=n-2; i>=0; i--)
    right_min[i] = min(data[i], right_min[i+1]);
  
  forr(i, 0, n)
    if (left_max[i] == right_min[i])
      ans[ans_cnt++] = data[i];
  qsort(ans, ans_cnt, sizeof(int), cmp);

  prti(ans_cnt); prtl();
  forr(i, 0, ans_cnt) {
    if (i) putchar(' ');
    prti(ans[i]);
  }
}