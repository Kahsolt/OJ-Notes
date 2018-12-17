#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define N 500000
/* Look-and-say Sequence (20) */

int main() {
  int d, n;
  scanf("%d%d", &d, &n);

  /* rolling array since strcpy() leads to TLE */
  char ans[2][N]; memset(ans, 0x00, sizeof(ans));
  int src = 0;  /* rolling array current workset pointer */
  ans[src][0] = d + '0'; /* save digit '0'~'9', init ans */
  
  while (--n) { /* rest n-1 round */
    int dst = src ^ 1;
    ans[dst][0] = '\0';
    char* p = ans[src];
    while (*p != '\0') {
      int cnt = 1;
      while (*p == *(p+1)) { p++; cnt++; }
      char buf[500];
      sprintf(buf, "%c%d", *p++, cnt);
      strcat(ans[dst], buf);
    }
    src ^= 1;
  }
  printf("%s", ans[src]);
}