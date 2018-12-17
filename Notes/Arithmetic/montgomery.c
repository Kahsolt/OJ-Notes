#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 2017-11-21
// 快速幂模 a^b mod c

// 二进制化b，从低位开始处理
int montgomery(int a, int b, int c) {
	int ans = 1;
	a %= c;
	while (b) {
		if (b & 1) ans = ans * a % c;	// 若b为奇数，补一项a
		b >>= 1;	// b折半
		a = (a * a) % c;
	}
	return ans;
}

// 二分递归：a^b == a^(b/2) * a^(b/2)
int montgomery_rec(int a, int b, int c) {
  if (b == 1) return a;
  int s = mod(a, b >> 1, c) % c;	/* 分成两半 */
  return (b & 1) 
      ? (s * s % c) * a % c	/* 两半s，奇数补一个a (s * s * a % c)*/
      : s * s % c;
}

int main() {
	srand(time(NULL));

	int t = rand() % 15 + 1;
	while (t--) {
		int a = rand();
		int b = rand();
		int c = rand();
		printf("%d ^ %d = %d (mod %d)\n", a, b, montgomery(a, b, c), c);
		printf("%d ^ %d = %d (mod %d)\n", a, b, montgomery_rec(a, b, c), c);
	}
}