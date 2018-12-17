#include <stdio.h>
#include <stdlib.h>
/* Elevator (20) */

int main() {
  int n, cur = 0, time = 0;
  scanf("%d", &n);
  while (n--) {
    int next;
    scanf("%d", &next);
    if (next > cur) {
      time += 5 + 6 * (next - cur);
      cur = next;
    } else if (next < cur) {
      time += 5 + 4 * (cur - next);
      cur = next;
    } else
      time += 5;
  }
  printf("%d\n", time);
}