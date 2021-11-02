// 2021/08/15 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> SpiralMatrix(vector<vector<int> >& matrix) {
    vector<int> r;
    int H = matrix.size();
    if (!H) return r;
    int W = matrix[0].size();
    if (!W) return r;

    int steps[] = {W, H-1, W-1, H-2};   // R-D-L-U
    int ii = 0, jj = -1;
    bool ok = false;
    while (!ok) {
      for (int i=0; !ok&&i<4; i++) {    // for each dir
        if (steps[i] <= 0) { ok = true; break; }
        for (int j=0; !ok&&j<steps[i]; j++) {   // go steps[i] steps 
          switch(i) {
            case 0: jj++; break;
            case 1: ii++; break;
            case 2: jj--; break;
            case 3: ii--; break;
          }
          r.push_back(matrix[ii][jj]);
        }
        steps[i] -= 2;
      }
    }

    return r;
  }
};

int main() {
  vector<int> line1 = {1,2,3,4};
  vector<int> line2 = {5,6,7,8};
  vector<int> line3 = {9,10,11,12};
  vector<vector<int>> matrix;
  matrix.push_back(line1);
  matrix.push_back(line2);
  matrix.push_back(line3);

  vector<int> r = Solution().SpiralMatrix(matrix);
  cout << r.size() << endl;
}