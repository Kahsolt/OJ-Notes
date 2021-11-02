// 2021/07/26 
// Note: 注意短路运算先后顺序的细节
 
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* FindKthToTail(struct ListNode* pHead, int k) {
  struct ListNode *p = pHead, *q = pHead;
  while (p && k--) {       // NOTE: 注意这里短路运算不要写反了
    //printf("k = %d, p->val = %d\n", k, p->val);
    p = p->next;
  }
  if (k > 0) return NULL;
  //printf("k = %d\n", k);
  while (p) { p = p->next; q = q->next; }
  return q;
}

void print(struct ListNode* p) {
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
  putchar('\n');
}

int main() {
  struct ListNode *p = NULL;
  for (int i=5; i>=1; i--) {
      struct ListNode *n = malloc(sizeof(struct ListNode));
      n->val = i;
      n->next = p;
      p = n;
  }
  print(p);

  p = FindKthToTail(p, 6);
  print(p);
}