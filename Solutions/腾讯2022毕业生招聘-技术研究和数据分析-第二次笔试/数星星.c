#include <stdio.h>
#define MANLEN 100000
#define UNTRACE

/*
8
SSTTAARR
*/

int n, ans = 0;
char s[MANLEN+1];
int pos[4] = { 0 };

void dfs(char* p, int d) {
  while (*p) {
    switch (d) {
    case 0: while (*p && *p!= 'S') p++; break;
    case 1: while (*p && *p!= 'T') p++; break;
    case 2: while (*p && *p!= 'A') p++; break;
    case 3: while (*p && *p!= 'R') p++; break;
    }
    if (!*p) break;
#ifdef TRACE
    pos[d]= p - s + 1;
#endif
      
    if (d == 3) {
      ans++;
#ifdef TRACE
      putchar('(');
      for (int i=0; i<4; i++) {
        printf("%d", pos[i]);
        if (i != 3) putchar(',');
      }
      puts(")");
#endif
    } else dfs(p + 2, d + 1);

    p++;
  }

}

int main() {
  scanf("%d", &n); getchar();
  gets(s);

  dfs(s, 0);

  printf("%d\n", ans);
}

