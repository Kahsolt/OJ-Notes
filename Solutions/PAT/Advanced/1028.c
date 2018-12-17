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
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 100000
/* List Sorting (25) */

typedef struct record {
  char ID[7];
  char name[9];
  int grade;
} Record;
Record records[N], *records_cur = records;

int cmp1(const void *a, const void *b) {
  return strcmp(((Record*)a)->ID, ((Record*)b)->ID);
}
int cmp2(const void *a, const void *b) {
  Record *ra = (Record*)a, *rb = (Record*)b;
  int ncmp = strcmp(ra->name, rb->name);
  return ncmp == 0 ? strcmp(ra->ID, rb->ID) : ncmp;
}
int cmp3(const void *a, const void *b) {
  Record *ra = (Record*)a, *rb = (Record*)b;
  int ga = ra->grade, gb = rb->grade;
  return  ga == gb ? strcmp(ra->ID, rb->ID) : ga - gb;
}
int main() {
  read(n); read(c); getchar();
  times(n) {
    scanf("%s %s %d", 
          records_cur->ID, records_cur->name, &records_cur->grade);
    getchar(); records_cur++;
  }
  
  switch (c) {
    case 1: qsort(records, n, sizeof(Record), cmp1); break;
    case 2: qsort(records, n, sizeof(Record), cmp2); break;
    case 3: qsort(records, n, sizeof(Record), cmp3); break;
  }
  Record* p = records;
  while (p != records_cur) {
    printf("%s %s %d\n", p->ID, p->name, p->grade);
    p++;
  }
}
