#include <iostream>
#include <algorithm>
#define MAXN 100000

using namespace std;

/*
3
9 7 4
6
17 3 21 8 44 24
*/

int speed[MAXN];

static inline int max(int a, int b) { return a >= b ? a : b; }

int main() {
  cin.sync_with_stdio(false);

  const int k = 10;
  int n; cin >> n;
  if (!n) { cout << 0; return 0; }
  for (int i=0; i<n; i++) cin >> speed[i];
  sort(speed, speed+n);
  
  // for (int i=0; i<n; i++) cout << speed[i] << ' '; cout << endl;

  int ans = 0;
  int i = 0, j = 0;
  while (j < n) {    
    while (j < n && speed[j] - speed[i] <= k) j++;
    // cout << i << ' ' << j << endl;
    ans = max(ans, j-i);
    //do { i++; } while (j < n && i < j && speed[i] == speed[i+1]);
    i++;
  }

  cout << ans << endl;
}