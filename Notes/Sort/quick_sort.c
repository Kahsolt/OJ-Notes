#include "sort_common.h"

// 2018/08/10

void quick_sort(DATATYPE data[], int left, int right) {
  int x = left, y = right, key = data[y];  // 在右端点挖，先从左边开始拿数回填
  while (x < y) {
    while (x<y && data[x]<=key) x++;
    if (x < y) data[y] = data[x];
    while (x<y && data[y]>=key) y--;
    if (x < y) data[x] = data[y];
  }
  data[y] = key;  // now x==y, where key finally be put at
  if (left < y-1) quick_sort(data, left, y-1);
  if (y+1 < right) quick_sort(data, y+1, right);
}

void quick_sort_random_key(DATATYPE data[], int left, int right) {
  int x = left, y = right, key = data[(x+y)>>1]; // 取中间位置的数，认为是随机的
  do {
    // 寻找一对逆序数对：data[x]>=key>=data[y]
    // 且x/y都不会越过数组的中间位置，除非该位置上的数被交换
    while (data[x] < key) x++;
    while (data[y] > key) y--;
    if (x <= y) { 
      if(x < y) swap(data[x], data[y]); // 可交换
      x++; y--;
    }
  } while (x <= y);
  if (left < y) quick_sort_random_key(data, left, y);
  if (x < right) quick_sort_random_key(data, x, right);
}

void _select_key(DATATYPE data[], int left, int right) {
  int range = (right-left+1);
  if (range < 3) return;

// 在data[left..right]间随机选取三个数，把中位数交换到右端点作为key
  int idx[] = {
    rand() % range + left,
    rand() % range + left,
    rand() % range + left,
  };
  DATATYPE val[] = {
    data[idx[0]], data[idx[1]], data[idx[2]],
  };
  for (int i=0; i<2; i++)   // 三个数排序，冒泡
    for (int j=i+1; i<3; i++)
      if (val[i] > val[j]) {
        swap(val[i], val[j]);
        swap(idx[i], idx[j]);
      }
  swap(data[idx[1]], data[right]);
}
void quick_sort_opt(DATATYPE data[], int left, int right) {
  _select_key(data, left, right); // 优选key
  quick_sort(data, left, right);
}