#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define forr(i, a, b) for(int i=a;i<b;i++)
#define forp(i, a, b) for(int i=a;i<=b;i++)
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define min(a, b) (((a)<=(b))?(a):(b))
#define swap(a, b) (a)^=(b)^=(a)^=(b)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define prtl() putchar('\n')
#define prti(x) printf("%d", x)
#define prta(x, a, b) forr(i,a,b){if(i!=a)putchar(' ');prti(x[i]);}
int cmp(const void* a,const void *b){return *((int*)a)-*((int*)b);}
#define N 1000
/* Counting Nodes in a BST (30) */

typedef struct node {
  int val;
  struct node *left, *right;
} Node;

Node* tree = NULL; // global tree, avoid annoying ref-pointers
void bst_insert(int val) {
  Node* n = malloc(sizeof(Node)); // new leaf
  n->val = val;
  n->left = n->right = NULL;

  if (!tree) tree = n;  // insert root
  else {
    Node *t = tree, *ft;  // father of t
    while (t) {
      ft = t;
      if (val <= t->val) t = t->left; // '<='
      else t = t->right;
    }
    if (val <= ft->val) ft->left = n;
    else ft->right = n;
  }
}
void bst_levelorder() {
  Node* queue[N];
  int head = 0, rear = 0;
  queue[head++] = tree;
  int robin = head;

  int n1 = 0, n2 = 0;
  while (head != rear) {
    int cnt = 0;
    while (rear != robin) {
      Node* n = queue[rear];
      rear = (rear + 1) % N;
      cnt++;
      if (n->left) {
        queue[head] = n->left;
        head = (head + 1) % N;
      }
      if (n->right) {
        queue[head] = n->right;
        head = (head + 1) % N;
      }
    }
    n2 = n1; n1 = cnt;
    robin = head;
  }
  printf("%d + %d = %d", n1, n2, n1 + n2);
}

int main() {
  read(n);
  if (n <= 2) {
    if (!n) printf("0 + 0 = 0");
    else if (n == 1) printf("0 + 1 = 1");
    else if (n == 2) printf("1 + 1 = 2");
    return 0;
  }
  
  times(n) {
    read(x);
    bst_insert(x);
  }
  bst_levelorder();
}