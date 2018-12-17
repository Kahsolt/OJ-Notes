#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define N 100

typedef struct seg {
  bool type;  // true: val, false: op
  char op;
  int val;
  struct seg* next;
} Seg;
Seg* parse_infix_expr(char* expr) {

}
static inline int get_priority(char op) {
  return op=='(' || op==')' ? 4
      : op=='^' ? 3
        : op=='*' || op=='/' || op=='%' ? 2
          : 1;
}
Seg* infix_to_postfix(Seg* seg) {
	Seg *s = NULL, *q = s;
  Seg* stack[N]; int top = -1;
  while (seg) {
    Seg* n = seg->next; // save next
    if (seg->type) {
      if (!s) s = seg;
      else {
        q->next = seg;
        q = seg;
        q->next = NULL;
      }
    } else {
      if (top == -1
          || get_priority(seg->op) > get_priority(stack[top]->op)) {
        stack[++top] = seg;
      } else {
        q->next = stack[top];
        q = stack[top];
        q->next = NULL;
        top--;
        stack[++top] = seg;
      }
    }
    seg = n;
  }
  return s;
}
int eval_postfix(Seg* seg) {
  int stack[N], top = -1;
	while (seg) {
    if (seg->type) stack[++top] = seg->val;
    else {
      int op2 = stack[top--];
      int op1 = stack[top--];
      switch (seg->op) {
        case '+': stack[++top] = op1 + op2;     break;
        case '-': stack[++top] = op1 - op2;     break;
        case '*': stack[++top] = op1 * op2;     break;
        case '/': stack[++top] = op1 / op2;     break;
        case '%': stack[++top] = op1 % op2;     break;
        case '^': stack[++top] = pow(op1, op2); break;
      }
    }
    seg = seg->next;
  }
  return stack[top];
}

int main() {

}