#include <stdio.h>
#define MAXN 4

// 2017-11-21
// 三对角矩阵的线性存储
// 矩阵规模: (MAXN*MAXN) => (3*MAXN-2)个非零元素

int matrix[3 * MAXN - 2] = {
  0, 1, 
  2, 3, 4,
     5, 6, 7,
        8, 9,
};

void index(int x, int y) {
  if (abs(x-y) > 1) puts("NULL");
  else printf("idx=%d\n", 2*x + y);
}
void ordinate(int idx) {
  printf("x=%d y=%d\n", 
    (idx+1)/3, (idx+1)/3 + (idx+1)%3 - 1);
}

int main() {
  index(1,1);
  index(1,2);
  ordinate(4);
  ordinate(8);
}
