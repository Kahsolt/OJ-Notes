#include <stdio.h>
#include <stdlib.h>
#define times(n) int _##n=n;while(_##n--)
#define input(x) scanf("%d",&x)
#define read(x) int x;input(x)
#define N 100000

/* 1057 Stack (30) */

typedef struct node {
  int data;
  struct node* next;  // stack
  struct node* succ;  // ordered list
} Node;

int main() {
  Node* foobar = malloc(sizeof(Node));
  foobar->data = 0;
  foobar->next = foobar->succ = NULL;
  
  read(n); getchar();
  times(n) {
    char op[11]; scanf("%s", op);
    if (op[1] == 'u') {
      read(val); getchar();
      foobar->data++;
      Node* n = malloc(sizeof(Node));
      n->data = val;
      // push into stack
      n->next = foobar->next;
      foobar->next = n;
      // insert into list
      if (!foobar->succ) {
        n->succ = NULL;
        foobar->succ = n;
      } else {
        Node* ll = foobar;
        while (ll->succ && ll->succ->data < val)
          ll = ll->succ;
        n->succ = ll->succ;
        ll->succ = n;
      }
      /* DEBUG */
      // printf("[Stack]: ");
      // Node* p = foobar->next;
      // while (p) {
      //   printf("%d ", p->data);
      //   p = p->next;
      // }
      // putchar(10);
      // printf("[List]: ");
      // p = foobar->succ;
      // while (p) {
      //   printf("%d ", p->data);
      //   p = p->succ;
      // }
      // putchar(10);
    } else if (op[1] == 'o') {
      if (!foobar->data) { puts("Invalid"); continue; }
      Node* n = foobar->next;
      // pop from stack
      foobar->next = n->next;
      // delete from list
      Node* ll = foobar;
      while (ll->succ && ll->succ != n)
        ll = ll->succ;
      ll->succ = ll->succ->succ;
      printf("%d\n", n->data);
      free(n); foobar->data--;
    } else {  // op[1] == 'e'
      if (!foobar->data) { puts("Invalid"); continue; }
      int skipcnt = (foobar->data - 1) >> 1;
      Node* ll = foobar->succ;
      while (skipcnt--) ll = ll->succ;
      printf("%d\n", ll->data);
    }
  }
}