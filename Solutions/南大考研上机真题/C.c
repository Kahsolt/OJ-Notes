#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MAXSTR 2001
#define max(x, y) (((x)>=(y))?(x):(y))

int f[MAXSTR+1][MAXSTR+1];
int LCS(char A[], char B[]) {
  f[0][0] = 0;  // memset(f, 0x00, sizeof(f));
  int lena = strlen(A), lenb = strlen(B);

  for (int i=1; i<=lena; i++)
    for (int j=1; j<=lenb; j++)
      if (A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1] + 1;
      else f[i][j] = max(f[i][j-1], f[i-1][j]);

  return f[lena][lenb];
}
int main() {
  char S[MAXSTR], T[MAXSTR], ANS[MAXSTR];
  int max_similarity = 0;
  
  scanf("%s", S); getchar();
  int n; scanf("%d", &n); getchar();
  while (n--) {
    scanf("%s", T); getchar();
    int sim = LCS(S, T);
    if (sim > max_similarity) {
      max_similarity = sim;
      strcpy(ANS, T);
    }
  }
  printf("%s\n%d\n", ANS, max_similarity);
}