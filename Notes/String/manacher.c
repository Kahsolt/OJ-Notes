#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 100000

// 2018/08/07
// 最长回文串

int radius[N];  // radius[i]-1: 以s[i]为中心最长回文串的半径(减去)
int manacher(char* s) {
  memset(radius, 0x00, sizeof(radius));
  int len = strlen(s), len2 = len*2+1;
  char* t = malloc(len2 * sizeof(char));
  char *p = s, *q = t;
  while (*p != '\0') {  // insert a '\0' between each char in s
    *q++ = '\0'; *q++ = *p++;
  } *q = '\0';

  // TODO: 什么po算法???
  
  free(t);
}

int main() {

  return 0;
}