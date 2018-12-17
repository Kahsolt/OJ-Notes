#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DATATYPE;
typedef struct node {
	DATATYPE data;
  bool lflag, rflag;  /* false: subtree, true: thread */
	struct node *lchild, *rchild;
} Node;
Node* vroot;  /* 线索化之后的虚拟根节点 */
Node* prior;  /* 线索化时辅助记忆变量，始终指向刚刚访问过的节点 */

void _tbt_inthreading(Node* cur) {
  if (cur->lchild) _tbt_inthreading(cur->lchild);
  else {
    cur->lflag = true;    /* 不存在则，左标志为线索 */
    cur->lchild = prior;  /* cur的前驱即刚访问过的prior */
  }

  if (!prior->rchild) {
    //prior->rflag = true;  /* 不存在则，右标志为线索 */
    prior->rchild = cur;  /* 刚访问过的后继回填为当前节点cur */
  }
  prior = cur;            /* 中序访问根，更新prior */
  
  if (cur->rchild) _tbt_inthreading(cur->rchild);
  else cur->rflag = true;
}
Node* tbt_inthreading(Node* root) {  /* 从实根节点开始 */
  if (!root) return NULL;
  Node* bt_newnode(int);
  vroot = bt_newnode(0);  // dummy value 0
  prior = vroot;
  _tbt_inthreading(root);
  return vroot;
}

Node* tbt_prior(Node* cur) {  /* 取前驱 */
  Node* p = cur->lchild;      /* 左滑到左子树 */
  if (!cur->lflag)            /* 左子树实在? */
    while (!p->rflag)         /* 右滑直到某个右子树不实在 */
      p = p->rchild;
  return p;
}
Node* tbt_succ(Node* cur) { /* 取后继 */
  Node* p = cur->rchild;    /* 右滑到右子树 */
  if (!cur->rflag)          /* 右子树实在? */
    while (!p->lflag)       /* 左滑直到某个左子树不实在 */
      p = p->lchild;
  return p;
}
void tbt_inorder(Node* vroot) { /* 应从vroot开始 */
  Node* p = vroot;
  do {
    p = tbt_succ(p);
    printf("%d ", p->data);
  } while (p != vroot);
}

int n = 12;
int nodes[] = { 0, // dummy nodes[0]
              1,
        5,          9,
     7,    2,    6,   -1,
  -1, 3, -1, 8, 4,
};
Node* bt_newnode(int data) {
  Node* n = malloc(sizeof(Node));
  n->data = data;
  n->lflag = n->rflag = false;  // default is tree
  n->lchild = n->rchild = NULL;
  return n;
}
Node* bt_create(int cur, int N) {
  int left = cur << 1;
  int right = left | 0x01;
  Node* n = bt_newnode(nodes[cur]);
  if (left<=N && nodes[left]!=-1)
    n->lchild = bt_create(left, N);
  if (right<=N && nodes[right]!=-1)
    n->rchild = bt_create(right, N);
  return n;
}
void bt_inorder(Node *t) {
	if (!t) return;
	if (!t->lflag && t->lchild) bt_inorder(t->lchild);
	printf("[%d] %d:%p %d:%p\n",
    t->data, t->lflag, t->lchild, t->rflag, t->rchild);
	if (!t->rflag && t->rchild) bt_inorder(t->rchild);
}

int main() {
  printf("sizeof(Node) = %d\n", sizeof(Node));

  Node* root = bt_create(1, n);
  bt_inorder(root); putchar(10);
  
  Node* vroot = tbt_inthreading(root);
  bt_inorder(root); putchar(10);
  tbt_inorder(vroot);
}