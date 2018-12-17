#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 这样做太复杂了
// 应该第一次处理乘除法，第二次处理加减法

double parseExpression();
double parseTerm();
double parseFactor();

double parseExpression() {
  double left = parseTerm();
  char op;
  while ((op=getchar()) == ' ');
  if (op == '+' || op == '-') {
    while (op == '+' || op == '-') {
      char c; while ((c=getchar()) == ' '); ungetc(c, stdin);
      double right = parseTerm();
      if (op == '+') left+=right;
      else left-=right;
      while ((op=getchar()) == ' ');
    }
  }
  return left;
}

double parseTerm() {
  double left = parseFactor();
  char op;
  while ((op=getchar()) == ' ');
  if (op == '*' || op == '/') {
    while (op == '*' || op == '/') {
      char c; while ((c=getchar()) == ' '); ungetc(c, stdin);
      double right = parseFactor();
      if (op == '*') left*=right;
      else left/=right;
      while ((op=getchar()) == ' ');
    }
  }
  ungetc(op, stdin);
  return left;
}

double parseFactor() {
  int x; scanf("%d", &x);
  return (double)x;
}

int main() {
  char c;
  while ((c=getchar()) != EOF)
    if (c == '0') break;   /* this is cursory though */
    else {
      ungetc(c, stdin);
      printf("%.2f\n", parseExpression());
    }
}