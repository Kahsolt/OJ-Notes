#include <math.h>
#include "sort_common.h"

// 2018/08/13

void shell_sort(DATATYPE data[], int n) { // optimized bubble sort
	int k = (int) sqrt(n);    // step: sqrt(n) down to 1
  while (k > 1) {
    for (int i=0; i<k; i++)
      for (int j=i+k; j<n; j+=k)
        if (data[j] > data[j-k])
          swap(data[j], data[j-k]);
    k = (int) sqrt(k);
  };
}