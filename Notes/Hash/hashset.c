#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 2021/09/11 

typedef int DATATYPE;
typedef struct node {
  DATATYPE data;
  struct node *next;
} Node;
typedef struct hashset {
	size_t size;      // aka. MOD
	Node** slots;     // first node use for count
} HashSet;

int hash(DATATYPE data) {
  int nbyte = sizeof(DATATYPE);
  char *p = (char*) &data;
  int h = 0;
  for (int i=0; i<nbyte; i++) {
    h = (h << 7) + (h >> 5) + *p;
    p++;
  }
  return h;
}

HashSet* hs_create(int size) {
  HashSet* hs = (HashSet*) malloc(sizeof(HashSet));
  hs->size = size;
  hs->slots = (Node**) malloc(hs->size*sizeof(Node*));
  for (int i=0; i<hs->size; i++) {  
    hs->slots[i] = (Node*) malloc(sizeof(Node));
    hs->slots[i]->data = 0;
    hs->slots[i]->next = NULL;
  }
  return hs;
}

HashSet* hs_destroy(HashSet* hs) {
  for (int i=0; i<hs->size; i++) {
    Node *p = hs->slots[i];
    while (p) {
      Node *q = p->next;
      free(p);
      p = q;
    }
  }
  free(hs->slots);
  free(hs);
}

void hs_insert(HashSet* hs, DATATYPE data) {
  int i = hash(data) % hs->size;
  Node* p = hs->slots[i]->next;
  while (p) {
    if (p->data == data) return;
    p = p->next;
  }
  
  Node* n = (Node*) malloc(sizeof(Node));
  n->data = data;
  n->next = hs->slots[i]->next;
  hs->slots[i]->next = n;
  hs->slots[i]->data++;
}

bool hs_has(HashSet* hs, DATATYPE data) {
  int i = hash(data) % hs->size;
  Node* p = hs->slots[i]->next;
  while (p) {
    if (p->data == data) return true;
    p = p->next;
  }
  return false;
}

void hs_debug(HashSet* hs) {
  for (int i=0; i<hs->size; i++) {
    Node* n = hs->slots[i];
    printf("[%d] %d:", i, n->data);
    
    Node* p = n->next;
    while (p) {
      printf(" %d", p->data);
      p = p->next;
    }
    putchar('\n');
  }
}

int main() {
  srand(time(NULL));
  
  HashSet* hs = hs_create(37);
  
  int MOD = 314;

  int N = 100;
  for (int i=0; i<N; i++) {
    int r = rand() % MOD;
    hs_insert(hs, r);
  }

  int M = 30;
  for (int i=0; i<M; i++) {
    int r = rand() % MOD;
    printf("find(%d) = %d\n", r, hs_has(hs, r));
  }
  
  hs_debug(hs);
  hs_destroy(hs);
}
