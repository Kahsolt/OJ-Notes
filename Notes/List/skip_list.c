#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#define NLAYER 10

// 2018/08/16

typedef int DATATYPE;
typedef struct node {     /* data node */
  DATATYPE data;
  struct node** next;     /* layer count decided by head node */
} Node;
typedef struct skiplist { /* head node */
  size_t layer;           /* layer count */
  size_t length;          /* list length, aka data count */
  struct node* list;      /* first data node of the list */
} SkipList;

Node* _sl_newnode(SkipList* sl, DATATYPE val) {
  sl->length++;
  Node* n = malloc(sizeof(Node));
  n->data = val;
  size_t sz = sl->layer * sizeof(Node*);
  n->next = malloc(sz); memset(n->next, 0x00, sz);
  return n;
}
SkipList* sl_init(size_t layer) {
  SkipList* sl = malloc(sizeof(SkipList));
  sl->layer = layer;
  sl->length = -1;    /* offset for the dummy node */
  sl->list = _sl_newnode(sl, -1); /* dummy first data node; data unused, so arbitary -INF */
  return sl;
}
bool sl_find(SkipList* sl, DATATYPE val) {
  Node* n = sl->list;
  size_t layer = 0;

  while (layer<sl->layer) {
    if (n->next[layer] && n->next[layer]->data == val)
      return true;
    else if (!n->next[layer] || n->next[layer]->data > val)
      layer++;
    else n = n->next[layer];
  }
  return false;
}
bool _sl_insert_deter(int length, int layer, int x) {
  /* a curve that pass through point (0, length) and (layer-1, sqrt(length)) */
  int r = rand() % length;
  int cal = length * (layer - 1) / ((ceil(sqrt(length)) - 1) * x + layer - 1);
  return r <= cal;
}
void sl_insert(SkipList* sl, DATATYPE val) {
  Node *p = sl->list;   /* preceed of the target node or vacancy */
  size_t layer = 0;

  while (p->next[layer] && layer<sl->layer) {
    if (p->next[layer]->data == val)
      return;   /* found exists, keep uniqueness */
    else if (p->next[layer]->data > val)
      layer++;    /* layer falldown */
    else p = p->next[layer];  /* same layer, follow link */
  }

  Node* n = _sl_newnode(sl, val);
  for (int i=0; i<sl->layer; i++) {
    if (i && !_sl_insert_deter(sl->length, sl->layer, i))
      break;
    n->next[i] = p->next[i];
    p->next[i] = n;
  }
}
void sl_delete(SkipList* sl, DATATYPE val) { }
void sl_print(SkipList* sl) {
  for (int i=0; i<sl->layer; i++) {
    printf("[#%d]: ", i);
    Node* n = sl->list->next[i];  /* or: sl->list; */
    while (n) {
      printf("%4d", n->data);
      n = n->next[i];
    }
    puts("");
  }
}

int main() {
  srand(time(NULL) + GetCurrentProcessId());

  int n = rand() % 30 + 1;
  SkipList* sl = sl_init(__max(ceil(log(n)), 1));
  if (n != sl->length) puts("Inconsist!");
  while (n--) sl_insert(sl, rand() % 50);
  sl_print(sl);
  int t = rand() % 10 + 5;
  while (t--) {
    int x = rand() % 75;
    printf("  [%c]%4d\n", sl_find(sl, x) ? 'Y' : 'N', x);
  }
}