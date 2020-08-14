#include <stdio.h>
#include <string.h>

// assured FULL binary tree
void bt_pre2inorder(char preorder[], int left, int right) {
  char root = preorder[left];
  int mid = ((right - left) >> 1) + left;
  if (left < mid) bt_pre2inorder(preorder, left + 1, mid);
  if (root != '#') putchar(root);
  if (mid < right) bt_pre2inorder(preorder, mid + 1, right);
}

int main() {
  char preoder[32]; scanf("%s", preoder);
  bt_pre2inorder(preoder, 0, strlen(preoder)-1);
}