#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 1000
#define NCHAR 26

// 2018-08-07
// 最长公共子序列
//
//           / 0                          (i,j==0)
// F[i][j] = | F[i-1][j-1] + 1            (a[i]==b[j])
//           \ max(F[i-1][j], F[i][j-1])  (a[i]!=b[j])

int F[N][N];      // dp
char flag[N][N];  // direction (1: ↘, 2: ↓, 3 →)
int lcs(char* a, char* b) {
  int lena = strlen(a), lenb = strlen(b);
  memset(F, 0x00, sizeof(F)); // i,j==0的情况已经被初始化0
  memset(flag, 0x00, sizeof(F));

  for (int i=1; i<=lena; i++)
    for (int j=1; j<=lenb; j++)
      if (a[i-1] == b[i-1]) {
        F[i][j] = F[i-1][j-1] + 1;
        flag[i][j] = 1;
      } else if(F[i-1][j] > F[i][j-1]) {  // TODO: what if equal?
        F[i][j] = F[i-1][j];
        flag[i][j] = 2;
      } else {
        F[i][j] = F[i][j-1];
        flag[i][j] = 3;
      }
  return F[lena][lenb];
}
void print_lcs(int i, int j, char* a) {  // starts from F[i=lena][j=lenb], use a[] to print (b[] also OK)
  switch (flag[i][j]) {
    case 1: print_lcs(i-1, j-1, a);
            printf("%c", a[i]);     break;
    case 2: print_lcs(i-1, j, a);   break;
    case 3: print_lcs(i, j-1, a);   break;
  }
}

int lcs_compress(char* a, char* b) {
  int lena = strlen(a), lenb = strlen(b);
	int *dp[2]; size_t sz = (lenb + 1) * sizeof(int);
	dp[0] = malloc(sz); memset(dp[0], 0x00, sz);  // 状态压缩
	dp[1] = malloc(sz); memset(dp[1], 0x00, sz);

	for(int i=0; i<lena; i++) {
    int x = i & 1;  // x和y相反，x表示当前行，y表示下一行
    int y = x ^ 1;
		for(int j=0; j<lenb; j++)  // TODO: 无后效性：预填下一行??
			if(a[i] == b[j]) dp[y][j+1] = dp[x][j] + 1;
			else {
        dp[x][j+1] = __max(dp[x][j+1], dp[x][j]);
        dp[y][j] = __max(dp[y][j], dp[x][j]);
      }
  }

  // for(int i=0;i<lenb;i++) printf("%d ", dp[0][i]); puts("");
  // for(int i=0;i<lenb;i++) printf("%d ", dp[1][i]); puts("");

	int ans = dp[lena & 1][lenb];
	free(dp[0]); free(dp[1]);
	return ans;
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

    printf("lcs: %d\n", lcs(a, b));
    printf("lcs_compressed: %d\n", lcs_compress(a, b));
    print_lcs(lena, lenb, a); puts("");
    puts("====================================");
  }

  return 0;
}