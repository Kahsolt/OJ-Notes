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
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 50
#define M 10000
/* Set Similarity (25) */

typedef struct set {
  int size;
  int data[M];
} Set;
Set sets[N];

void setify(Set* set) {
  int k = 1, i = 1;
  while (i < set->size) {
    while (set->data[i] == set->data[i-1]) i++;
    set->data[k++] = set->data[i++];
  }
  set->size = k;
}
int main() {
  read(n); forr(i, 0, n) {
    read(k); sets[i].size = k;
    forr(j, 0, k) input(sets[i].data[j]);
    qsort(sets[i].data, k, sizeof(int), cmp);
    setify(&sets[i]);
  }

  read(k); times(k) {
    read(x); read(y);
    Set *s1 = &sets[--x], *s2 = &sets[--y];
    if (s1->size > s2->size) { Set* tmp=s1;s1=s2;s2=tmp; }
    int cnt_intersect = 0, cnt_union = s2->size;
    forr(i, 0, s1->size)
      if (bsearch(&s1->data[i], s2->data, s2->size, sizeof(int), cmp))
        cnt_intersect++;
      else cnt_union++;
    printf("%.1f%%\n", (double) cnt_intersect * 100 / cnt_union);
  }
}
