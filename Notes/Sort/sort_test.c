#include <stdlib.h>
#include <time.h>
#include "bubble_sort.c"
#include "counting_sort.c"
#include "heap_sort.c"
#include "insert_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"
#include "select_sort.c"
#include "shell_sort.c"

// 2018/08/10

#define MAXN 100000

DATATYPE *data, *copy, *ans;
int n;
size_t sz;
clock_t t;

int cmp(const void* a, const void *b) {
  return *(DATATYPE*)a - *(DATATYPE*)b;
}
void gen_data(int size) {
  srand(time(NULL));
  n = size;
  sz = n * sizeof(DATATYPE);
  data = malloc(sz);
  copy = malloc(sz);
  ans = malloc(sz);
  for (int i=0; i<n; i++)
    data[i] = rand() % MAXN;
  memcpy(ans, data, sz);
  qsort(ans, n, sizeof(DATATYPE), cmp);
}
void free_data() {
  free(data);
  free(copy);
  free(ans);
}
void check() {
  for (int i=0; i<n; i++)
    if (copy[i] != ans[i])
      return puts(">> Uncorrect.");
}

int main() {
  gen_data(50000); 

  memcpy(copy, data, sz); t = clock(); bubble_sort(copy, n);
  check(); printf("bubble_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); counting_sort(copy, n, MAXN-1);
  check(); printf("counting_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); heap_sort(copy, n);
  check(); printf("heap_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); insert_sort(copy, n);
  check(); printf("insert_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); insert_sort_binary(copy, n);
  check(); printf("insert_sort_binary: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); merge_sort(copy, 0, n-1);
  check(); printf("merge_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); quick_sort(copy, 0, n-1);
  check(); printf("quick_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); quick_sort_random_key(copy, 0, n-1);
  check(); printf("quick_sort_random_key: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); quick_sort_opt(copy, 0, n-1);
  check(); printf("quick_sort_opt: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); select_sort(copy, n);
  check(); printf("select_sort: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); select_sort_double_side(copy, n);
  check(); printf("select_sort_double_side: %d\n", clock()-t);
  memcpy(copy, data, sz); t = clock(); shell_sort(copy, n);
  check(); printf("shell_sort: %d\n", clock()-t);

  free_data();
}