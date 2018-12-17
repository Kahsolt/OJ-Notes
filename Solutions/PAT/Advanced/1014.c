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
#define K 1001
#define N 20
#define M 21
/* Waiting in Line (30) */

int queues[N][M];  /* n: queues count, m: queues length */
int q_head[N], q_rear[N], q_size;
int ptime[K]; /* processing time for customer-i */
int dtime[K]; /* done time */
int main() {
  mset(dtime, 0xFF); mset(queues, 0xFF); 
  mset(q_head, 0x00); mset(q_rear, 0x00);
  int n, m, k, q; scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i=1; i<=k; i++) scanf("%d", &ptime[i]);
  
  q_size = m + 1;
  int customer_cur = 1; /* from 1 upto k */
  forr(i, 0, n*m)       /* init load tasks */
    if (customer_cur <= k) {
      int h = q_head[i%n];
      queues[i%n][h] = customer_cur++;
      q_head[i%n] = (h + 1) % q_size;
    }

  int curtime = 8 * 60, endtime = 17 * 60;
  while (curtime <= endtime) {
    curtime++;
    forr(i, 0, n) {
      int c = queues[i][q_rear[i]];
      if (c == -1) continue;
      ptime[c]--;   /* reduce time slice */
      if (!ptime[c]) {
        dtime[c] = curtime;
        queues[i][q_rear[i]] = -1; /* clean when done */
        q_rear[i] = (q_rear[i] + 1) % q_size;
      }
    }
    int vaccnt = 0;
    forr(i, 0, n) {
      int h = q_head[i], r = q_rear[i];
      if (h == r) vaccnt++;
      else if (customer_cur <= k 
              && (h + 1 + q_size) % q_size != r) { /* queue not full */
        queues[i][q_head[i]] = customer_cur++;  /* load new task */
        q_head[i] = (q_head[i] + 1) % q_size;
      }
    } 
    if (vaccnt == n) break; /* all queue vacant */
  }

  while (q--) {
    read(z);
    if (dtime[z] == -1) puts("Sorry");
    else printf("%02d:%02d\n", dtime[z] / 60, dtime[z] % 60);
  }
}