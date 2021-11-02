// 2021/07/30 
// Note: 

class Solution {
public:
  int solve(vector<vector<char> >& M) {
    int nrow = M.size();
    if (!nrow) return 0;
    int ncol = M[0].size();
    if (!ncol) return 0;

    int dp[10000][10000], nmax = -1;
    for (int i=0; i<nrow; i++) {
      dp[i][0] = M[i][0] - '0';
      if (dp[i][0] > nmax) nmax = dp[i][0];
    }
    for (int j=0; j<ncol; j++) {
      dp[0][j] = M[0][j] - '0';
      if (dp[0][j] > nmax) nmax = dp[0][j];
    }

    for (int i=1; i<nrow; i++)
      for (int j=1; j<ncol; j++)
        if (M[i][j] == '1') {
          int h = dp[i-1][j], w = dp[i][j-1];
          dp[i][j] = h == w
                        ? h + int(M[i-h][j-h] == '1')
                        : 1 + (h < w ? h : w);
          if (dp[i][j] > nmax) nmax = dp[i][j];
        } else dp[i][j] = 0;
  
    for (int i=0; i<nrow; i++) {
      for (int j=0; j<ncol; j++)
        printf("%d ", dp[i][j]);
      putchar('\n');
    }

    return nmax*nmax;
  }
};
