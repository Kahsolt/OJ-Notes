#include <stdlib.h>
#include <memory.h>
#include "sort_common.h"

// 2018/08/10

void _heapify(int *heap, int cur, int n) {
	int idx = cur<<1;		/* 先假定最大值为左儿子 */
	while (idx <= n)	{	/* 左儿子依然在N个考虑元素范围内 */
		if(idx+1 <=n && heap[idx+1]>heap[idx])
			idx++;					/* 若右儿子存在且大于左儿子，则移动最大值为右儿子 */
		if(heap[cur] < heap[idx]) {
			swap(heap[cur], heap[idx])
			cur = idx;			/* 移动至大儿子节点，迭代更新子树 */
			idx = cur<<1;		/* 变成子树的左儿子，即同步循环的初始条件 */
		} else break;
	}
}
void heap_sort(DATATYPE data[], int n) {
	DATATYPE* heap = malloc((n + 1) * sizeof(DATATYPE));
	size_t sz = n * sizeof(DATATYPE);
	memcpy(&heap[1], data, sz);	// heap[0] not used

	for(int i=n>>1; i>=1; i--) _heapify(heap, i, n);	// make big root heap
	for(int i=n; i>=1; i--) {
		swap(heap[1], heap[i]);			// move heap top to tail
		_heapify(heap, 1, i-1);			// shrink heap size & adjust down
	}

	memcpy(data, &heap[1], sz);	// copy back
	free(heap);
}