// 2021/07/29 
// Note: 记录中序遍历中上一个节点last_node即可，还需要记录中序遍历的最开始节点init_node

struct TreeNode {
  int val;
  struct TreeNode *left;    // aka. prev, 指向中序遍历的前驱
  struct TreeNode *right;   // aka. next，指向中序遍历的后继
};

static struct TreeNode *last_node = NULL, *init_node = NULL; // fix startpoint
static struct TreeNode *stack[1000] = { NULL };
static int top = -1;

void inorder_rec(struct TreeNode* root) {
  if (root->left) inorder_proc(root->left);

  root->left = last_node;
  if (last_node) last_node->right = root;
  else init_node = root;
  last_node = root;

  if (root->right) inorder_proc(root->right);
}

void inorder(struct TreeNode* p) {
  while (p || top != -1) {
    // root
    while (p) {
      stack[++top] = p;
      p = p->left;
    }
    // root
    p = stack[top--];
    p->left = last_node;
    if (last_node) last_node->right = p;
    else init_node = p;
    last_node = p;
    // right
    p = stack[top]->right;
  }
}

struct TreeNode* Convert(struct TreeNode* root) {
  if (!root) return NULL;

  inorder_rec(root);
  last_node->right = NULL;  // fix endpoint

  return init_node;
}
