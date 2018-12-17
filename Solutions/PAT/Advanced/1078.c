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
#define T 10000
/* Hashing (25) */

bool isprime(int x) {
  if (x <= 1) return false;
  if (x==2 || x==3 || x==5 || x==7) return true;
  forr(i, 2, sqrt(x)+1)
    if (!(x%i)) return false;
  return true;
}

bool hash[T] = { false };
int main() {
  bool prtflag = false;

  read(t);  while (!isprime(t)) t++;
  read(n); times(n) {
    read(x); int h = x % t, idx;
    bool ok = false;
    for (int i=0; !ok && i<t; i++) {
      idx = (h + i * i) % t;  // Quadratic Probing
      if (!hash[idx]) {
        hash[idx] = true;
        ok = true;
      }
    }
    
    if (prtflag) putchar(' ');
    else prtflag = true;
    if (!ok) putchar('-');
    else prti(idx);
  }
}
