#include <stdio.h>
#include <string.h>
#define N 100001
#define MOD 1000000007

/* 1093 Count PAT's (25) */

int cnt_left_P[N], cnt_right_T[N];
char str[N];
int main() {
  gets(str);
  int len = strlen(str);
  if (len < 3) { putchar('0'); return 0; }
  
  for (int i=0; i<len; i++)
    cnt_left_P[i] = (i ? cnt_left_P[i-1] : 0)
      + (str[i] == 'P');
  for (int i=len-1; i>=0; i--)
    cnt_right_T[i] = (i<len-1 ? cnt_right_T[i+1] : 0)
      + (str[i] == 'T');

  int ans = 0;
  for (int i=0; i<len; i++) if (str[i] == 'A')
    ans = (ans + (cnt_left_P[i] * cnt_right_T[i]) % MOD) % MOD;
  printf("%d", ans);
}