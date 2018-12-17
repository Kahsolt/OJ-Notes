#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 101

// 2018/08/01
// 二进制索引树/树状数组(aka. Fenwick Tree)
//   常用于求前缀和
//

int s[N]; /* s[0] unused */

#define lowbit(x) (x & -x)
void bit_add(int idx, int val) {
  while (idx < N) {
    s[idx] += val;
    idx += lowbit(idx);
  }
}
int bit_sum(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += s[idx];
    idx -= lowbit(idx);
  }
  return sum;
}

int main() {
  srand(time(NULL));
  int t = rand() % N + 1;
  while (t--) {
    int idx, val = rand() % 100;
    if(rand() & 1) val = -val;
    printf("add %d to idx [%d]\t", val, idx);
    do { idx = rand() % N; } while (idx == 0);
    bit_add(idx, val);
    do { idx = rand() % N; } while (idx == 0);
    printf("sum[%d] = %d\n", idx, bit_sum(idx));
  }
}