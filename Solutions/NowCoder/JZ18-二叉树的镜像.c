// 2021/07/26 
// Note: 递归地交换左右子树完事
 
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

struct TreeNode* Mirror(struct TreeNode* pRoot) {
  if (!pRoot) return NULL;

  if (pRoot->left) Mirror(pRoot->left);
  if (pRoot->right) Mirror(pRoot->right);
  struct TreeNode *tmp = pRoot->left; 
  pRoot->left = pRoot->right; 
  pRoot->right = tmp;

  return pRoot;
}