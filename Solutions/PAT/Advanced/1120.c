#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define N 10000
#define read(x) int x; scanf("%d", &x)

bool hash[N];
int main() {
  memset(hash, false, sizeof(hash));
  read(n);
  int maxs = 0, cnt = 0;
  while (n--) {
    read(m);
    int s = 0;
    while (m) {
      s += m % 10;
      m /= 10;
    }
    if (s > maxs) maxs = s;
    if (!hash[s]) cnt++;
    hash[s] = true;
  }
  printf("%d\n", cnt);
  if (cnt) for (int i=0; i<=maxs; i++)
    if (hash[i]) {
      printf("%d", i);
      if (--cnt) printf(" ");
    }
}
