#include <stdio.h>

//2017/11/21

#define move(n, from, to) \
	printf("[%d]: %c -> %c\n", n, from, to)

void hanoi(int n, char from, char via, char to) {
	if (n == 1) move(1, from, to);
	else {
		hanoi(n-1, from, to, via);
		move(n, from, to);
		hanoi(n-1, via, from, to);
	}
}

int main() {
	hanoi(3, 'A', 'B', 'C');
}