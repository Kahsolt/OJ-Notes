#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define times(n) int _##n=n;while(_##n--)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define N 40000
#define K 2500
#define NHASH 26*26*26*10

/* Student List for Course (25) */

char names[NHASH][5];
static inline int hash(char* str) {
  return (*str - 'A') * 10 * 26 * 26
      + (*(str + 1) - 'A') * 10 * 26
      + (*(str + 2) - 'A') * 10
      + ((*(str + 3)) & 0x0F);
}

short count[K] = { 0 };
bool enroll[NHASH][K] = { false };
int main() {
  read(n); read(k); getchar();
  forr(i, 0, n) {
    char name[5]; scanf("%s", name);
    int h = hash(name);
    strcpy(names[h], name);
    read(c); times(c) {
      read(id); id--;
      count[id]++; enroll[h][id] = true;
    } getchar();
  }
  forr(i, 0, k) {
    int cnt = count[i];
    printf("%d %d\n", i + 1, cnt);
    for (int j=0; cnt && j<NHASH; j++)
      if (enroll[j][i]) {
        puts(names[j]);
        cnt--;
      }
  }
}