// 2021/07/26 
// Note: 注意归并后反序；至少需要四个指针(两个源链表头，一个目标链表头，一个tmp)

/**
* struct ListNode {
*	int val;
*	struct ListNode *next;
* };
*/

struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
  struct ListNode *r = NULL, *nx, *p = NULL;

  // merge
  while (pHead1 && pHead2) {
    if (pHead1->val <= pHead2->val) {
      nx = pHead1->next;
      pHead1->next = r;
      r = pHead1;
      pHead1 = nx;
    } else {
      nx = pHead2->next;
      pHead2->next = r;
      r = pHead2;
      pHead2 = nx;
    }
  }
  while (pHead1) {
    nx = pHead1->next;
    pHead1->next = r;
    r = pHead1;
    pHead1 = nx;
  }
  while (pHead2) {
    nx = pHead2->next;
    pHead2->next = r;
    r = pHead2;
    pHead2 = nx;
  }
  
  // reverse
  while (r) {
    nx = r->next;
    r->next = p;
    p = r;
    r = nx;
  }

  return p;
}