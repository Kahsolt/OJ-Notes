// Max Sum

#include <stdio.h>
#include <string.h>
#define MAXN 100000

int x[MAXN], cnt[MAXN];
int main() {
  int t; scanf("%d", &t);
  for (int i=1; i<=t; i++) {
    int n; scanf("%d", &n);
    for (int j=0; j<n; j++) scanf("%d", &x[j]);

    int maxsum = x[0], end = 0; cnt[0] = 0;
    for (int j=1; j<n; j++) {
      if (x[j-1] >= 0) {
        x[j] += x[j-1];
        cnt[j] = cnt[j-1] + 1;
      } else cnt[j] = 0;
      if (x[j] > maxsum) maxsum = x[end = j];
    }
    
    printf("Case %d:\n%d %d %d\n", i, maxsum, end-cnt[end]+1, end+1);
    if (i != t) putchar(10);
  }
}