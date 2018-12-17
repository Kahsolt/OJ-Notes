#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define read(x) int x;scanf("%d",&x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar('*');printf("%d",x[i]);}
#define N 100000
#define eps 1e-5
/* Finding Average (20) */

bool valid;
double parse(char* buf) {
  valid = true;
  char* p = buf;
  double x = 0.0, fracbase = 0.1;
  bool sign = false, dot = false;
  if (*p == '-') { p++; sign = true; }
  while (valid && *p != '\0') {
    if ('0'<=*p && *p<='9')  {
      if (!dot) x = x * 10 + (*p & 0x0F);
      else {
        x += fracbase * (*p & 0x0F);
        fracbase /= 10;
      }
      if (x<-1000.0 || x>1000.0 || fracbase - eps <= 0.0001)
        valid = false;
    } else if (*p=='.') {
      if (!dot) dot = true;
      else valid = false;
    } else valid = false;
    p++;
  }
  return sign ? -x : x;
}
int main() {
  int cnt = 0;
  double sum;
  read(n);
  while (n--) {
    char buf[100]; scanf("%s", buf);
    double x = parse(buf);
    if (valid) { cnt++; sum += x; }
    else printf("ERROR: %s is not a legal number\n", buf);
  }
  if (!cnt) puts("The average of 0 numbers is Undefined");
  else if (cnt == 1) printf("The average of 1 number is %.2f", sum);
  else printf("The average of %d numbers is %.2f", cnt, sum / cnt);
}