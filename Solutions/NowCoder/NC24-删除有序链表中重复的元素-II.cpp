// 2021/08/11 
// Note: 

#define MAGIC -114514

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return NULL;

    // make pseudo-head
    ListNode* phead = new ListNode(MAGIC);
    phead->next = head;

    ListNode *fp = phead, *p = head, *r;
    int to_delete = MAGIC;
    while (p) {
      // 若p和p->next值相等为val，以fp为基准删除所有值为val的节点
      if (p->next && p->next->val == p->val) {
        to_delete = p->val;
        while (to_delete != MAGIC) {
          r = p; p = p->next; delete r;
          fp->next = p;
          if (!p || p->val != to_delete)   // 如果p已经是新值，跳出
            to_delete = MAGIC;
        }
      } else {
        fp = p; p = p->next;
      }
    }

    return phead->next;
  }
};
