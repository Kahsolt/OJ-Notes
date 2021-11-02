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
#define N 100000
#define MOD 100000009
#define DEBUG true

// 2021/08/09 

typedef struct seg {
  int l, r;
  int v;
  struct seg *next;
} Seg;

Seg* new_seg(int l, int r, int v) {
  Seg *s = malloc(sizeof(Seg));
  s->l = l;
  s->r = r;
  s->v = v;
  s->next = NULL;
  return s;
}

void print_seg(Seg* p) {
  while (p) {
    printf("  [%d, %d]: v = %d\n", p->l, p->r, p->v);
    p = p->next;
  }
}

int main() {
  read(n); read(m);
  Seg *head = new_seg(-1, -1, -1);    // dummy head
  head->next = new_seg(0, n-1, 0);

  if (DEBUG) { print_seg(head->next); putchar('\n'); }

  forp (i, 1, m) {
    read(L); read(R);
    Seg *fp = head, *p = head->next; while (p) {
      if (p->l <= L && L <= p->r) break;
      p = p->next; fp = fp->next;
    }
    Seg *q = p; while (q) {
      if (q->l <= R && R <= q->r) break;
      q = q->next;
    }

    if (DEBUG) printf(">> p=[%d,%d] q=[%d,%d]\n", p->l, p->r, q->l, q->r);

    if (p == q) {   // 分裂
      if (p->l == L && p->r == R) {
        p->v = i;
      } else if (p->l == L) { // 左侧分裂
        Seg *n = new_seg(R + 1, p->r, p->v);  // 右侧seg的左边界缩小
        n->next = p->next; p->next = n;   // 插入p之前
        p->l = L; p->r = R; p->v = i;
      } else if (p->r == R) { // 右侧分裂
        Seg *n = new_seg(L, R, i);
        n->next = p->next; p->next = n;   // 插入p之后
        p->r = L - 1;         // 左侧seg的右边界缩小
      } else {    // 三分
        Seg *n = new_seg(L, R, i),
            *n2 = new_seg(R+1, p->r, p->v);
        n2->next = p->next; n->next = n2; p->next = n; // 三个串起来
        p->r = L - 1;
      }
    } else {    // 合并
      if (p->l < L) {   // 分裂左侧出来: modify p->r, then shift
        p->r = L-1;
        p = p->next;  // shift
      }
      if (true /*R <= q->r*/) {   // 分裂右侧出来: q->n, 左侧作为[L,R]节点
        if (q->next) {
          Seg *n = new_seg(R+1, q->r, q->v);
          n->next = q->next; q->next = n;
        }
      }
      while (p != q) {
        fp->next = p->next;
        free(p);
        p = p->next; fp = fp->next;
      }
      q->l = L; q->r = R; q->v = i;   // directly modify q
    }

    if (DEBUG) { print_seg(head->next); putchar('\n'); }
  }

  Seg *p = head->next;
  int ans = 0, base = 0;
  while (p) {
    ans = (ans + base * p->v) % MOD;
    p = p->next;
    base++;
  }

  prti(ans);
}
