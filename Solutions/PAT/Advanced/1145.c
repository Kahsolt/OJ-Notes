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
/*  Hashing - Average Search Time (25) */

bool isprime(int x) {
  if (x <= 1) return false;
  if (x==2 || x==3 || x==5 || x==7) return true;
  forr(i, 2, sqrt(x)+1)
    if (!(x%i)) return false;
  return true;
}

int hash[T];
int main() {
  mset(hash, 0xFF);
  bool prtflag = false;

  read(t);  while (!isprime(t)) t++;
  read(n); read(m); times(n) {
    read(x); int h = x % t;
    bool ok = false;
    for (int i=0; !ok && i<t; i++) {
      int idx = (h + i * i) % t;  // Quadratic Probing
      if (hash[idx] == -1) {
        hash[idx] = x;
        ok = true;
      }
    }
    if (!ok) printf("%d cannot be inserted.\n", x);
  }
  int cnt = 0;
  times(m) {
    read(x); int h = x % t;
    bool ok = false;
    for (int i=0; !ok && i<t; i++) {
      cnt++;
      int y = hash[(h + i * i) % t];
      if (y == x) ok = true;
      else if (y == -1) break;
    }
  }
  printf("%.1f", (double) cnt / m);
}