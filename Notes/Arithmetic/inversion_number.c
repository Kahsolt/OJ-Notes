#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define N 1000000
#define M 300000

// 2018-08-01
// 三种方法求序列的逆序数：模拟、分治、树状数组
//

int inv_num_simple(int x[], int n) {
	int cnt = 0;
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(x[i] > x[j]) cnt++;
	return cnt;
}

int inv_num_dq(int x[], int left, int right) {
	int mid = (left + right) >> 1;
	int lcnt = left < mid ? inv_num_dq(x, left, mid) : 0;
	int rcnt = mid+1 < right ? inv_num_dq(x, mid+1, right) : 0;
	int icnt = 0;
	for (int i=left; i<=mid; i++)
		for (int j=mid+1; j<=right; j++)
			if (x[i] > x[j]) icnt++;
	return lcnt + rcnt + icnt;
}

#define lowbit(k) (k&-k)
void bit_add(int s[], int idx, int val) {
	for (; idx<=M; idx+=lowbit(idx))
		s[idx] += val;
}
int bit_sum(int s[], int idx) {
	int ans = 0;
	for (; idx>0; idx-=lowbit(idx))
		ans += s[idx];
	return ans;
}
int inv_num_bit(int x[], int n) {
	int res = 0, s[M] = { 0 };	// count times of appearence

	for (int i=0; i<n; i++) {
		// add appearence once
		bit_add(s, x[i], 1);
    // now we have (i+1) numbers to consider
		// count numbers bigger than s[i]
		res += (i + 1 - bit_sum(s, x[i]));
	}

	return res;
}

int main() {
	srand(time(NULL));
	int t = rand() % 15 + 1;
	
	int x[N];
	while (t--) {
		int n = rand() % (N - 1) + 1;
		for (int i=0; i<n; i++)
		  x[i] = rand() % (M - 1) + 1;
		
		clock_t t, e; int res;
		t = clock(); res = inv_num_simple(x, n); e = clock();
		printf("[%ld]\tinv_num_simple = %d\n", e-t, res);
		t = clock(); res = inv_num_dq(x, 0, n-1); e = clock();
		printf("[%ld]\tinv_num_dq = %d\n", e-t, res);
		t = clock(); res = inv_num_bit(x, n); e = clock();
		printf("[%ld]\tinv_num_bit = %d\n", e-t, res);	
		printf("==========================\n");
	}
}