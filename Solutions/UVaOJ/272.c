#include <stdio.h>
#include <stdbool.h>

/* 272. TEX Quotes */
int main() {
  char c;
  bool flag = true;
  while ((c = getchar()) != EOF) {
    if (c != '"') putchar(c);
    else {
      printf(flag ? "``" : "''");
      flag = !flag;
    }
  }
}