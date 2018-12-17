#include <stdio.h>
#include <stdlib.h>

// 2018/08/10

typedef int DATATYPE;
typedef struct list {
  DATATYPE* data;
  int length;
  int size; // malloc() max length avalible for data
} List;

List* ls_create(int size) {
  List* ls = malloc(sizeof(List));
  ls->length = 0;
  ls->size = size;
  ls->data = malloc(size * sizeof(DATATYPE));
  return ls;
}
void ls_destroy(List* ls) {
  if (ls) {
    if (ls->data) free(ls->data);
    free(ls);
  }
}
void ls_print(List* ls) {
  printf(">> ");
  for (int i=0; i<ls->length; i++)
    printf("%d ", ls->data[i]);
  putchar('\n');
}
DATATYPE ls_at(List* ls, int idx) {
  return ls->data[idx];
}
int ls_find(List* ls, int val) {
  for (int i=0; i<ls->length; i++)
    if (ls->data[i] == val) return i;
  return -1;
}
void ls_append(List* ls, int val) {
  ls->data[ls->length++] = val;
}
void ls_insert(List* ls, int idx, int val) {
  ls->length++;
  for (int i=ls->length; i>idx; i--)  // move backward
    ls->data[i] = ls->data[i-1];
  ls->data[idx] = val;
}
DATATYPE ls_delete(List* ls, int idx) {
  DATATYPE val = ls->data[idx];
  for(int i=idx; i<ls->length-1; i++) // move forward
    ls->data[i] = ls->data[i+1];
  ls->length--;
  return val;
}
int ls_remove(List* ls, int val) {
  int cnt = 0, k = 0;
  for (int i=0; i<ls->length; i++)
    if (ls->data[i] == val) cnt++;
    else ls->data[k++] = ls->data[i]; // 保留该元素
  ls->length -= cnt;
  return cnt;
}

int main() {
  List* ls = ls_create(5);
  ls_print(ls);
  ls_append(ls, 0);
  ls_append(ls, 2);
  ls_append(ls, 2);
  ls_insert(ls, 0, 3);
  ls_print(ls);
  ls_delete(ls, 1);
  ls_print(ls);
  ls_remove(ls, 2);
  ls_print(ls);
  printf("at: %d\n", ls_at(ls, 2));
  printf("find: %d\n", ls_find(ls, 3));
  ls_destroy(ls);
}
