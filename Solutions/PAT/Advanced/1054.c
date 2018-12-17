#include <stdio.h>
/* The Dominant Color (20) */

int main() {
  int n, m;
  scanf("%d%d", &m, &n);

  /* 
    O(N) algorithm for finding 
    dominant element in a data stream
  */
  int cur = -1;   // the consecutive elmt in current consideration
  int ans = -1;   // final result elmt
  int cnt = 0;    // count the presence of cur
  int maxcnt = 0; // count the presence of ans
  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
      int c;
      scanf("%d", &c);
      if (!i && !j) ans = c;  // init ans
      if (c == cur) {
        cnt++;
        if (cnt > maxcnt) { // MUST be strictly greater than '>'
          maxcnt = cnt;
          ans = cur;
        }
      } else cur = c;
    }
  
  printf("%d\n", ans);
}