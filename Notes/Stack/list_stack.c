#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef int DATATYPE;
typedef struct node {
  DATATYPE data;
  struct node* link;
} Node;
typedef struct stack {
  struct node* top;
} Stack;

Stack* s_init() {
  Stack* s = malloc(sizeof(Stack));
  s->top = NULL;
  return s;
}
void s_push(Stack* s, DATATYPE val) {
  Node* n = malloc(sizeof(Node));
  n->data = val;
  n->link = s->top;
  s->top = n;
}
DATATYPE s_pop(Stack* s) {
  Node* p = s->top;
  DATATYPE v = p->data;
  s->top = p->link;
  free(p);
  return v;
}
bool s_empty(Stack* s) {
	return s->top == NULL;
}

int main() {
  srand(time(NULL));
  Stack* s = s_init();

  int t = rand() % 15 + 1;
  while (t--) {
    if (rand() % 3 == 1) {
      int r = rand() % 100;
      printf("push %d\n", r);
      s_push(s, r);
    } else if (!s_empty(s))
      printf("pop %d\n", s_pop(s));
  }

	return 0;
}