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
#define N 50000
/* Recommendation System (25) */

typedef struct item {
  int id, cnt;
  struct item *prev, *next;
} Item;
Item* items;
bool items_has[N] = { false };  // opt

void ll_print() {
  Item *it = items->next, *fit = items;
  putchar('>');
  while (it) {
    printf("%d ", it->id);
    fit = it;
    it = it->next;
  } putchar('|');
  it = fit;
  while (it != items) {
    printf(" %d", it->id);
    it = it->prev;
  } prtl();
}
void ll_insert(Item* it) {  // insert that make ascending ordered linklist
  Item *p = items->next, *fp = items;
  while (p && (p->cnt > it->cnt ||
      p->cnt == it->cnt && p->id < it->id)) {
    fp = p;
    p = p->next;
  }
  it->next = p; fp->next = it;
  it->prev = fp; if (p) p->prev = it;
}
void ll_bubleup(Item* it) {
  Item *p = it->prev;
  while (p != items && (it->cnt > p->cnt ||
      it->cnt == p->cnt && it->id < p->id)) {
    // printf("[%d:%d > %d:%d]\n", it->id, it->cnt, p->id, p->cnt);
    p->next = it->next; it->prev = p->prev;
    p->prev->next = it;
    if (it->next) it->next->prev = p;
    p->prev = it; it->next = p;
    p = it->prev; // reset
  }
}
int main() {
  items = malloc(sizeof(Item));  // dummy head node, left robin
  items->prev = items->next = NULL;

  read(n); read(k);
  forr(i, 0, n) {
    read(id);
    if (i) {
      printf("%d:", id);
      Item* p = items->next;
      int cnt = k; while (p && cnt--) {
        printf(" %d", p->id);
        p = p->next;
      } prtl();
    }

    if (items_has[id]) {  // node exists
      Item *p = items->next;
      while (p->id != id) p = p->next;
      p->cnt++;
      ll_bubleup(p);
    } else {  // new node
      Item* it = malloc(sizeof(Item));
      items_has[it->id = id] = true;
      it->cnt = 1;
      it->prev = it->next = NULL;
      ll_insert(it);
    }
    // ll_print();
  }
}