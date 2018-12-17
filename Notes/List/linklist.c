#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

typedef int DATATYPE;
typedef struct node {
  DATATYPE data;
  struct node* next;
} Node;

Node* ll_create();
void ll_find(Node* ll, int val);
void ll_count(Node* ll, int val);
void ll_insert(Node* ll, int idx, DATATYPE val);
DATATYPE ll_delete(Node* ll, int idx);
void ll_remove(Node* ll, int val);
void ll_sort(Node* ll);
void ll_dedup(Node* ll);
void ll_reverse(Node* ll) {
  Node* nl = NULL;
  while (ll) {
    Node* p = ll;   // 取下头
    ll = ll->next;  // 旧链表移动
    p->next = nl;   // 新链表头指向原新链表头
    nl = p;         // 更新新链表头
  }
  ll = nl;
}
void ll_reverse2(Node* ll) {
  Node *p = ll, *q = NULL, *r;
  while (p) {
    r = q;        // r反向移动
    q = p;        // q反向移动
    p = p->next;  // p正向移动
    q->next = r;  // 让q连接r
  }
  ll = q;
}
void ll_destroy(Node* ll) {
  while (ll) {
    Node* p = ll;
    ll = ll->next;
    free(p);
  }
}
void ll_print(Node* ll) {
  int cnt = ll->data;
  while (cnt--) {
    ll = ll->next;
    printf("%d ", ll->data);
  }
  printf("\n");
}

int main() {

}