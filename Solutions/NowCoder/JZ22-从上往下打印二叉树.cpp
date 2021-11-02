// 2021/07/26 
// Note: 层次遍历用队列

class Solution {
public:
  vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> r;
    if (!root) return r;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *n = q.front(); q.pop();
      r.push_back(n->val);
      if (n->left) q.push(n->left);
      if (n->right) q.push(n->right);
    }
    return r;
  }
};
