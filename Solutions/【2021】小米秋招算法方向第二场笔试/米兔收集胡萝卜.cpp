#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
// 2021/08/09

inline int max(int a, int b) { return a >= b ? a : b; }

class Solution {
public:
  int maxPathSum(vector<vector<int> >& a) {
    int nrow = a.size(); if (!nrow) return 0;
    int ncol = a[0].size(); if (!ncol) return 0;

    for (int i=1; i<nrow; i++)
      a[i][0] += a[i-1][0];
    for (int j=1; j<ncol; j++)
      a[0][j] += a[0][j-1];

    for (int i=1; i<nrow; i++)
      for (int j=1; j<ncol; j++)
          a[i][j] += max(a[i-1][j], a[i][j-1]);
    
    return a[nrow-1][ncol-1];
  }
};

int main() {
  vector<vector<int> > a;
  vector<int> line1 = { 1, 4, 9 }; a.push_back(line1);
  vector<int> line2 = { 3, 5, 9 }; a.push_back(line2);
  cout << Solution().maxPathSum(a) << endl;
}
