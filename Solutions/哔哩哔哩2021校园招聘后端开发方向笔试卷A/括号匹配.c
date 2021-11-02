// 2021/08/14 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool IsValidExp(char* s) {
  int len = strlen(s), top = -1;
  char *stack = (char*) malloc(len * sizeof(char));

  while (*s) {
    if (top != -1) {
      if (*s == '(' || *s == '[' || *s == '{') stack[++top] = *s;
      else if (stack[top] == '(' && *s == ')') top--;
      else if (stack[top] == '[' && *s == ']') top--;
      else if (stack[top] == '{' && *s == '}') top--;
    } else {
      if (*s == ')' || *s == ']' || *s == '}') return false; 
      else stack[++top] = *s;
    }
    s++;
  }

  return top == -1;
}

int main() {
  printf("%d\n", IsValidExp("{[]}"));
  printf("%d\n", IsValidExp("([)]"));
  printf("%d\n", IsValidExp("([]"));
}
