// 2021/07/26 
// Note: 就很申必，要遍历大树的每个节点、尝试视作小树的根节点、然后作contains检查
 
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
  bool _has_sub_tree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot2) return true;
    if (!pRoot1 && pRoot2) return false;

    return pRoot1->val == pRoot2->val 
              && _has_sub_tree(pRoot1->left, pRoot2->left)
              && _has_sub_tree(pRoot1->right, pRoot2->right);
  }
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (!pRoot1 || !pRoot2) return false;
    bool ok = _has_sub_tree(pRoot1, pRoot2);
    if (!ok && pRoot1->left) ok = HasSubtree(pRoot1->left, pRoot2);
    if (!ok && pRoot1->right) ok = HasSubtree(pRoot1->right, pRoot2);
    return ok;
  }
};