#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minNumber(char* str) {
  if (str == NULL) return 0;
  int len = strlen(str);
  if (!len) return 0;

  int ans = 0;
  char* p = str;
  while (*p) {
    if (*p == '1') {
      while (*p && *p == '1') p++;
      ans++;
    }
    while (*p && *p == '0') p++;
  }

  return ans;
}
