#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _n=n;while(_n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 100
#define K 300
/* PAT Ranking (25) */

typedef struct testee {
  char ID[14];
  int score;
  int final_rank;
  int loc_number;
  int local_rank;
} Testee;
Testee testees[N*K], *testees_base = testees, *testees_top = testees;

int cmp(const void* a, const void* b) {
  int sa = ((Testee*)a)->score;
  int sb = ((Testee*)b)->score;
  return sa != sb ? -(sa - sb)
                  : strcmp(((Testee*)a)->ID, ((Testee*)b)->ID);
}
int main() {
  int cnt = 0;
  read(n); getchar(); forp(loc, 1, n) {
    read(k); getchar(); cnt += k; times(k) {
      scanf("%s%d", &testees_top->ID, &testees_top->score); getchar();
      testees_top->loc_number = loc;
      testees_top++; 
    }
    qsort(testees_base, testees_top - testees_base,
          sizeof(Testee), cmp);
    Testee* p = testees_base;
    int rk = 0, ct = 1; /* rank and count of continuous same score */
    while (p != testees_top) {
      if (p == testees_base 
          || p->score != (p-1)->score) {  // new rank!
        rk += ct ; ct = 1;
        p->local_rank = rk;
      } else {
        ct++;
        p->local_rank = rk;
      }
      p++;
    }
    testees_base = testees_top;
  }
  qsort(testees, cnt, sizeof(Testee), cmp);

  prti(cnt); prtl();
  Testee* p = testees;
  int rk = 0, ct = 1; /* rank and count of continuous same score */
  while (p != testees_top) {
    if (p == testees 
        || p->score != (p-1)->score) {  // new rank!
      rk += ct ; ct = 1;
      p->final_rank = rk;
    } else {
      ct++;
      p->final_rank = rk;
    }
    printf("%s %d %d %d\n",
          p->ID, p->final_rank, p->loc_number, p->local_rank);
    p++;
  }
}
