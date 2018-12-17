#ifndef SORT_COMPARE
#define SORT_COMPARE

// 2018/08/10

#include <stdio.h>

#define N 1000
typedef int DATATYPE;
#define FORMAT_STRING "%d "
#define swap(a, b) a ^= b ^= a ^= b;

void print(DATATYPE* data, int n) {
#define NLIM 15
	int nlim = n > NLIM ? NLIM : n;
	for (int i=1; i<=nlim; i++)
		printf(FORMAT_STRING, data[i]);
	putchar('\n');
}

#endif