#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MAXN 100005

static int tree1[MAXN] = { 0 }, tree2[MAXN] = { 0 };
static int idx1[MAXN]  = { 0 }, idx2[MAXN]  = { 0 };
static int cnt = 0;

void preorder(struct TreeNode* r1, struct TreeNode* r2) {
  tree1[cnt] = r1->val, tree2[cnt] = r2->val;
  idx1[r1->val] = cnt, idx2[r2->val] = cnt;
  cnt++;

  if (r1->left)  preorder(r1->left,  r2->left);
  if (r1->right) preorder(r1->right, r2->right);
}

int swapNumbers(struct TreeNode* T1, struct TreeNode* T2) {
  if (T1 == NULL || T2 == NULL) return 0;

  preorder(T1, T2);

  int res = 0;
  for (int i=0; i<cnt; i++) {   // sort tree1 to match tree2
    if (tree1[i] == tree2[i]) continue;
    int from = i, tmp = tree1[from];
    tree1[from] = -1;
    while (1) {
      int to = idx2[tmp];
      if (tree1[to] == -1) { tree1[to] = tmp; break; }
      int tmp2 = tree1[to];
      tree1[to] = tmp, tmp = tmp2;
      res++;
    }
  }

  return res;
}
