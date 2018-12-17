#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 100

// 2018/09/15

typedef int DATATYPE;
typedef struct node {
	DATATYPE data;
	int balance_factor;
	struct node *parent;
	struct node *lchild, *rchild;
} Node;

Node* avl_search(Node* t, DATATYPE val) {
	while (t && t->data!=val)
		t = val < t->data ? t->lchild : t->rchild;
	return t;
}
bool avl_insert(Node* *t, DATATYPE val) {
	return true;
}
Node* avl_create(DATATYPE* data, int size) {
  Node* t = NULL;
	for (int i=0; i<size; i++)
		avl_insert(&t, data[i]);
  return t;
}
void avl_print_inorder(Node* t) {
	if (!t) return;
	if (t->lchild) avl_print_inorder(t->lchild);
	printf("%d ", t->data);
	if (t->rchild) avl_print_inorder(t->rchild);
}

int main() {
	srand(time(NULL));

	DATATYPE data[N];
	int n = 10;
	for (int i=0; i<n; i++) {
		data[i] = rand() % 15;
		printf("%d ", data[i]);
  } putchar(10);

	Node* t = avl_create(data, n);
	avl_print_inorder(t);
}
