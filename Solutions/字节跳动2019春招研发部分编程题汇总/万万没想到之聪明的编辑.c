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
#define inputs(x) scanf("%s",&x); getchar();
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prts(x) printf("%s", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void* b){return *((int*)a)-*((int*)b);}
#define MAXN 100000

// 2021/08/09 

int main() {
  char str[MAXN+1];
  read(n); getchar();
  times(n) {
    inputs(str); int len = strlen(str);
    if (len <= 2) { prts(str); prtl(); continue; }

    char *p = str, *q = str;
    while (*p) {
      if (*(p+3) && *p == *(p+1) && *(p+2) == *(p+3) && *p != *(p+2)) {
        times(3) *q++ = *p++;
        q--;
      } else {
        char *r = p + 1;
        while (*r == *p) r++;
        int d = r - p;      // cnt of continous same char
        //prti(d); prtl();
        //printf("p = %c = %p\n", *p, p);
        //printf("r = %c = %p\n", *r, r);
        if (d > 2) {
          times(2) *q++ = *p;
          p = r;
        } else {
          times(d) *q++ = *p++;
        }
      }
    }

    *q = '\0';
    prts(str); prtl();
  }
}
