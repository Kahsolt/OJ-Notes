#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#define MAXN 500
#define EPS 1e-6

using namespace std;

/*
3 3
2 3 4
4 9 16

4 3
1 2 3 1234567
1 2 1234567
*/

int n, m, q;
set<int> s;
int w[MAXN];

int main() {
  cin.sync_with_stdio(false);

  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    cin >> w[i];
    s.insert(w[i]);
  }
  sort(w, w + n);

  for (int j=1; j<=m; j++) {
    cin >> q;
    int found = 0;
    for (int i=n-1; !found && i>=0; i--) {
      int x = w[i];
      double y = log(q) / log(x);
      int iy = (int) y;
      cout << "target y: " << y << endl;
      if (iy != x && y - iy < EPS && s.find(iy) != s.end()) {
        found = 1;
        cout << x << ' ' << iy << endl;
      }
    }
    if (!found) cout << "-1 -1" << endl;
  }
}
