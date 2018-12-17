#include <stdio.h>
#include <stdlib.h>

// 2018-09-07

typedef int DATATYPE;
typedef struct node {
  DATATYPE data;
  struct node *next;  // rear需要处理的下一个
} Node;
Node *head, *rear;

void q_init() {
  head = rear = NULL;
}
void q_print() {
  printf("=> ");
  Node *p = rear;
  while (p) {
    printf("%d ", p->data);
    p = p->next;
  }
  putchar('\n');
}
void q_enqueue(DATATYPE data) {
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL; // 这是队首，没有需要处理的下一个
  if (!head) head = rear = n;
  else head = head->next = n;
}
DATATYPE q_dequeue() {
  DATATYPE data = rear->data;
  Node *n = rear->next;
  free(rear);
  rear = n;
  if (!rear) head = NULL;
  return data;
}

int main() {
  q_init();
  q_enqueue(1);
  q_enqueue(2);
  q_print();
  printf("%d\n", q_dequeue());
  q_enqueue(3);
  q_enqueue(4);
  q_print();
  printf("%d\n", q_dequeue());
  printf("%d\n", q_dequeue());
  q_print();
  printf("%d\n", q_dequeue());
}
