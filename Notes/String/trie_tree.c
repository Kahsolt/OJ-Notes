#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#define NCHAR 26
#define N 100

// 2018/08/07
// 字典树，快速查询字典中含某前缀的单词数

typedef struct node {
  int cnt;            // 置于单词结尾标记结束，也标记该单词有多少个 
  int via;            // 途径这个节点的单词数，即前缀计数
  struct node** next; // 后继字母索引表
} Node;
Node nodes[N], *node_cur = nodes, *trie;

Node* tt_newnode() {  // clear a new node from pool
  node_cur->cnt = node_cur->via = 0;
  size_t sz = NCHAR * sizeof(Node*);
  node_cur->next = malloc(sz);
  memset(node_cur->next, 0x00, sz); // default NULL
  return node_cur++;
}

void tt_insert(char* s) {
  Node* p = trie;
  p->via++;
  while (*s != '\0') {
    int t = *(s++) - 'a';   // offset
    if (p->next[t] == NULL)
      p->next[t] = tt_newnode();
    p = p->next[t];
    p->via++;
  }
  p->cnt++;
}
static Node* tt_find(char* s) {
  Node* p = trie;
  while (*s != '\0') {
    int t = *(s++) - 'a';   // offset
    if (p->next[t] == NULL)
      return NULL;
    p = p->next[t];
  }
  return p;
}
int tt_count(char* s) {
  Node* n = tt_find(s);
  return n ? n->cnt : 0;
}
int tt_has(char* s) {
  return tt_count(s) > 0;
}
int tt_count_prefix(char* s) {
  Node* n = tt_find(s);
  return n ? n->via : 0;
}

int main() {
  trie = tt_newnode();  // 虚拟公共起始节点

  tt_insert(""); // 空串不影响
  tt_insert("banana");
  tt_insert("band");
  tt_insert("bee"); tt_insert("bee"); tt_insert("bee");
  tt_insert("absolute"); tt_insert("absolute");
  tt_insert("acm");
  printf("%d words in total\n", trie->via);

  printf("%d\n", tt_count_prefix("ba"));    // 2
  printf("%d\n", tt_count_prefix("b"));     // 5
  printf("%d\n", tt_count_prefix("band"));  // 1
  printf("%d\n", tt_count_prefix("abc"));   // 0
  puts("");
  printf("%d\n", tt_count("abc"));          // 0
  printf("%d\n", tt_count("bee"));          // 3
  printf("%d\n", tt_count("absolute"));     // 2
}