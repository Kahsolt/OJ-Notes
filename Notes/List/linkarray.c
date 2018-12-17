#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <time.h>
#define N 100

// 2018/09/05
// 数组模拟链表

typedef int DATATYPE;
typedef struct node {
  DATATYPE data;
  int next;
} Node;
Node nodes[N];

void la_print(int la) {
  puts("=================");
  while (la != -1) {
    printf(nodes[la].next == -1
        ? "%06d %3d %d\n"
        : "%06d %3d %06d\n",
      la, nodes[la].data, nodes[la].next);
    la = nodes[la].next;
  }
  puts("=================");
}

int la_reverse(int la) { // 三指针法
  int p = -1, q = la, r = nodes[la].next;
  while (q != -1) {
    nodes[q].next = p;
    p = q;
    q = r;
    r = nodes[r].next;
  }
  return p;
}

int main() {
  srand(time(NULL));
  memset(nodes, 0xFF, sizeof(nodes)); // clear

  int la = rand() % N, cur = la, next;  // start addr
  int len = rand() % 10;
  while (len--) {
    nodes[cur].data = rand() % 1000;
    do { next = rand() % N; }
      while (nodes[next].next != -1);
    if (len) nodes[cur].next = next;
    cur = next;
  }

  la_print(la);
  la = la_reverse(la);
  la_print(la);
}
