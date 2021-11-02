// 2021/10/10 

#include <stdlib.h>
#include <string.h>

int solution(char *S) {
  int N = strlen(S);
  if (!N) return 1;

  char *stack = (char *) malloc(sizeof(char)*N), *p = S;
  int top = -1;
  stack[++top] = *p++;
  while (*p) {
    if (stack[top] == '(' && *p == ')' || 
        stack[top] == '[' && *p == ']' ||
        stack[top] == '{' && *p == '}') top--;
    else stack[++top] = *p;
    p++;
  }
  return top == -1;
}
