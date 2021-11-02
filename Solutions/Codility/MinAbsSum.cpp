// 2021/10/11 

// 2021/10/11 

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define abs(x) x>0?x:-x

int solution(vector<int> &A) {
  if (A.empty()) return 0;

  set<int> s[2];
  int from = 0;
  s[from].insert(0);
  for (auto it=A.begin(); it!=A.end(); ++it) {
    int to = !from; s[to].clear();
    for (auto jt=s[from].begin(); jt!=s[from].end(); ++jt) {
      s[to].insert(*jt + *it);
      s[to].insert(*jt - *it);
    }
    from = to;
  }

  int ans = 0x3f3f3f3f;
  for (auto jt=s[from].begin(); ans && jt!=s[from].end(); ++jt) {
    cout << *jt << endl;
    int r = abs(*jt);
    if (r < ans) ans = r;
  }
  return ans;
}

int main() {
  vector<int> A = { 1, 5, 2, -2 };
  solution(A);
}