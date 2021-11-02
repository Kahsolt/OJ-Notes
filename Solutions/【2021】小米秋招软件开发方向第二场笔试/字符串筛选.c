#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 2021/08/09 

static int bv[4] = { 0 };

static inline int getb(int i) { return bv[i/32] & (0x1 << i); }
static inline void setb(int i) { bv[i/32] |= (0x1 << i); }

char* unique_string(char* s) {
  char *p = s, *q = s;
  while (*p) {
    if (!getb(*p)) {
      setb(*p);
      if (p != q) *q = *p;
      q++;
    }
    p++;
  }
  *q = '\0';
  return s;
}

int main() {
  char s1[] = "aab";
  char s2[] = "hellowelcometoxiaomi";

  memset(bv, 0, sizeof(bv)); puts(unique_string(s1));
  memset(bv, 0, sizeof(bv)); puts(unique_string(s2));
}
