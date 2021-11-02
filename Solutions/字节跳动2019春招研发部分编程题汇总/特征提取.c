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
#define N 100000

typedef struct point {
  int x, y;
} Point;

bool operator==(Point p1, Point p2) {
  return p1.x == p2.x && p1.y == p2.y; 
}

int main() {
  read(n);
  times(n) {
    int ans = 0;
    read(m);
    times(m) {
      read(c);
      times(c) {
        read(x, y);
        
      }
    }
  }
  
}
2021/08/09 
