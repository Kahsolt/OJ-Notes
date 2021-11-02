#include <stdio.h>
#include <string.h>


/*
5
1 2 3 4
2 3 4 5
1 2 3 4 5
2 3 4 5 6
1 1 1 1 1
*/


int n;
int x[6]; // case 0 for count
int flag = 0;

void go(int l, int r, int *d) {
  printf("[%d, %d]\n", l, r);
  if (l == 0 && r == x[0] && *d == 24) {
    flag = 1;
    return;
  }

  if (l == r) *d = x[l];
  else for (int m=l+1; !flag && m<r; m++) {
    int x; go(l, m, &x);
    int y; go(m+1, r, &y);
    
    *d = x + y; go(l, r, d);
    *d = x - y; go(l, r, d);
    *d = x * y; go(l, r, d);
    if (y) { *d = x / y; go(l, r, d); }
  }
}

int main() {
    scanf("%d", &n); getchar();
    int ans = 0;
    for (int i=0; i<n; i++) {
      flag = 0;
      x[0] = 0;
      while (1) {
        scanf("%d", &x[x[0]++]);
        if (getchar() == '\n') break;
      }
      int d = 0;
      go(1, x[0], &d);
      ans += flag;
    }

    printf("%d", ans);
}