#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define inputs(x) scanf("%s",x)
#define N 100000+1

// 2021/08/09

char s[N];
int cntL = 0;

void die(bool ok) {
  puts(ok ? "YES" : "NO");
  exit(0);
}

int main() {
  inputs(s);
  char *p = s;
  while (*p) {
    if (*p != '(' && *p != ')') die(false);

    if (*p == '(') cntL++;
    else {
      if (cntL <= 0) die(false);
      else cntL--;
    }

    p++;
  }
  die(!cntL);
}
