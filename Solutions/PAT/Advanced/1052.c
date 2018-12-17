#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define times(n) int _##n=n;while(_##n--)
#define N 100000

/* Linked List Sorting (25) */

typedef struct node {
  int data, next;
} Node;
Node nodes[N];

int ll_sort(int ll) {
  int S = ll, p = nodes[S].next;
  nodes[S].next = -1; // terminate the sorted list
  while (p != -1) {
    int q = nodes[p].next;  // detach node-p, save q as the next p
    if (nodes[p].data < nodes[S].data) {
      nodes[p].next = S;
      S = p;
    } else {
      int r = S;
      while (nodes[r].next != -1
          && nodes[nodes[r].next].data < nodes[p].data)
        r = nodes[r].next;
      nodes[p].next = nodes[r].next;
      nodes[r].next = p;
    }
    p = q;
  }
  return S;
}

void ll_print(int ll) {
  while (ll != -1) {
    printf(nodes[ll].next == -1
        ? "%05d %d %d\n"
        : "%05d %d %05d\n",
      ll, nodes[ll].data, nodes[ll].next);
    ll = nodes[ll].next;
  }
}

Node nodes[N];
int main() {
  memset(nodes, 0xFF, sizeof(nodes));
  int n, S; scanf("%d%d", &n, &S);
  times(n) {
    int addr; scanf("%d", &addr);
    scanf("%d", &nodes[addr].data);
    scanf("%d", &nodes[addr].next);
  }
  S = ll_sort(S);
  printf("%d %05d\n", n, S);
  ll_print(S);
}