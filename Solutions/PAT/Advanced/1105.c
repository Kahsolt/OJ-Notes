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
/* Spiral Matrix (25) */


int data[N];
int matrix[N][N] = { 0 };
int main() {
  read(n);
  int w = ceil(sqrt(n));
  while (n % w) w--;
  int h = n / w;
  if (h < w) swap(h, w);

  forr(i, 0, n) input(data[i]);
  qsort(data, n, sizeof(int), cmp);
  int x = 0, y = -1, dir = 0;
  while (n) {
    while (dir == 0 && (y + 1 >= w || matrix[x][y+1])
        || dir == 1 && (x + 1 >= h || matrix[x+1][y])
        || dir == 2 && (y - 1 < 0 || matrix[x][y-1])
        || dir == 3 && (x - 1 < 0 || matrix[x-1][y]))
      dir = (dir + 1) % 4;  // turn clockwise, if boundary exceeded or already filled
    switch (dir) {
      case 0: y++; break;  // right
      case 1: x++; break;  // down
      case 2: y--; break;  // left
      case 3: x--; break;  // up
    }
    // printf("(%d, %d)\n", x, y);
    matrix[x][y] = data[--n]; // big numbers first
  }

  forr(i, 0, h) {
    forr(j, 0, w) {
      if (j) putchar(' ');
      prti(matrix[i][j]);
    }
    prtl();
  }
}