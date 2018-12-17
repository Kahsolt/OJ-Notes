#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100

// 2018/08/25
//
// Havel-Hakimi定理：
// 根据顶点的度序列判断是否可图，可图则一般来说不唯一
//

int cmp(const void* a, const void* b) { // '>'
  return (*(int*)b) - (*(int*)a);
}
bool havel_hakimi(int deg[], int n) {
  for (int i=0; i<n; i++) {
    qsort(deg+i, n-i, sizeof(int), cmp);  // sort descending
    int maxdeg = deg[i];  // pop the vertex with max deg
    for (int j=1; j<=maxdeg; j++) {
      int idx = i + j;  //  decrease the following j deg[i+1, i+j]
      deg[idx]--; // deg--: link an edge from v-i to v-idx
      if (deg[idx] < 0) return false; // invalid deg
    }
  }
  return true;
}
int main() {
  int r = 3;
  int n[] = { 8, 10, 6 };
  int deg[][N] = {
    { 7, 7, 4, 3, 3, 3, 2, 1 },       // NO
    { 5, 4, 3, 3, 2, 2, 2, 1, 1, 1 }, // Yes
    { 2, 5, 4, 3, 3, 1 },             // Yes
  };

  for (int i=0; i<r; i++)
    puts(havel_hakimi(deg[i], n[i]) ? "Yes" : "No");
}