#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define N 100000

typedef struct record {
  int id; // filter use
  int golds, silvers, population;
  double golds_rate, silvers_rate;
  int rank, rank_type;
} Record;
Record *records[N], rec[N];
int cmpid(const void* a,const void* b) { return ((Record*)a)->id           - ((Record*)b)->id; }
int cmpg (const void* a,const void* b) { return ((Record*)b)->golds        - ((Record*)a)->golds; }
int cmps (const void* a,const void* b) { return ((Record*)b)->silvers      - ((Record*)a)->silvers; }
int cmpgr(const void* a,const void* b) { return ((Record*)b)->golds_rate   - ((Record*)a)->golds_rate; }
int cmpsr(const void* a,const void* b) { return ((Record*)b)->silvers_rate - ((Record*)a)->silvers_rate; }

void adjust_rank(Record* rec, int m, int type) {
  int rnk, cnt = 0; forr(i, 0, m) {
    cnt++;
    if (!i  || (type==1 && rec[i].golds         != rec[i-1].golds)
            || (type==2 && rec[i].silvers       != rec[i-1].silvers)
            || (type==3 && rec[i].golds_rate    != rec[i-1].golds_rate)
            || (type==4 && rec[i].silvers_rate  != rec[i-1].silvers_rate))
      rnk = cnt;
    if (rnk < rec[i].rank) {
      rec[i].rank = rnk;
      rec[i].rank_type = type;
    }
  }
}
int main() {
  int n, m; while (~scanf("%d%d", &n, &m)) {
    forr(i, 0, n) {
      int g, s, p; scanf("%d%d%d", &p, &s, &p);
      records[i] = malloc(sizeof(Record));
      records[i]->golds = g;
      records[i]->silvers = s;
      records[i]->population = p;
      records[i]->golds_rate = p ? g / p : 0; 
      records[i]->silvers_rate = p ? s / p : 0;
      records[i]->rank = n + 1;
    }
    forr(i, 0, m) {
      int z; scanf("%d", &z);
      memcpy(&rec[i], records[z], sizeof(Record));
      rec[i].id = i;
    }

    qsort(rec, m, sizeof(Record),  cmpg); adjust_rank(rec, m, 1);
    qsort(rec, m, sizeof(Record),  cmps); adjust_rank(rec, m, 2);
    qsort(rec, m, sizeof(Record), cmpgr); adjust_rank(rec, m, 3);
    qsort(rec, m, sizeof(Record), cmpsr); adjust_rank(rec, m, 4);
    qsort(rec, m, sizeof(Record), cmpid);
    forr(i, 0, m)
      printf("%d:%d\n", rec[i].rank, rec[i].rank_type);
    putchar(10);
  }
}