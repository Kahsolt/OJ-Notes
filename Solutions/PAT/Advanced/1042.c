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
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 54
/* Shuffling Machine (20) */

int ans[2][N] = { 0 }, src = 0;
int box[N];
int main() {
  read(n);
  forr(i, 0, N) {
    input(box[i]); box[i]--;
    ans[src][i] = i;
  }
  times(n) {
    int dst = src ^ 1;
    forr(i, 0, N)
      ans[dst][box[i]] = ans[src][i];
    src ^= 1;
  }
  char category[] = { 'S', 'H', 'C', 'D', 'J' };
  forr(i, 0, N) {
    if (i) putchar(' ');
    int v = ans[src][i];
    printf("%c%d", category[v / 13], v % 13 + 1);
  }
}
