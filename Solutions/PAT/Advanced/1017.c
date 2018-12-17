#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 10000
#define K 100
/* Queueing at Bank (25)  */

typedef struct customer {
  int atime;  /* arrive time (in seconds) */
  int ptime;  /* processing time (in seconds) */
} Customer;
Customer customers[N], *customer_cur = customers;
Customer* windows[K];

int cmp(const void* a, const void* b) { return ((Customer*)a)->atime - ((Customer*)b)->atime; }
int main() {
  read(n); read(k); getchar();
  int endtime = 17 * 3600;
  forr(i, 0, n) {
    int h, m, s, p; scanf("%d:%d:%d %d", &h, &m, &s, &p); getchar();
    customer_cur->atime = h * 3600 + m * 60 + s;
    customer_cur->ptime = p * 60;
    if (customer_cur->atime <= endtime) customer_cur++;
  }
  n = customer_cur - customers;
  qsort(customers, n, sizeof(Customer), cmp);

  int wtime = 0;  /* total wait time */
  int curtime = 8 * 3600;
  Customer* p = customers;
  while (true) {  /* simulate by second */
    int vaccnt = 0;
    forr(i, 0, k) {
      if (windows[i]) {
        windows[i]->ptime--;    /* reduce time slice */
        if (!windows[i]->ptime) /* clean if work done */
          windows[i] = NULL;
      }
      if (!windows[i] && p!=customer_cur) {   /* load task if vacant */
        wtime += (curtime - p->atime);
        windows[i] = p++;
      }
      if (!windows[i]) vaccnt++;  /* if still vacant.. */
    }
    if (vaccnt == k) break; /* all windows are vacant */
    curtime++;
  }
  printf("%.1f", wtime / 60.0 / n);
}