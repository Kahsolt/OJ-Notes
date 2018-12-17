#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 1000
#define NCHAR 26

// 2018-08-07
// 最长公共子串
//
// F[i][j] = a[i]==b[j] ? F[i-1][j-1]+1 : 0;

char* substring;
int lcss(char* a, char* b) {
  int ans = 0, lenb = strlen(b);
  size_t sz = (lenb + 1) * sizeof(int);   // 状态压缩
  int* dp = malloc(sz); memset(dp, 0x00, sz);

  for (int i=1; i<=strlen(a); i++)  // TODO: 逆序保证无后效性?
    for (int j=lenb; j>=1; j--) {
      dp[j] = a[i-1]==b[i-1] ? dp[j-1]+1 : 0;
      if (ans < dp[j]) {
        ans = dp[j];
        substring = &a[i-1];
      }
    }

  free(dp);
  return ans;
}
void print_lcss(int len) {
  substring -= len;
  while (len--) printf("%c", *(substring++));
  puts("");
}

int main() {
  srand(time(NULL));
  char a[N], b[N];

  int r = rand() % 10 + 1;
  while (r--) {
    int lena = rand() % N;
    for (int i=0; i<lena; i++)
      a[i] = rand() % NCHAR + 'a';
    a[lena] = '\0';
    int lenb = rand() % N;
    for (int i=0; i<lenb; i++)
      b[i] = rand() % NCHAR + 'a';
    b[lenb] = '\0';

    int ans = lcss(a, b);
    printf("lcs: %d\n", ans);
    print_lcss(ans);
  }

  return 0;
}