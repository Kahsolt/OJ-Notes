#include "sort_common.h"

// 2018/08/10

void insert_sort(DATATYPE data[], int n) {
	for (int i=1; i<n; i++)
		if (data[i] < data[i-1])	{	// 逆序则交换
			int tmp = data[i], j;
			for (j=i; j>0 && data[i]<data[j]; j--)	// 整块后移
				data[j] = data[j-1];
			data[j] = tmp;
		}
}

void insert_sort_binary(DATATYPE data[], int n) {
	for (int i=1; i<n; i++)				// data[0]已经有序，从1开始
		if (data[i] < data[i-1]) {	// 逆序，二分插入前面的有序序列
			int tmp = data[i];
			int low = 0, high = i-1;
			while (low <= high) {
				int mid = (low + high) >> 1;
				if (tmp < data[mid]) high = mid - 1;
				else low = mid + 1;
			}
			for (int j=i; j>low; j--)	// 整块后移
				data[j] = data[j-1];
			data[low] = tmp;
		}
}
