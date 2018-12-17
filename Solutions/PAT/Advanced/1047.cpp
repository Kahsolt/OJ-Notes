#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Student List for Course (25)

int main() {
  cin.sync_with_stdio(false);
  int n, k; cin >> n >> k; cin.get();
  vector<string> enroll[k];
  for (int i=0; i<n; i++) {
    string name; cin >> name;
    int c; cin >> c;
    while (c--) {
      int id; cin >> id;
      enroll[id-1].push_back(name);
    } cin.get();
  }
  for (int i=0; i<k; i++) {
    cout << i+1 << ' ' << enroll[i].size() << endl;
    sort(enroll[i].begin(), enroll[i].end());
    for (auto it=enroll[i].begin(); it!=enroll[i].end(); it++)
      cout << *it << endl;
  }
}
