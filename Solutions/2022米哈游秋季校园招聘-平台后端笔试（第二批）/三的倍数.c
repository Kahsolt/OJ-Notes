#include <stdio.h>

// f(0) = 0
// f(n) = f(n-1) + (n - 2);

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        n /= 3;
        if (n <= 2) puts("0");
        else printf("%d\n", (n-1)*(n-2)/2);
    }
}