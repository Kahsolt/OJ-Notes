#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100000

/* Spell It Right (20) */

char* words[] = {
  "zero", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine",
};
char N[LENGTH];

int main() {
  memset(N, 0, sizeof(N));

  char c;
  while(~scanf("%c",&c)) {
    if (c == '\n') break;
    N[0] += c & 0x0F;             /* high precise add */
    for(int i=0; i<LENGTH; i++)   /* carry on */
      if (N[i] >= 10) {
        N[i+1] += N[i] / 10;
        N[i] %= 10;
      } else break;
  }
  int i = LENGTH - 1;
  while (i && !N[i]) i--;         /* find highest non-zero */
  for (;i>=0;i--) {
    printf("%s", words[N[i]]);
    if (i) printf(" ");
  }
}