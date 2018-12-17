#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 11
#define NRADIX 36
#define max(a, b) (((a)>(b))?(a):(b))
/* Radix (25) */

typedef unsigned long long ULL;
ULL to_decimal(char *p, ULL rdx) {
  ULL ret = 0;
  while (*p != '\0') {
    ret *= rdx;
    if ('0'<=*p && *p<='9')
      ret += *p & 0x0F;   /* aka. (*p - '0') */
    else  /* aka. ('a'<=*p && *p<='z') */
      ret += *p - 'a' + 10;
    p++;
  }
  return ret;
}
int detect_min_radix(char *p) {
  int max_digit = 1;
  while (*p != '\0') {
    if ('0'<=*p && *p<='9')
      max_digit = max(max_digit, *p & 0x0F);
    else  /* aka. 'a'<=*p && *p<='z' */
      max_digit = max(max_digit, *p -'a' + 10);
    p++;
  }
  return max(max_digit + 1, 2); /* smallest radix is 2 */
}

int main() {
  size_t sz = N * sizeof(char);
  char* N1 = malloc(sz); memset(N1, 0x00, sz);
  char* N2 = malloc(sz); memset(N2, 0x00, sz);
  int tag, radix;
  
  scanf("%s%s%d%d", N1, N2, &tag, &radix);
  /* assure N1 has the kown radix */
  if (tag == 2) { char* tmp = N1; N1 = N2; N2 = tmp; }
  ULL num = to_decimal(N1, radix);

  bool found = false;
  ULL left = detect_min_radix(N2),
      right = max(left, num); /* radix no more than num */
  /* binary search for ans; enumerate [mix_radix(2)..INF] is also ok */
  while (!found && left<=right) {
    ULL mid = (left + right) >> 1;
    ULL k = to_decimal(N2, mid);
    if (k > num) right = mid - 1;
    else if (k < num) left = mid + 1;
    else {  /* found */
      printf("%d\n", mid);
      found = true;
    }
  }
  if (!found) puts("Impossible");
  free(N1); free(N2);
}