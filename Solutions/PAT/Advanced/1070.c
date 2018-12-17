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
#define inputf(x) scanf("%lf",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prtf(x) printf("%.2f", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 1000
/* Mooncake (25) */

typedef struct mooncake {
  int amount;
  double price;
  double rate; // unit price = price / amount
} Mooncake;
Mooncake mooncakes[N];
int cmp(const void* a,const void *b) {  // '>'
  return ((Mooncake*)b)->rate - ((Mooncake*)a)->rate;
}

int main() {
  read(n); read(d);
  forr(i, 0, n) input(mooncakes[i].amount);
  forr(i, 0, n) {
    inputf(mooncakes[i].price);
    mooncakes[i].rate = mooncakes[i].price / mooncakes[i].amount;
  }
  qsort(mooncakes, n, sizeof(Mooncake), cmp);
  double ans = 0.0;
  Mooncake* p = mooncakes;
  while (d)
    if (p->amount > d) {
      ans += (double) p->price * d / p->amount ;
      d -= d;
    } else {
      ans += p->price;
      d -= p->amount;
      p++;
    }
  prtf(ans);
}
