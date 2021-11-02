#include <stdio.h>
#include <stdlib.h>
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define input(x) scanf("%lld",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%lld", x)
#define N 1000
#define DTYPE long long

// 2021/08/09 
// WA： 0/10

DTYPE A[N+1][N+1];
DTYPE A2[N+1][N+1];

int main() {
  read(n); read(m);
  forp (i, 1, n)
    forp (j, 1, m) {
      input(A[i][j]);
      A2[i][j] = A[i][j] * A[i][j];
    }

  forp (i, 1, n) {
    int t = 1;
    forp (j, 1, m)
      t *= A[i][j];
    A[i][0] = t;
  } 
  forp (j, 1, m) {
    int t = 1;
    forp (i, 1, n)
      t *= A[i][j];
    A[0][j] = t;
  }

/*
  forp (i, 0, n) {
    forp (j, 0, m) {
      prti(A[i][j]);
      putchar(' ');
    }
    putchar('\n');
  }
*/

  int ans = 0;
  forp (i, 1, n)
    forp (j, 1, m) {
      if (A2[i][j] > 0) {

        int newans = A[i][0] * A[0][j] / A2[i][j];
        ans = newans > ans ? newans : ans;
      }
    }
  prti(ans);
}
