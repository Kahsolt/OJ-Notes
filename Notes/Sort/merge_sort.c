#include <memory.h>
#include "sort_common.h"

// 2018/08/10

void _merge(DATATYPE data[], int left, int mid, int right) {
	int i = left, j = mid+1, k = 0;
	size_t sz = (right-left+1) * sizeof(DATATYPE);
	DATATYPE* tmp = malloc(sz);

	while (i<=mid && j<=right)
		if (data[i] <= data[j]) tmp[k++] = data[i++];
		else tmp[k++] = data[j++];
	while (i <= mid) tmp[k++] = data[i++];
	while (j <= right) tmp[k++] = data[j++];
	memcpy(&data[left], tmp, sz);
	
	free(tmp);
}
void merge_sort(DATATYPE data[], int left, int right) {
	if (left < right) {
		int mid = (left+right)>>1;
		merge_sort(data, left, mid);
		merge_sort(data, mid+1, right);
		_merge(data, left, mid, right);
	}
}