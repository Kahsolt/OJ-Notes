#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define N 100

//2018/08/14

typedef int DATATYPE;
typedef struct node {
	DATATYPE data;
	struct node *lchild, *rchild;
} Node;

void bst_destroy(Node* t) {
	if (!t) return;
	if (t->lchild) bst_destroy(t->lchild);
	if (t->rchild) bst_destroy(t->rchild);
	free(t);
}
Node* bst_search(Node* t, DATATYPE val) {
	while (t && t->data!=val)
		t = val < t->data ? t->lchild : t->rchild;
	return t;
}
bool bst_insert(Node* *t, DATATYPE val) {
  Node *p = *t, *f = *t;	// copy, father node before search quit
	while (p && p->data!=val) {
		f = p;
		p = val < p->data ? p->lchild : p->rchild;
	}
	if (p) return false;	// assure uniqueness
	
	Node* n = malloc(sizeof(Node));
	n->lchild = n->rchild = NULL;
	n->data = val;
	if (!f) *t = n;	// insert at root
	else {
		if (val < f->data) f->lchild = n;
		else f->rchild = n;
	}
	return true;
}
Node* bst_create(DATATYPE* data, int size) {
  Node* t = NULL;
	for (int i=0; i<size; i++)
		bst_insert(&t, data[i]);
  return t;
}
bool bst_delete(Node* t, DATATYPE val) {	// TODO: not implemented
	Node *s = t, *f = t;	// search node and its father
	while (s && s->data!=val) {
		f = s;
		s = val < s->data ? s->lchild : s->rchild;
	}
	if (!s) return false;	// not found
	
	if (s->lchild && s->rchild)	{	// twin
		s = t->lchild;
		while (s->rchild) {
			f = s;
			s = s->rchild;
		}
		t->data = s->data;
		t = s;
	} else if (s->lchild || s->rchild) {	// single
		if (s->data < f->data) f->lchild = s;
		else f->rchild = s;
		if(t->rchild) s = t->lchild;
		else s = t->rchild;
	}

	free(s);
	return true;
}
void bst_print_inorder(Node* t) {
	if (!t) return;
	if (t->lchild) bst_print_inorder(t->lchild);
	printf("%d ", t->data);
	if (t->rchild) bst_print_inorder(t->rchild);
}

int main() {
	srand(time(NULL));

	DATATYPE data[N];
	int n = 10;
	for (int i=0; i<n; i++) {
		data[i] = rand() % 15;
		printf("%d ", data[i]);
  } putchar(10);
	
	Node* t = bst_create(data, n);
	bst_print_inorder(t);
	bst_destroy(t);
}