#include <stdio.h>
#include <string.h>
#define NSTR 101

char chr[3] = { 'Z', 'O', 'J'};
int cnt[3] = { 0 };
int main() {
  char str[NSTR], *p = str; gets(str);
  while (*p != '\0') {
    if (*p == 'Z') cnt[0]++;
    else if (*p == 'O') cnt[1]++;
    else cnt[2]++;
    p++;
  }
  int cur = 0;
  while (cnt[0] || cnt[1] || cnt[2]) {
    if (cnt[cur]) {
      putchar(chr[cur]);
      cnt[cur]--;
    }
    cur = (cur + 1) % 3;
  }
}