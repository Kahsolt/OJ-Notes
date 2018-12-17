#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DATATYPE;
typedef struct stack {
  int size;
  DATATYPE* data;
} Stack;

Stack* s_create(size_t size) {
  Stack* s = malloc(sizeof(Stack));
  s->size = -1;
  s->data = malloc(size * sizeof(DATATYPE));
  return s;
}
void s_destroy(Stack* s) {
  if (s) {
    if (s->data) free(s->data);
    free(s);
  }
}
DATATYPE s_pop(Stack* s) {
  return s->data[s->size--];
}
void s_push(Stack* s, DATATYPE val) {
  s->data[++s->size] = val;
}
int s_empty(Stack* s) {
  return s->size == -1;
}

int main() {
  srand(time(NULL));
  Stack* s = s_create(10);
  
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