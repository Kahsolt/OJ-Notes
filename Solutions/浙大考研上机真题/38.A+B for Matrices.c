#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prti(x) printf("%d\n", x)
#define N 10

int matrix[N][N];
bool unzerorow[N], unzerocol[N];
int main() {
  int n; while (~input(n)) {
    if (!n) break; read(m);
    mset(unzerorow, false); mset(unzerocol, false);
    
    forr(i, 0, n)
      forr(j, 0, m)
        input(matrix[i][j]);
    forr(i, 0, n)
      forr(j, 0, m) {
        read(x);
        if (x + matrix[i][j]) // if not zero
          unzerorow[i] = unzerocol[j] = true; // mark not zero
      }

    int cnt = n + m;
    forr(i, 0, n) cnt -= unzerorow[i];
    forr(i, 0, m) cnt -= unzerocol[i];
    prti(cnt);
  }
}