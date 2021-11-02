// 2021/08/14 

#include <stdio.h>
#include <stdbool.h>

static int op[3] = { 0 };   // add=0, sub=1, mul=2, div=3 
static int ok = false;

int calc(int *arr) {
  int ans = 0, r = arr[0], sign = 1;
  for (int i=1; i<=3; i++) {
    switch (op[i]) {
    case 0:
      ans += sign * r;
      sign = 1; r = arr[i];
      break;
    case 1:
      ans += sign * r;
      sign = -1; r = arr[i];
      break;
    case 2:
      r *= arr[i]; break;
    case 3:
      r /= arr[i]; break;
    }
  }
  ans += sign * r;
  //printf("ans = %d\n", ans);
  return ans;
}

void search(int* arr, int r) {
  if (r == 3) {
    ok = calc(arr) == 24;    
    return;
  }

  for (int i=0; !ok&&i<4; i++) {
    op[r] = i;
    search(arr, r+1);
  }
}

bool Game24Points(int* arr, int arrLen) {
  search(arr, 0);
  return ok;
}

int main() {
  int arr[] = {7,2,1,10}, arrLen = 4;
  printf("%d\n", Game24Points(arr, arrLen));
}