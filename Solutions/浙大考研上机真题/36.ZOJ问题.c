#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define NSTR 1001
#define AC "Accepted"
#define WA "Wrong Answer"

/*
  check if str[] ~= /AzBojA{#B+1}/, where
  A and B is composed of any times of char 'o',
  and #B is the length of B.

  OPTIMIZE: check if str[] ~= /AzBjA{#B}/
*/

static inline bool check(char *s, size_t len) { // check if all 'o'
  for (int i=0; i<len; i++)
    if (s[i] != 'o')
      return false;
  return true;
}
int main() {
  char str[NSTR]; while (gets(str)) {
    char* z = strchr(str, 'z');
    char* j = strchr(str, 'j');
    if (!z || !j) { puts(WA); continue; }

    size_t lena = z - str;
    size_t lenb = j - 1 - z;
    if (lena<0 || lenb<=0 || strlen(str) != 2 + lena * (lenb + 1) + lenb)
      { puts(WA); continue; }

    bool ok = true;
    if (lena) ok = check(str, lena) && check(j + 1, lena * lenb);
    if (lenb) ok = ok && check(z + 1, lenb);
    puts(ok ? AC : WA);
  }
}