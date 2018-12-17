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
#define NSTR 9
#define K 10
#define N 10000
/*  Group Photo (25) */

typedef struct person {
  char name[NSTR];
  int height;
} Person;
Person persons[N], *persons_cur = persons;
int cmp(const void* a, const void *b) { // '<'
  Person *pa = (Person*)a, *pb = (Person*)b;
  int cmph = pa->height - pb->height;
  return cmph ? cmph : -strcmp(pa->name, pb->name);
}
Person* formation[K][N] = { NULL };
int count[K]; // person count in kth row

int main() {
  read(n); read(k); getchar();
  int cnt = n / k; forr(i, 0, k-1) count[i] = cnt;
  count[k-1] = n - cnt * (k - 1);
  times(n) {
    scanf("%s %d", persons_cur->name, &persons_cur->height);
    getchar(); persons_cur++;
  }
  qsort(persons, n, sizeof(Person), cmp);

  Person *pbase = persons, *ptop;
  forr(i, 0, k) {
    int cnt = count[i];
    pbase += cnt;
    ptop = pbase;
    int idx = cnt >> 1;
    int k = 0, dir = 1; // k: step length; dir: -1 left, 1 right
    forr(j, 0, cnt) {
      idx += k * dir;
      formation[i][idx] = --ptop;
      dir *= -1;  // reverse direction
      k += 1;     // add step
    }
  }

  for(int i=k-1; i>=0; i--) {
    int cnt = count[i];
    forr(j, 0, cnt) {
      if (j) putchar(' ');
      printf("%s", formation[i][j]->name);
    }
    prtl();
  }
}