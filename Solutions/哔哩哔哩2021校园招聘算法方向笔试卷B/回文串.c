#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define input(x) scanf("%d",&x)
#define inputs(x) scanf("%s",&x);getchar()
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define MAXLEN 100000
#define SEP_CHAR '_'

// 2021/08/18 

char t[MAXLEN], s[MAXLEN];
int R = 1, P = 1;
int len = 0;

void expand(int i) {
  int k = 1;
  while (i-k>=0 && i+k<len && s[i-k]==s[i+k]) k++;
  if (k > R) { R = k; P = i; }
  //printf("  k=%d\n", k);
}

int main() {
  inputs(t);
  char *p = t, *q = s;
  while (*p) {
    *q++ = SEP_CHAR;
    *q++ = *p++;
  }
  *q++ = SEP_CHAR;
  *q = '\0';
  len = strlen(s);
  //puts(t); puts(s);
  
  forr (i, 1, len-1) expand(i);
  //printf("P=%d, R=%d\n", P, R);
  
  P -= R-1;
  forr (i, 0, 2*(R-1)) {
    i++;
    putchar(s[P+i]);
  }
  putchar(10);
}

