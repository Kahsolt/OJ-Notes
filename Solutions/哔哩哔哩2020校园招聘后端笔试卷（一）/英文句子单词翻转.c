#include <stdio.h>
#define MAXN 100000

// 2021/08/18 

char s[MAXN], *p = s;
int main() {
  gets(s);
  while (*p) p++; p--;
  while (p >= s) {
    while (p>=s && *p!=' ') p--;
    printf("%s ", p+1); 
    *p = '\0';
  }
}
