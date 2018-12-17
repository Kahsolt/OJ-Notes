#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define mod 32768

long long fibonacci(long long n) {
	if(n==1 || n==2) return 1;
	long long a=1, b=1, tmp;
	
	n-=2;
	while (n--) {
		tmp = b;
		b = (a + b) % mod;
		a = tmp;
	}
	return b;
}

int main() {
	srand(time(NULL));
	int t = rand() % 15 + 1;
	while (t--) {
		long long n = rand();
		printf("fib[%d]=%lld", n, fibonacci(n));
	}
	return 0;
}

