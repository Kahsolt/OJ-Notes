// 2021/07/02 
// Note: 不能把STL vector当stack用，因为pop_back()仅丢弃末尾元素而没有返回值！

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> rev = vector<int>();
        vector<int> ret = vector<int>();
        while (head) {
            rev.push_back(head->val);
            head = head->next;
        }
        for (auto it=rev.rbegin(); it!=rev.rend(); it++)
            ret.push_back(*it);
        return ret;
    }
};
