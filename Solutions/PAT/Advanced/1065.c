#include <stdio.h>
#include <stdbool.h>
/* A+B and C (64bit) (20) */

typedef long long LL;
int main() {
  int n;
  scanf("%d", &n);
  for (int i=1; i<=n; i++) {
    LL a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);

    bool res;
    if (a>0 && b>0)
      res = (a+b<0 || a+b>c); // up overflow or satisfy '>'
    else if (a<0 && b<0)
      res = (a+b<0 && a+b>c); // not down overflow and satisfy '>'
    else res = a+b>c;
    
    printf("Case #%d: %s\n", i, res ? "true" : "false");
  }
}