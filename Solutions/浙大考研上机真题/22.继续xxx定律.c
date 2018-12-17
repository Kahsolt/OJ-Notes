#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#define N 501
#define M 125253 // This is the upper limit, I carefully tested :(

int data[N];
bool visit[M];
int main() {
  int n; while (~scanf("%d", &n)) {
    if (!n) break;
    memset(visit, false, sizeof(visit)); visit[1] = true;
    
    for (int i=0; i<n; i++) {
      int x; scanf("%d", &x); data[i] = x;
      while (true) {
        x = (((x&0x01) ? (3*x+1) : x) >> 1);  // 3*n+1 law
        if (visit[x]) break;
        else visit[x] = true;
      }
    }

    for (int i=n-1; i>=0; i--)
      if (!visit[data[i]])
        printf("%d ", data[i]);
    putchar(10);
  }
}