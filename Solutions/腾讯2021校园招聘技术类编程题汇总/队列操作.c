#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define times(n) int _##n=n;while(_##n--)
#define input(x) scanf("%d",&x)
#define inputs(x) scanf("%s",&x);getchar()
#define read(x) int x;input(x)
#define prti(x) printf("%d\n", x)

// 2021/08/16

typedef struct node {
  int value;
  struct node *prev;
  struct node *next;
} Node;

static inline Node* q_new(int v) {
  Node *q = malloc(sizeof(Node));
  q->value = v;   // q_size
  q->prev = q->next = q;
  return q;
}
static inline void q_push(Node *q, int x) {
  Node* n = q_new(x);
  n->next = q->next; q->next = n;
  n->next->prev = n; n->prev = q;
  q->value++;
}
static inline int q_size(Node *q) {
  return q->value;
}
static inline int q_top(Node *q) {
  if (!q_size(q)) return -1;
  return q->prev->value;
}
static inline bool q_pop(Node *q) {
  if (!q_size(q)) return false;
  Node *t = q->prev;
  q->prev = t->prev; t->prev->next = q;
  free(t);
  q->value--;
  return true;
}
static inline void q_clear(Node *q) {
  while (q->next != q) {
    Node *t = q->next;
    q->next = t->next;
    t->next->prev = q;
    free(t);
  }
}

int main() {
  Node *q = q_new(0);
  char cmd[6];
  read(T); getchar(); times(T) {
    q_clear(q);  // reset
    read(Q); getchar(); times(Q) {
      inputs(cmd);
      if (cmd[1] == 'L') q_clear(q);
      else if (cmd[1] == 'I') prti(q_size(q));
      else if (cmd[1] == 'U') { read(x); q_push(q, x); }
      else if (cmd[0] == 'T') prti(q_top(q));
      else if (!q_pop(q)) puts("-1");
    }
  }
}
