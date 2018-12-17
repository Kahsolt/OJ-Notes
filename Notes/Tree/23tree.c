#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 2018/08/29
// 2-3树：三阶B-树
//   2-节点，含有一个键和两条链接
//   3-节点，含有两个键和三条链接
//

typedef int DATATYPE;
typedef struct node {
  enum { DUAL, TRIPLE } type;
  DATATYPE lkey, rkey;
	struct node *lchild, *mchild, *rchild;
} Node;

Node* t23_newnode(DATATYPE val) {
  Node* n = malloc(sizeof(Node));
  n->type = DUAL;
  n->lkey = val; n->rkey = -1;
  n->lchild = n->mchild = n->rchild = NULL;
  return n;
}
bool t23_find(Node* t, DATATYPE val) {
  while (t) {
    if (val==t->lkey || val==t->rkey)
      return true;
    if (val <= t->lkey) t = t->lchild;
    else if (val > t->rkey) t = t->rchild;
    else t = t->mchild;
  }
  return false;
}
void t23_insert(Node** t, DATATYPE val) {
  if (!*t) { *t = t23_newnode(val); return; }
  Node *p = *t;

}
void t23_delete(Node* t, DATATYPE val) {

}

int main() {

}