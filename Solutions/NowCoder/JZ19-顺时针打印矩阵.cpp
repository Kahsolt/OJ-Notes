// 2021/07/26 
// Note: 边界检测，特殊值作visit标记
 
class Solution {
public:
  vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> r;
    int H = matrix.size();
    if (!H) return r;
    int W = matrix[0].size();
    if (!W) return r;
    
    int direct = 0;         // 0-Right, 1-Down, 2-Left, 3-Up
    int i = 0, j = 0;       // indexes
    int R = W * H;
    while (R--) {
      r.push_back(matrix[i][j]);
      matrix[i][j] = -42;   // mark it MAGIC

      // detect if should turn away
      switch (direct) {
        case 0: if (j == W - 1 || matrix[i][j+1] == -42) direct = 1; break;
        case 1: if (i == H - 1 || matrix[i+1][j] == -42) direct = 2; break;
        case 2: if (j == 0 || matrix[i][j-1] == -42) direct = 3; break;
        case 3: if (i == 0 || matrix[i-1][j] == -42) direct = 0; break;
      }
      // step award
      switch (direct) {
        case 0: j++; break;
        case 1: i++; break;
        case 2: j--; break;
        case 3: i--; break;
      }
    }
    return r;
  }
};
