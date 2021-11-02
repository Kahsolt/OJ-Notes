#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

// 2021/09/11
// B树，平衡的多路查找树

typedef int DATATYPE;
typedef struct node {
  size_t n;                  // data[]有效数据的长度
  DATATYPE* data;            // len(data) == m-1
  struct node** children;    // len(children) == m
} Node;

typedef struct btree {
  int m;             // m路 
  struct node* root;
} BTree;

Node* bt_newnode(int m) {
  Node* n = (Node*) malloc(sizeof(Node));
  n->n = 0;
  n->data = (DATATYPE*) malloc((m-1)*sizeof(DATATYPE));
  n->children = (Node**) malloc(m*sizeof(Node*));
  return n;
}

BTree* bt_create(int m) {
  BTree* bt = (BTree*) malloc(sizeof(BTree));
  bt->m = m;
  bt->root = bt_newnode(m);
  return bt;
}

void bt_insert(BTree* bt, DATATYPE data) {

}

bool bt_has(BTree* bt, DATATYPE data) {

}

int main() {
  srand(time(NULL));
  
  BTree* bt = bt_create(5);
  
  int MOD = 314;

  int N = 100;
  for (int i=0; i<N; i++) {
    int r = rand() % MOD;
    bt_insert(bt, r);
  }

  int M = 30;
  for (int i=0; i<M; i++) {
    int r = rand() % MOD;
    printf("find(%d) = %d\n", r, bt_has(bt, r));
  }
}
 
