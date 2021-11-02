#include <stdio.h>
#include <string.h>
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define inputs(x) scanf("%s",&x);getchar()
#define prti(x) printf("%d", x)
#define MAXLEN 10000

// 2021/08/19 

static inline int min(int a, int b, int c) {
  if (b < a) a = b;
  if (c < a) a = c;
  return a;
}

char s[MAXLEN], t[MAXLEN];
int dp[MAXLEN][MAXLEN] = { 0 };

int main() {
  inputs(s); inputs(t);
  int lens = strlen(s), lent = strlen(t);

  forp (i, 1, lent) dp[0][i] = i;
  forp (j, 1, lens) dp[j][0] = j;

  forp (i, 1, lens)
    forp (j, 1, lent)
      if (s[i-1] == t[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1;

  prti(dp[lens][lent]);
}
