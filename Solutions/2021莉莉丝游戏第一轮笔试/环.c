#include <stdio.h>

long long minimum(int* a, int aLen) {
    if (!a) return 0;
    if (aLen == 1) return a[0];
    if (aLen == 2) return abs(a[0] - a[1]);

    long long sum = 0;
    for (int i=0; i<aLen; i++) sum += a[i];
    long long ans = sum + 1;

    for (int j=1; j<aLen; j++) {        // make acc[]
        a[j] += a[j-1];
        int d = abs(sum - (a[j]<<1));
        if (!d) return 0;
        else if (d < ans) ans = d;
    }

    for (int i=0; i<aLen-1; i++) {
        for (int j=i+1; j<aLen; j++) {
            a[j] -= a[i];
          int d = abs(sum - (a[j]<<1));
          if (!d) return 0;
          else if (d < ans) ans = d;
        }
    }
    
    return ans;
}

int main() {
    int a[] = {1,2,3,4,5}, aLen = 5;
    long long ans = minimum(a, aLen);
    printf("%d\n", ans);
}