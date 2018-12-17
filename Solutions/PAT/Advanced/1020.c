#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
/* Tree Traversals (25) */

typedef struct node {
  int id;
  struct node *left, *right;
} Node;
int postorder[N], inorder[N];

Node* create(int pos, int poe, int ios, int ioe) {
  if (pos>poe || ios>ioe) return NULL;

  int root = postorder[poe], idx = -1;
  for (int k=ios; k<=ioe; k++)
    if (inorder[k] == root)
      { idx = k; break; } // find idx of root in inorder
      
  Node* n = malloc(sizeof(Node));
  n->id = root;
  n->left  = create(pos,         pos+idx-ios-1, ios,   idx-1);
  n->right = create(pos+idx-ios, poe-1,         idx+1, ioe);
  return n;
}

void layer_order(Node* t) {
  Node* queue[N+2]; memset(queue, 0x00, sizeof(queue));
  int head = 0, tail = 0;
  queue[head++] = t;

  while (head != tail) {
    Node* n = queue[tail];
    if (n->left) queue[head++] = n->left;
    if (n->right) queue[head++] = n->right;
    printf("%d", n->id);
    if (head != ++tail) printf(" ");
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &postorder[i]);
  for (int i=0; i<n; i++) scanf("%d", &inorder[i]);
  layer_order(create(0, n-1, 0, n-1));
}