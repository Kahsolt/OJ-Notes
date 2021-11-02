// 2021/07/26 
// Note: 头插法，先detach再insert再step；至少需要三个指针(两个链表头，一个tmp)

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

void print(struct ListNode* p) {
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  putchar('\n');
}

struct ListNode* ReverseList(struct ListNode* pHead) {
  struct ListNode *q = NULL, *r;
  while (pHead) {
    r = pHead->next;     // detatch
    pHead->next = q;     // insert at head
    q = pHead;
    pHead = r;           // 步进
  }
  return q;
}

int main() {
  struct ListNode *p = NULL;
  for (int i=3; i>=1; i--) {
      struct ListNode *n = malloc(sizeof(struct ListNode));
      n->val = i;
      n->next = p;
      p = n;
  }
  print(p);

  p = ReverseList(p);
  print(p);
}