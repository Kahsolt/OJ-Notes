#include <stdio.h>
#include <stdbool.h>
#include <math.h>
/* Rational Arithmetic (20) */

typedef long long LL;
LL gcd(LL a, LL b) {
  if (a < b) a ^= b ^= a ^= b;
  if (!b) return 1;
  LL r = a % b;
  while (r) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}
void print(LL num, LL den) {
  if (!num) {
    putchar('0');
    return;
  }

  bool sign = (num < 0) ^ (den < 0);
  num = abs(num), den = abs(den);
  LL k = gcd(num, den);
  if (k > 1) { num /= k; den /= k; }

  if (sign) printf("(-");
  if (num < den)
    printf("%lld/%lld", num, den);
  else {
    printf("%lld", num / den);
    LL r = num % den;
    if (r) printf(" %lld/%lld", r, den);
  }
  if (sign) putchar(')');
}

int main() {
  LL n1, d1, n2, d2;
  scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
  
  print(n1, d1); printf(" + ");
  print(n2, d2); printf(" = ");
  print(n1 * d2 + d1 * n2, d1 * d2); putchar('\n');

  print(n1, d1); printf(" - ");
  print(n2, d2); printf(" = ");
  print(n1 * d2 - d1 * n2, d1 * d2); putchar('\n');

  print(n1, d1); printf(" * ");
  print(n2, d2); printf(" = ");
  print(n1 * n2, d1 * d2); putchar('\n');

  print(n1, d1); printf(" / ");
  print(n2, d2); printf(" = ");
  if (!n2) printf("Inf");
  else print(n1 * d2, d1 * n2);
  putchar('\n');
}