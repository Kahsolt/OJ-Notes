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
#define N 1001
/* Stucked Keyboard (20) */

int main() {
  read(k); getchar();
  char str[N]; gets(str);
  size_t len = strlen(str);
  
  forr(i, 0, len) {
    if (str[i] == -1) continue;
    if (i==0 && str[i]!=str[i+1]
        || str[i-1]!=str[i] && str[i]!=str[i+1]
        || i==len-1 && str[i-1]!=str[i])  {
      char c = str[i];  /* str[i] appeared singularly, is not stucked */
      forr(j, 0, len)
        if (str[j] == c) /* wipe out all same chars */
          str[j] = -1;
    }
  }

  char ans[N], ans_cur = 0;
  bool flag[1<<7]; mset(flag, false);
  int cnt = 1;
  forr(i, 1, len) {
    if (str[i-1]>=0 && str[i]==str[i-1]) cnt++;
    else if (str[i] != str[i-1]) {
      char c = str[i-1];
      if (c == -1) continue;
      if (!(cnt%k) && !flag[c]) { /* stuck keys count MUST be times of k */
        flag[ans[ans_cur++]=c] = true;
        cnt = 1;  /* reset */
      }
    }
  }

  forr(i, 0, ans_cur) putchar(ans[i]);
}