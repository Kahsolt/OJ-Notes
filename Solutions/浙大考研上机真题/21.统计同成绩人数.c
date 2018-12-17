#include <stdio.h>
#include <memory.h>
#define N 101

int grades[N];
int main() {
  int n; while(~scanf("%d", &n)) {
    if (!n) break;
    memset(grades, 0x00, sizeof(grades));
    while (n--) {
      int g; scanf("%d", &g);
      grades[g]++;
    }
    int k; scanf("%d", &k);
    printf("%d\n", grades[k]);
  }
}