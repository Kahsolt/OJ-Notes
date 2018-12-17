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
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define N 100
#define NSTR 257
/* Kuchiguse (20) */

char lines[N][NSTR];
char* end[N];
int main() {
  read(n); getchar();
  int minlen = NSTR + 1; char* minstr;
  forr(i, 0, n) {
    gets(lines[i]);
    int len = strlen(lines[i]);
    if (len < minlen) { minlen = len; minstr = lines[i]; }
    end[i] = lines[i] + len - 1;
  }

  char* ans = NULL; 
  while (!ans && minlen) {
    char c = *end[0]--;
    for (int i=1; !ans && i<n; i++)
      if (*end[i] == c) end[i]--;
      else ans = end[i] + 1;
    minlen--;
  }
  puts(!ans ? minstr : *ans=='\0' ? "nai" : ans);
}