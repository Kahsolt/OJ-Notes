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
#define N 100

/* 1098 Insertion or Heap Sort (25) */
// incomplete

int init[N], partial[N];
bool ok = false;

void try_insert_sort(int n) {
  int i = n - 1, maxx = partial[i], maxidx = i;
  while (i>=0 && init[i]==partial[i]) {
    if (partial[i] > maxx)
      maxx = partial[maxidx=i];
    i--;
  }
  int j = i;
  while (j--)
    if (partial[j+1] < partial[j])
      return;
  
  puts("Insertion Sort"); ok = true;
  swap(partial[i+1], partial[maxidx]);
  prta(partial, 0, n);
}
void try_heap_sort(int n) {

}
int main() {
  read(n);
  forr(i, 0, n) input(init[i]);
  forr(i, 0, n) input(partial[i]);
  
  try_insert_sort(n);
  if (!ok) try_heap_sort(n);
}
