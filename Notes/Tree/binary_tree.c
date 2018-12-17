#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef int DATATYPE;
typedef struct node {
	DATATYPE data;
	struct node *lchild, *rchild, *parent;
} Node;

void bt_print_preorder_rec(Node *t) {
	if (!t) return;
	printf("%d ", t->data);
	if (t->lchild) bt_print_preorder_rec(t->lchild);
	if (t->rchild) bt_print_preorder_rec(t->rchild);
}
void bt_print_inorder_rec(Node *t) {
	if (!t) return;
	if (t->lchild) bt_print_inorder_rec(t->lchild);
	printf("%d ", t->data);
	if (t->rchild) bt_print_inorder_rec(t->rchild);
}
void bt_print_postorder_rec(Node *t) {
	if (!t) return;
	if (t->lchild) bt_print_postorder_rec(t->lchild);
	if (t->rchild) bt_print_postorder_rec(t->rchild);
	printf("%d ", t->data);
}
void bt_print_preorder(Node *t) {
	Node* stack[N]; int top = 0;
	
	while (t || top) {
		while (t) {
			stack[top++] = t;
			printf("%d ", t->data);	// 先根
			t = t->lchild;					// 一路左到底
		}
		t = stack[--top];
    t = t->rchild;		// 处理右子树
	}
}
void bt_print_inorder(Node *t) {
	Node* stack[N]; int top = 0;
	
	while (t || top)  {  
		while (t)  {  
			stack[top++] = t;  
			t = t->lchild;  	// 压左到底
		}  
		t = stack[--top];
		printf("%d ", t->data);	// 中根
		t = t->rchild;  	// 处理右子树
	}                                                                                                                                     
}
void bt_print(Node *t) {  // 广义表打印
	if (!t) return;
	printf("%d", t->data);
	if (t->lchild || t->rchild) {
		putchar('(');
		if (t->lchild) bt_print(t->lchild);
		putchar(',');
		if (t->rchild) bt_print(t->rchild);
		putchar(')');
	}
}
int bt_height(Node *t) {
	if (!t) return 0;
	else {
		int lh = t->lchild ? bt_height(t->lchild) : 0;
		int rh = t->rchild ? bt_height(t->rchild) : 0;
		return __max(lh, rh) + 1;
	}
}

int main() {

}