// 2021/10/02 
// Note: LRU = linklist (update/delete) + hashmap (query)
// 指针太多错误跑不起来（

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 9973

typedef struct node {
  int key, value;
  struct node *next, *prev;
} Node;

typedef struct hashmap {
  int count;
  Node* map[MOD];
} HashMap;

Node* ll;
HashMap* ht;
int lru_size = 0;

int hash(int k) {
  return k % MOD;
}

Node* new_node(int v, int k) {
  Node* n = (Node*) malloc(sizeof(Node));
  n->key = k; n->value = v;
  n->next = n->prev = n;
  return n;
}

void ll_popup(Node *n) {
  n->next->prev = n->prev;
  n->prev->next = n->next;
  n->prev = ll;
  ll->next = ll->next->next;
  n->next = ll->next;
  ll->next->prev = n;
}

void ll_put_head(Node *n) {
  n->prev = ll;
  n->next = ll->next;
  ll->next->prev = n;
  ll->next = n;
}

Node* ll_pop_tail() {
  Node* r = ll->prev;
  r->prev->next = ll;
  ll->prev = r->prev;
  return r;
}

HashMap* ht_new() {
  HashMap* ht = (HashMap*) malloc(sizeof(HashMap));
  ht->count = 0;
  memset(ht->map, 0, sizeof(ht->map));
  return ht;
}

Node* ht_find(int key) {
  int k = hash(key);
  for (int i=0; i<MOD; i++) {
    for (int j=-1; j<=1; j+=2) {
      int loc = (k + j * i * i + MOD) % MOD;
      if (ht->map[loc] && ht->map[loc]->key == k) {
        ll_popup(ht->map[loc]);
        return ht->map[loc];
      }
    }
  }
  return NULL;
}

Node* ht_insert(int key, int value) {
  Node* n = new_node(key, value);
  int k = hash(key);
  for (int i=0; i<MOD; i++) {
    for (int j=-1; j<=1; j+=2) {
      int loc = (k + j * i * i + MOD) % MOD;
      if (!ht->map[loc]) {
        ht->map[loc] = n;
        return n;
      }
    }
  }
  return NULL;
}

void ht_delete(int key) {
  int k = hash(key);
  for (int i=0; i<MOD; i++) {
    for (int j=-1; j<=1; j+=2) {
      int loc = (k + j * i * i + MOD) % MOD;
      if (ht->map[loc] && ht->map[loc]->key == k) {
        free(ht->map[loc]);
        ht->map[loc] = NULL;
        return;
      }
    }
  }
}

void insert(int key, int value) {
  if (ht_find(key)) return;
  
  if (ht->count >= lru_size) {
    Node* n = ll_pop_tail();
    ht_delete(n->key);
  } else ht->count++;
  Node *n = ht_insert(key, value);
  ll_put_head(n);
}

int* LRU(int** operators, int operatorsRowLen, int* operatorsColLen, int k, int* returnSize) {
  int *ret = NULL; *returnSize = 0;
  int q = 0;
  for (int i=0; i<operatorsRowLen; i++)
    if (operators[i][0] == 2) q++;
  if (!q) return ret;
  ret = (int *) malloc(sizeof(int) * q);
  *returnSize = q;
  
  ll = new_node(-1, -1);      // head node for double linklist
  ht = ht_new();              // hashtable
  lru_size = k;
  int p = 0;

  for (int i=0; i<operatorsRowLen; i++) {
    if (operators[i][0] == 1) {   // set(k, v)
      int k = operators[i][1], v = operators[i][2];
      printf("set(%d, %d)\n", k, v);
      insert(k, v);
    } else {                      // get(k)
      int k = operators[i][1];
      printf("get(%d, %d)\n", k);
      Node *r = ht_find(k);
      ret[p++] = r ? r->value : -1;
    }
  }

  return ret;
}

int main() {
  int operators[][3] = {
    {1,1,1},
    {1,2,2},
    {1,3,2},
    {2,1},
    {1,4,4},
    {2,2},
  };
  int* returnSize;
  int *r = LRU(operators, 6, NULL, 3, &returnSize);

  for (int i=0; i<*returnSize; i++)
    printf("%d ", r[i]);
}