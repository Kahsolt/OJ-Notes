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
#define N 10
#define DEBUG false

// 2021/08/09 

char cnt[N] = { 0 };
char tmp[N];

bool chk(int r) { // chk if cnt[] can be divided as four 顺子 and 刻子
  if (DEBUG) { printf("      >> "); prta(cnt, 1, N); prtl(); }
  forr (i, 1, N) {
    if (tmp[i] >= 3) {    // make a 刻子
      if (DEBUG) printf("    make (%d, %d, %d).\n", i, i, i);
      if (r == 1) return true;
      else {
        tmp[i] -= 3;
        int ok = chk(r - 1);
        if (ok) return true;
        tmp[i] += 3;
      }
    }
    else if (i+2<N && tmp[i]>=1 && tmp[i+1]>=1 && tmp[i+2]>=1) {
      if (DEBUG) printf("    make (%d, %d, %d).\n", i, i+1, i+2);
      if (r == 1) return true;
      else {
        tmp[i]--; tmp[i+1]--; tmp[i+2]--;
        int ok = chk(r - 1);
        if (ok) return true;
        tmp[i]++; tmp[i+1]++; tmp[i+2]++;
      }
    }
  }
  return false;
}

bool check() {
  memcpy(tmp, cnt, sizeof(cnt));
  return chk(4);
}

int main() {
  cnt[0] = -1;
  times(13) {
    int x; input(x);
    cnt[x]++;
  }

  bool found = false;
  forp (i, 1, 9) {
    cnt[i]++;  // if add the 14th card i
    if (DEBUG) printf(">> try add %d\n", i);
    forp (j, 1, 9)
      if (cnt[j] >= 2) {    // try j as 雀头
        cnt[j] -= 2;
        if (DEBUG) printf("  try %d as QueTou.\n", j);
        if (check()) {
          prti(i); putchar(' ');    // found a solution
          found = true;
          cnt[j] += 2;  // undo
          break;        // stop early
        }
        cnt[j] += 2;    // undo
      }
    cnt[i]--;  // undo
  }
  if (!found) putchar('0');
}
