#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 1000

// 2018/08/28
// 图灵机：有穷自动机的扩展版
//

typedef char DATATYPE;
typedef enum { LEFT, RIGHT, STALL } Direction;
struct node;  // pre declare
typedef struct condition {
  DATATYPE when;
  DATATYPE write;
  struct node* then;
  Direction move;
  struct condition* next;
} Condition;
typedef struct node {
  bool terminal;
  bool accept;
  struct condition* conditions;
} Node;

#define RBN -1    // the robin grid
#define NUL 'X'   // the black grid
DATATYPE tape[N]; // the infinite tape...

static inline Node* tm_newnode(bool terminal, bool accept) {
  Node* n = malloc(sizeof(Node));
  n->conditions = NULL;
  n->terminal = terminal;
  n->accept = accept;
}
static inline void tm_addcondition(
  Node* stat,
  DATATYPE when, DATATYPE write, Direction move, Node* then
) {
  Condition* c = malloc(sizeof(Condition));
  c->when = when;
  c->write = write;
  c->then = then;
  c->move = move;
  c->next = stat->conditions;  // insert head
  stat->conditions = c;
}
static inline int tm_loadtape(DATATYPE data[], size_t len) {
  int pos = 0;
  tape[pos++] = RBN;   // leading robin
  for (int i=0; i<len; i++)
    tape[pos++] = data[i];
  tape[pos++] = RBN;   // ending robin
  return 1;           // start pos
}
static inline bool tm_run(Node* stat, int pos) {
  while (!stat->terminal) {
    Condition* c = stat->conditions;
    while (c->when != tape[pos]) c = c->next;
    if (!c) return false;
    tape[pos] = c->write;     // write symbol
    if (c->move == RIGHT)     // move head
      pos++;
    else if (c->move == LEFT)
      pos--;
    stat = c->then;           // switch state
  }
  return stat->accept;
}

int main() {
  // This turing machin accepts string with equal '0's and '1's
  Node* sm = tm_newnode(true,  false);  // terminal trap (reject)
  Node* s0 = tm_newnode(true,  true);   // terminal trap (accept)
  Node* s1 = tm_newnode(false, false);  // starting stat
  Node* s2 = tm_newnode(false, false);  // got 0, need del 1 stat
  Node* s3 = tm_newnode(false, false);  // got 1, need del 0 stat
  Node* s4 = tm_newnode(false, false);  // carrige return stat
  
  tm_addcondition(s1, NUL, NUL, RIGHT, s1);
  tm_addcondition(s1, '0', NUL, RIGHT, s2);
  tm_addcondition(s1, '1', NUL, RIGHT, s3);
  tm_addcondition(s1, RBN, RBN, RIGHT, s0);

  tm_addcondition(s2, NUL, NUL, RIGHT, s2);
  tm_addcondition(s2, '0', '0', RIGHT, s2);
  tm_addcondition(s2, '1', NUL,  LEFT, s4);
  tm_addcondition(s2, RBN, RBN, STALL, sm);

  tm_addcondition(s3, NUL, NUL, RIGHT, s3);
  tm_addcondition(s3, '1', '1', RIGHT, s3);
  tm_addcondition(s3, '0', NUL,  LEFT, s4);
  tm_addcondition(s3, RBN, RBN, STALL, sm);

  tm_addcondition(s4, NUL, NUL,  LEFT, s4);
  tm_addcondition(s4, '1', '1',  LEFT, s4);
  tm_addcondition(s4, '0', '0',  LEFT, s4);
  tm_addcondition(s4, RBN, RBN, RIGHT, s1);
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
    puts(tm_run(S, tm_loadtape(data[i], strlen(data[i])))
        ? "Yes" : "No");
}