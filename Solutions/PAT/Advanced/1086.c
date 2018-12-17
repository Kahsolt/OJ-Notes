#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTR 5
/* Tree Traversals Again (25) */

int *preorder, *inorder, top_preorder=-1, top_inorder=-1;
int N;

typedef struct node {
  int id;
  struct node *left, *right;
} Node;

Node* bt_create(int pos, int poe, int ios, int ioe) {
    int root = preorder[pos], idx = -1;
    for (int k=ios; k<=ioe; k++)
      if (inorder[k] == root)
        { idx = k; break; }
            
    /* printf("pos=%d poe=%d ios=%d ioe=%d idx=%d [root]=%d\n", pos, poe, ios, ioe, idx, root); */

    Node* n = malloc(sizeof(Node));
    n->id = root;
    n->left = (ios+1<=idx)
              ? bt_create(pos+1, pos+idx-ios, ios, idx-1)
              : NULL;
    n->right = (pos+idx-ios+1<=poe && idx+1<=ioe)
              ? bt_create(pos+idx-ios+1, poe, idx+1, ioe)
              : NULL;

    return n;
}
void bt_postorder(Node *t)
{
    if (t->left)  bt_postorder(t->left);
    if (t->right) bt_postorder(t->right);
    /* printf("[%d]:%x L:%x R:%x\n", t->id, t, t->left, t->right); */
    printf("%d", t->id);
    if (--N) putchar(' ');
}
/*
void print() {
  for (int i=0;i<N;i++)
    printf("%d ", preorder[i]);
  putchar('\n');
  for (int i=0;i<N;i++)
    printf("%d ", inorder[i]);
  putchar('\n');
}
*/

int main() {
    scanf("%d", &N); getchar();
    size_t sz = N * sizeof(int);
    preorder = malloc(sz);
    inorder = malloc(sz);
    int *stack = malloc(sz), top = -1;

    char op[5];
    while (~scanf("%[^ \n]s", op)) {
      if (op[1] == 'o')
        inorder[++top_inorder] = stack[top--];
      else {
        int node; scanf("%d", &node);
        preorder[++top_preorder] = node;
        stack[++top] = node;
      }
      getchar();
    }

    bt_postorder(bt_create(0, N-1, 0, N-1));
}