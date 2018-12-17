#include <memory.h>
#include "sort_common.h"

// 2018/08/10

void counting_sort(DATATYPE data[], int n, int k) {	// 排序n个取值在[0, k]之间的元素
	size_t sz = (k + 1) * sizeof(DATATYPE);
	int* cnt = malloc(sz);
	memset(cnt, 0x00, sz);

	for (int i=0; i<n; i++)
		cnt[data[i]]++;
	int idx = 0;
	for (int i=0; i<=k; i++)
		while (cnt[i]--)	// 有cnt[i]个i
			data[idx++] = i;
	
	free(cnt);
}