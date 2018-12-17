#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define N 1000
#define DIGITS 16

typedef struct node {
  unsigned char code;    // plain code (4bit): '0'~'F'(0000~1111)
  unsigned char hcode;   // huffman code (15bit at most)
  double weight;
  struct node *parent, *lchild, *rchild;
} HTNode;

HTNode* ht_create(HTNode** nodes, int n) {
  HTNode* t = NULL; // the final tree
  int lidx;         // the idx of the root node in final node pool
  while (--n) {     // merge at most (n-1) rounds
    double w1 = 1.5, w2 = 1.5;  // frequency should no more than 1.0
    HTNode *lt, *rt;              // merge two sub-tree with lowest weight
    int ridx;
    for (int i=0; i<n; i++)     // search in sub-tree pool
      if (nodes[i])
        if (nodes[i]->weight < w1) { // w1 is the minimal
          w2 = w1; rt = lt;     // transfer
          w1 = nodes[i]->weight;
          lt = nodes[lidx=i];
        } else if (nodes[i]->weight < w2) {  // w2 is the secondary minimal
          w2 = nodes[i]->weight;
          rt = nodes[ridx=i];
        }
    HTNode* n = malloc(sizeof(HTNode));
    n->weight = w1 + w2;
    n->lchild = lt; n->rchild = rt;
    lt->parent = rt->parent = n;
    nodes[ridx] = NULL; // move them out of node pool
    nodes[lidx] = n; // put the new node to node pool
  }
  t = nodes[lidx];
  t->parent = NULL;
  t->hcode = 0x00u; // init hcode
  return t;
}
double _ht_weight(HTNode* ht, int depth) {
  if (!ht) return 0.0;
  if (!ht->lchild && !ht->rchild) return ht->weight * depth;
  else return (ht->lchild ? _ht_weight(ht->lchild, depth+1) : 0.0) +
              (ht->rchild ? _ht_weight(ht->rchild, depth+1) : 0.0);
}
#define ht_weight(ht) _ht_weight(ht, 0)

void _ht_encode(HTNode* ht, unsigned int* hcode) {
  if (!ht) return;
  if (!ht->lchild && !ht->rchild) {
    hcode[ht->code] = ht->hcode;
    return;
  }
  if (ht->lchild) {
    ht->lchild->hcode = ht->hcode << 1 | 0x01u;
    _ht_encode(ht->lchild, hcode);
  }
  if (ht->rchild) {
    ht->rchild->hcode = ht->hcode << 1;
    _ht_encode(ht->rchild, hcode);
  }
}
unsigned int* ht_encode(HTNode* ht) {  // wrapper for _ht_encode() 
  size_t sz = DIGITS * sizeof(unsigned int);
  unsigned int* hcode = malloc(sz);
  memset(hcode, 0x00, sz);
  _ht_encode(ht, hcode);
  return hcode;
}
void test(char* str) {
  // 0. text digit frequency analyze
  size_t sz = DIGITS * sizeof(size_t);  // hist[16]: 0000 ~ 1111
  size_t* hist = malloc(sz);
  memset(hist, 0x00, sz);
  size_t len = strlen(str);
  for (int i=0; i<=len; i++) {
    hist[str[i] & 0x0Fu]++;
    hist[(str[i] & 0xF0u) >> 4]++;
  }
  puts("weight[]:");
  for (int i=0; i<DIGITS; i++) 
    printf("%4X", i); puts("");
  for (int i=0; i<DIGITS; i++)
    printf("%4d", hist[i] * 100 / len); puts("");

  HTNode** nodes = malloc(DIGITS * sizeof(HTNode*));
  for (int i=0; i<DIGITS; i++) {
    nodes[i] = malloc(sizeof(HTNode));
    nodes[i]->code = i;
    nodes[i]->weight = (double) hist[i] / len;
    nodes[i]->lchild = nodes[i]->rchild = NULL;
  }

  // 1. build huffman tree and encode
  HTNode* ht = ht_create(nodes, DIGITS);
  int* hcode = ht_encode(ht);
  printf("ht_weight: %.2lf\n", ht_weight(ht));

  // 2. show hcode
  puts("hcode[]:");
  for (int i=0; i<DIGITS; i++) 
    printf("%4X", i); puts("");
  for (int i=0; i<DIGITS; i++)
    printf("%4X", hcode[i]);

  // -1. clean up
  free(hist);
  for (int i=0; i<DIGITS; i++) free(nodes[i]);
  free(nodes);
  free(hcode);
}

int main() {
  srand(time(NULL));
  char str[N];
  for (int i=0; i<N; i++)
    str[i] = rand() % 95 + 32;  // printable chars
  test(str);
}