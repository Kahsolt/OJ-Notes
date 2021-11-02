// 2021/10/10 

#include <stdlib.h>
#include <string.h>

#define min(x,y) x<=y?x:y

typedef struct node {
  int L, R, X;
  struct node *left, *right;
} Node;

Node* new_node(int L, int R, int X) {
  Node *n = (Node*) malloc(sizeof(Node));
  n->L = L, n->R = R;
  n->X = X;
  n->left = n->right = NULL;
  return n;
}

Node* build(char *S, int L, int R) {
  if (L == R) return new_node(L, R, S[L]);

  Node *n = new_node(L, R, -1);
  int M = (L + R) >> 1;
  n->left = build(S, L, M),
  n->right = build(S, M+1, R);
  n->X = min(n->left->X, n->right->X);
  return n;
}

int query(Node* p, int L, int R) {
  if (L <= p->L && p->R <= R) return p->X;

  int M = (L + R) >> 1, ret = 5;        // 5 is the maximun
  if (p->left && L <= M) {
    int r = query(p->left, L, R);
    ret = min(r, ret);
  }
  if (p->right && M < R) {  // M+1 <= R
    int r = query(p->right, L, R);
    ret = min(r, ret);
  }
  return ret;
}

struct Results solution(char *S, int P[], int Q[], int M) {
  int N = strlen(S);
  for (int i=0; i<N; i++)
    switch (S[i]) {
      case 'A': S[i] = 1; break;
      case 'C': S[i] = 2; break;
      case 'G': S[i] = 3; break;
      case 'T': S[i] = 4; break;
    }
  Node* r = build(S, 0, N - 1);

  int *A = (int*) malloc(sizeof(int) * N);
  for (int j=0; j<M; j++)
    A[j] = P[j] == Q[j] ? S[P[j]] : query(r, P[j], Q[j]);

  struct Results result;
  result.A = A;
  result.M = M;
  return result;
}
