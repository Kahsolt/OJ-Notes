#include "sort_common.h"

// 2018/08/10

void select_sort(DATATYPE data[], int n) {
  int minn, minidx;
  for (int i=0; i<n-1; i++) { // 找最小放在前面
    minn = data[minidx=i];
    for (int j=i+1; j<n; j++)
      if (data[j] < minn)
        minn = data[minidx=j];
    swap(data[i], data[minidx]);
  }
}

void select_sort_double_side(DATATYPE data[], int n) {
  int minn, maxx, minidx, maxidx;
  for (int i=0; i<=N>>1; i++) {   // 最小放前面，最大放后面
    minn = data[minidx=i];;
    maxx = data[maxidx=n-i+1];
    for (int j=i+1; j<n; j++)
      if (data[j] < minn)
        minn = data[minidx=j];
      else if (data[j] > maxx)
        maxx = data[maxidx=j];
    swap(data[i], data[minidx]);
    swap(data[n-i+1], data[maxidx]);
  }
}