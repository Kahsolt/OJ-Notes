#include <iostream>
#include <list>
using namespace std;
/* Median (25) */

int main() {
  cin.sync_with_stdio(false);
  list<long long> ls;           // MLE!
  for (int t=1; t<=2; t++) {
    int k; cin >> k;
    while (k--) {
      long long n; cin >> n;
      ls.push_back(n);
    }
  }
  ls.sort();
  int cuts = ls.size() >> 1;
  auto idx = ls.begin();
  while (cuts--) idx++;
  cout << *idx;
}