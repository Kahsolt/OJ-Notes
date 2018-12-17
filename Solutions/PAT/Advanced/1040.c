#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _n=n;while(_n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
#define N 1005
/* Longest Symmetric String (25) */

char raw[N], str[N<<1];
int main() {
  gets(raw); int len = strlen(raw);
  char *p = raw, *q = str;
  *q++ = -1;  // left wall
  while (*p != '\0') {
    *q++ = *p++;
    *q++ = -2;  // inter dummy char
  }
  *(q-1) = -1;  // right wall
  *q = '\0';    // FIX: make string

  int ans = 0;
  forp(i, 1, strlen(str)-2) {
    char* p = &str[i];
    int k = 1;
    while (*(p-k)!=-1 && *(p+k)!=-1 
            && *(p-k)==*(p+k)) k++;
    if (*(p+k-1) == -2) k--;  /* dummy char offset */
    if (k > ans) ans = k;
  }
  prti(ans);
}
