#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define times(n) int _##n=n;while(_##n--)
#define mset(d, v) memset(d,v,sizeof(d))
#define input(x) scanf("%d",&x)
#define N 10
#define COMPAROR <

typedef struct node {
  int id;
  struct node *left, *right;
} Node;
bool visit[N];
Node* bst_create(char* data) {
  Node* t = NULL; char* p = data;
  while (*p != '\0') {
    int id = *p++ & 0x0F;
    Node* n = malloc(sizeof(Node));
    n->id = id;
    n->left = n->right = NULL;

    if (!t) t = n;
    else {
      Node *q = t, *fq;
      while (q) {
        fq = q;
        if (id COMPAROR q->id) q = q->left; 
        else q = q->right;
      }
      if (id COMPAROR fq->id) fq->left = n;
      else fq->right = n;
    }
  }
  return t;
}
bool bst_check(Node* t, char* data) {
  char* p = data; while (*p != '\0') {
    int id = *p & 0x0F; Node *q = t;
    while (q->id != id) {
      if (!visit[q->id]) return false;  // nodes along this path MUST have been visited
      if (id COMPAROR q->id) q = q->left;
      else q = q->right; 
    }
    visit[id] = true; // mark visit
    p++;
  }
  return true;
}

int main() {
  int n; while (~input(n)) {
    if (!n) break; getchar();
    char buf[N+1]; gets(buf);
    Node* t = bst_create(buf);
    times(n) {
      gets(buf); mset(visit, false);
      puts(bst_check(t, buf) ? "YES" : "NO");
    }
  }
}