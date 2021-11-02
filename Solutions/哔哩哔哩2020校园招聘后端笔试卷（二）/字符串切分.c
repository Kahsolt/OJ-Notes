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
#define max(a, b) (((a)>=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define inputs(x) scanf("%s",&x);getchar()
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define MAXLEN 100000

//2021/08/19 

char s[MAXLEN];
char **pool;
int cnt = 0;

int main() {
  pool = (char**) malloc(MAXLEN*sizeof(char*));
  char sep_pr = getchar(); getchar();
  char sep_kv = getchar(); getchar();
  gets(s);
  char* p = s;

  while (*p) {
    char* q = p;
    while (*q && *q != sep_pr) q++; q--;
    if (*p == sep_kv || *q == sep_kv) {
      // ignore if k==null || v==null
    } else {
      int len = q - p + 2;
      pool[cnt] = malloc(len * sizeof(char));
      char* t = pool[cnt];
      while (p != q + 1) {
        if (*p == sep_kv) *t++ = ' ';
        else *t++ = *p;
        p++;
      }
      *t = '\0';
      cnt++;
    }
    p = q + 2;
  }

  prti(cnt); prtl();
  forr (i, 0, cnt)
    puts(pool[i]);
}
