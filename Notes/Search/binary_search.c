#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

// 2018/08/08

typedef int DATATYPE;
DATATYPE data[N];

int binary_search(int left, int right, DATATYPE val) {
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (val < data[mid]) right = mid - 1;
		else if (val > data[mid]) left = mid + 1;
		else return mid;
	}
	return -1;
}
int binary_search_rec(int left, int right, DATATYPE val) {
	if (left == right)
    return data[left] == val ? left : -1;
	else {
		int mid = (left + right) >> 1;
		if (val < data[mid])
      return binary_search_rec(left, mid-1, val);
		else if (val > data[mid])
      return binary_search_rec(mid+1, right, val);
		else return mid;
	}
}

int cmp(const void* a, const void* b) {
  return *(DATATYPE*)a - *(DATATYPE*)b;
}

int main() {
	srand(time(NULL));

	int n = rand() % N;
	for (int i=0; i<n; i++) data[i] = rand() % 10;
	qsort(data, n, sizeof(DATATYPE), cmp);
	int r = 10;
	while (r--) {
		int t = rand() % 10;
		printf("binary_search: %d\n", binary_search(0, n-1, t));
		printf("binary_search_rec: %d\n", binary_search_rec(0, n-1, t));
    DATATYPE* r = bsearch(&t, data, n, sizeof(DATATYPE), cmp);
		printf("bsearch: %d\n", r ? r - data : -1);
	}
}