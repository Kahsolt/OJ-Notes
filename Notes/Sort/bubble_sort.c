#include "sort_common.h"

// 2018/08/10

void bubble_sort(DATATYPE data[], int n) {
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (data[i] > data[j])
				swap(data[i], data[j]);
}