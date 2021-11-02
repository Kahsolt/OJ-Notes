// 2021/07/02 
// Note: 注意空树，该死的下标offset=1

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (!pre.size()) return NULL;
        
        //cout << "pre: ";
        //for (auto it=pre.begin(); it!=pre.end(); it++)
        //  cout << *it << " "; cout<< endl;
        //cout << "vin: ";
        //for (auto it=vin.begin(); it!=vin.end(); it++)
        //  cout << *it << " "; cout<< endl;
        
        auto root = pre.begin();
        TreeNode *node = new TreeNode(*root);
        //cout << "root = " << *root << endl;

        auto cp = vin.begin();
        for (; cp!=vin.end(); cp++) if (*cp == *root) break;
        int nLeft = cp - vin.begin(),
            nRight = vin.end() - cp - 1;
        //cout << "nLeft = " << nLeft << " nRight = " << nRight << endl;
        
        if (nLeft) node->left = reConstructBinaryTree(
                        vector<int>(root + 1, root + nLeft + 1),      // 不含右端点
                        vector<int>(vin.begin(), cp));
        if (nRight) node->right = reConstructBinaryTree(
                        vector<int>(root + nLeft + 1, pre.end()),
                        vector<int>(cp + 1, vin.end()));
        return node;
    }
};

int main() {
  vector<int> pre = {1,2,3,4,5,6,7};
  vector<int> vin = {3,2,4,1,6,5,7};
  Solution().reConstructBinaryTree(pre, vin);
}