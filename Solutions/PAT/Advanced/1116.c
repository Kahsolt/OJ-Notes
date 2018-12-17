#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 10000
/* Come on! Let's C (20) */

char entry[N];  /* id 0000~9999 */
bool check[N], prime[N+1];  /* rank 1~n */
int main() {
  memset(entry, 0x00, sizeof(entry)); /* default absent */
  memset(check, false, sizeof(check));
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int i=2; i<N; i++)
    if (prime[i])
      for (int j=i<<1; j<=N; j*=i)
        prime[j] = false;

  int n; scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    int x; scanf("%d", &x);
    if (i == 1) entry[x] = 1;
    else if (prime[i]) entry[x] = 2;
    else entry[x] = 3;
  }
  int k; scanf("%d", &k);
  while (k--) {
    int x; scanf("%d", &x);
    printf("%04d: ", x);
    if (!entry[x]) puts("Are you kidding?");
    else if (check[x]) puts("Checked"); 
    else {
      check[x] = true;
      switch (entry[x]) {
        case 1: puts("Mystery Award"); break;
        case 2: puts("Minion"); break;
        case 3: puts("Chocolate"); break;
      }
    } 
  }
}