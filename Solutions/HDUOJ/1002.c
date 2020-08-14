// A + B Problem II

#include <stdio.h>
#include <string.h>
#define MAXN 1001

char a[MAXN], b[MAXN], c[MAXN];

void add(char a[], char b[]) {
  char ra[MAXN] = { 0 }, rb[MAXN] = { 0 };
  char *p, *q;

  p = a + strlen(a) - 1 ; q = ra;
  while (p >= a) *q++ = *p-- & 0x0F;
  p = b + strlen(b) - 1; q = rb;
  while (p >= b) *q++ = *p-- & 0x0F;

  memset(c, 0x00, sizeof(c));
  for (int i=0; i<MAXN-1; i++) {
    int d = ra[i] + rb[i] + c[i];
    c[i] = d % 10;
    if (d >= 10) c[i + 1] = 1;
  }
}

void println(char c[]) {
  char *p = &c[MAXN - 1];
  while (p >= c && !*p) p--;
  if (p < c) putchar('0');
  else while (p >= c) printf("%d", *p--);
  putchar(10);
}

int main() {
  int t; scanf("%d", &t); getchar();
  for (int i=1; i<=t; i++) {
    scanf("%s", a); getchar();
    scanf("%s", b); getchar();
    printf("Case %d:\n%s + %s = ", i, a, b);
    add(a, b); println(c);
    if (i != t) putchar(10);
  }
}