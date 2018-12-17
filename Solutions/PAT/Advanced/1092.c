#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 1001
#define M 62
/* To Buy or Not to Buy (20) */

/* map color '0-9a-zA-Z' to number by base 62(=10+26+26)*/
int have[M] = { 0 }, need[M] = { 0 };
int hash(char c) {
  if ('0'<=c && c<='9') return c & 0x0F;
  if ('a'<=c && c<='z') return 10 + c - 'a';
  if ('A'<=c && c<='Z') return 36 + c - 'A';
}
int main() {
  char c;
  while (c = getchar()) {
    if (c == '\n') break;
    have[hash(c)]++;
  }
  while (c = getchar()) {
    if (c == '\n') break;
    need[hash(c)]++;
  }
  int extras_cnt = 0, missing_cnt = 0;
  forr(i, 0, M) {
    if (need[i]) {
      if (have[i] > need[i]) extras_cnt += have[i] - need[i];
      else if (have[i] < need[i]) missing_cnt += need[i] -  have[i];
    } else extras_cnt += have[i];
  }
  if (missing_cnt) printf("No %d", missing_cnt);
  else printf("Yes %d", extras_cnt);
}