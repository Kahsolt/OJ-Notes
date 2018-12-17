#include <stdio.h>
#include <stdbool.h>
#define NBUF 1000
/* General Palindromic Number (20) */

typedef unsigned long long ULL;
int main() {
  ULL n, r;
  scanf("%llu%llu", &n, &r);
  if (0<=n && n<r) {
    printf("Yes\n%llu", n);
    return 0;
  }

  ULL digits[NBUF];
  int len = 0;
  while (n) {
    digits[len++] = n % r;
    n /= r;
  }
  bool flag = true;
  int i = 0, j = len - 1;
  while (i < j) {
    if (digits[i] != digits[j]) {
      flag = false;
      break;
    }
    i++; j--;
  }

  puts(flag ? "Yes" : "No");
  for (int i=len-1; i>=0; i--) {
    printf("%llu", digits[i]);
    if (i) printf(" ");
  }
}