#include <stdio.h>
#include <stdlib.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d", x)
#define MAXN 100000

// 2021/08/21 

typedef struct seg {
  int x, y;
} Seg;

int cmp(const void* a,const void* b) {
  Seg *sa = (Seg*) a, *sb = (Seg*) b;
  return sa->x == sb->x
          ? sa->y > sb->y
          : sa->x > sb->x;
}

Seg segs[MAXN];

int main() {
  read(n); read(L);
  forr (i, 0, n) {
    input(segs[i].x);
    input(segs[i].y);
  }

  qsort(segs, n, sizeof(Seg), cmp);
  if (segs[0].x) {
    puts("-1");
    return 0;
  }

  //forr (i, 0, n) printf("[%d, %d]\n", segs[i].x, segs[i].y);

  int ans = 0, lend = 0;
  int p = 0;
  while (lend < L) {
    while (p<n && segs[p].x <= lend) p++;
    Seg *s = &segs[p-1];
    if (s->x <= lend) {
      //printf(" >> use [%d, %d]\n", s->x, s->y);
      lend = s->y;   // use this seg
      ans += 1;
    } else break;
  }

  if (lend >= L)
    prti(ans);
  else
    puts("-1");
}
