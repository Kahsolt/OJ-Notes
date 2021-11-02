// 2021/07/26 
// Note: 暴力搜索
 
class Solution {
public:
  void visit(TreeNode* root, int n, vector<int> &t, vector<vector<int> > &r) {
    t.push_back(root->val);
    
    if (!root->left && !root->right) {
      if (n == root->val) r.push_back(t);
    } else {
      if (root->left) visit(root->left, n - root->val, t, r);
      if (root->right) visit(root->right, n - root->val, t, r);
    }
    t.pop_back();
  }
  vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    vector<vector<int> > r;
    vector<int> t;
    if (root) visit(root, expectNumber, t, r);
    return r;
  }
};
