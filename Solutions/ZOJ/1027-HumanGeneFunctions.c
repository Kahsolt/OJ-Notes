#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#define N 101
#define NINF 0xF0
#define max(a, b) (((a)>=(b))?(a):(b))

int dp[N][N];     // the max match using A[1..i] and B[1..j]
char A[N], B[N];
char V[5][5]= {
        /* A   C   G   T   - */
  /* A */ { 5, -1, -2, -1, -3},
  /* C */ {-1,  5, -3, -2, -4},
  /* G */ {-2, -3,  5, -2, -2},
  /* T */ {-1, -2, -2,  5, -1},
  /* - */ {-3, -4, -2, -1, NINF},
};
int getv(char a, char b) {
  int x, y;
  switch (a) {
    case 'A': x = 0; break;
    case 'C': x = 1; break;
    case 'G': x = 2; break;
    case 'T': x = 3; break;
    default:  x = 4; break;
  }
  switch (b) {
    case 'A': y = 0; break;
    case 'C': y = 1; break;
    case 'G': y = 2; break;
    case 'T': y = 3; break;
    default:  y = 4; break;
  }
  return V[x][y];
}
int main() {
  int t;
  scanf("%d", &t); getchar();
  while (t--) {
    int lena, lenb;
    scanf("%d ", &lena);
    for (int i=0; i<lena; i++)
      scanf("%c", &A[i]);
    getchar();
    scanf("%d ", &lenb);
    for (int i=0; i<lenb; i++)
      scanf("%c", &B[i]);
    getchar();

    memset(dp, NINF, sizeof(dp));
    // for (int i=0; i<=lena; i++)
    //   for (int j=0; j<=lenb; j++)
    //     dp[i][j] = NINF;
    dp[0][0] = 0;
    for (int i=0; i<lena; i++)
      dp[i+1][0] = getv(A[i], '-');
    for (int j=0; j<lenb; j++)
      dp[0][j+1] = getv(B[j], '-');
    for (int i=0; i<lena; i++)
      for (int j=0; j<lenb; j++) {
        // on the base of dp[i][j]...
        //   1.use A[i] only
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + getv(A[i], '-'));
        //   2.use B[j] only
        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + getv(B[j], '-'));
        //   3.use A[i] and B[j] both
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + getv(A[i], B[j]));
      }
    // for (int i=0; i<=lena; i++) {
    //   for (int j=0; j<=lenb; j++)
    //     printf("%4d", dp[i][j]);
    //   puts("");
    // }
    printf("%d\n", dp[lena][lenb]);
  }
}