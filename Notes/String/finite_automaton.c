#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 100

// 2018/08/27
// 有穷自动机 (linking node ver)
//

typedef char DATATYPE;
struct node;  // pre declare
typedef struct condition {
  DATATYPE when;
  struct node* then;
  struct condition* next;
} Condition;
typedef struct node {
  bool terminal;
  struct condition* conditions;
} Node;
static inline Node* fa_newnode(bool terminal) {
  Node* n = malloc(sizeof(Node));
  n->conditions = NULL;
  n->terminal = terminal;
}
static inline void fa_addcondition(Node* cur, DATATYPE when, Node* then) {
  Condition* c = malloc(sizeof(Condition));
  c->when = when;
  c->then = then;
  c->next = cur->conditions;  // insert head
  cur->conditions = c;
}
static inline bool fa_run(Node* cur, DATATYPE data[], size_t len) {
  for (int i=0; i<len; i++) {
    Condition* c = cur->conditions;
    while (c && data[i] != c->when)
      c = c->next;
    if (c) cur = c->then;
    else return false;
  }
  return cur->terminal;
}

int main() {
  // This automaton accepts string with odd '1's
  Node* s1 = fa_newnode(false);
  Node* s2 = fa_newnode(true);
  fa_addcondition(s1, '0', s1);
  fa_addcondition(s1, '1', s2);
  fa_addcondition(s2, '0', s2);
  fa_addcondition(s2, '1', s1);
  Node* S = s1;

  int t = 5;
  DATATYPE data[][N] = {
    "001",
    "1010100",
    "1001",
    "1110110",
    "10101010",
  };
  for (int i=0; i<t; i++)
    puts(fa_run(S, data[i], strlen(data[i]))
        ? "Yes" : "No");
}