#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 30
#define NCHAR 10

int min_presention(char s2[], int len) {  // s2两倍串, len一倍串长
  int i = 0, j = 1, k = 0;  // i,j: cursor(初值可对调); k: common string length-1
  while (i<len && j<len && k<len) {
    if (s2[i+k] == s2[j+k]) k++;  // s2[i,i+k]==s2[j,j+k], 长度为k的字串相等则尝试更长的k
    else {
      // 方向重要：这个 < 就是 COMPAROR
      if (s2[i+k] < s2[j+k]) j += k+1;  // 以i开头的串比较小，保留i而移动j
      else i += k+1;
      if (i == j) j++; // 错位，assure i!=j; i++ is also OK
      k = 0;  // reset length
    }
  }
  // k==len时, s2[i..j-1]为s2的循环节，i和j对应的字符串相同
  // i或j==len时，较小者是解
  return __min(i, j);
}

int main() {
  srand(time(NULL));
  char s[N], s2[N<<1];
  
  int t = rand() % 10 + 1;
  while (t--) {
    int len = rand() % N + 1;
    for (int i=0; i<len; i++)
      s[i] = rand() % NCHAR + '0';
    s[len] = '\0';
    strcpy(s2, s); strcat(s2, s);
    printf("Original: %s\n", s);

    int start = min_presention(s2, len);
    printf("Minimal : ");
    for (int i=start; i<start+len; i++) 
      printf("%c", s2[i]);
    putchar(10);
    puts("====================================");
  }
}