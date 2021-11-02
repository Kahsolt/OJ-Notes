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
    r = q;        // 临时指针r，暂时记录新链表头
    q = p;        // 暂时记录从旧连表上取下的节点，将成为新链表头q
    p = p->next;  // 原链表头p，正向移动、链表不断缩短
    q->next = r;  // 让取下来的q头插到r上，q成为新链表头q
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