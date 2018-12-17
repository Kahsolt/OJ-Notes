#include <stdio.h>
#include <math.h>
/* Rational Sum (20) */

typedef long long LL;
LL gcd(LL a, LL b) {
  if (a < b) a ^= b ^= a ^= b;
  LL r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int main() {
  int n;
  scanf("%d", &n);

  LL num = 0, den = 1;  /* dummy init ans = 0/1 */
  while (n--) {
    LL x, y;
    scanf("%lld/%lld", &x, &y);
    num = num * y + den * x;
    den *= y;
    if (num) {  /* num!=0 , need reduce */
      LL k = gcd(abs(num), abs(den));
      num /= k;
      den /= k;
    }
  }

  if (num == 0) putchar('0');
  else if (num >= den) {
    printf("%lld", num / den);
    if (num % den)
      printf(" %lld/%lld", num % den, den);
  } else printf("%lld/%lld", num, den);
}