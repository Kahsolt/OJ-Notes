#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
#define N 10000

// 2021/08/09 

static int R, C;
static bool *FLAG;
inline bool get_flag(int r, int c) { return FLAG[r*C+c]; }
inline void set_flag(int r, int c, bool v) { FLAG[r*C+c] = v; }
static int dx[] = { 1, -1, 0, 0 };
static int dy[] = { 0, 0, 1, -1 };

class Solution {
public:
  inline bool chk(int r, int c) { return 0 <= r && r < R && 0 <= c && c < C; }
  bool search(vector<vector<char> > &board, int r, int c, string &word, int idx) {
    cout << " >> now at (" << r << ", " << c << "), "
            "next for word[" << idx<<"]= " << word[idx] << endl;

    for (int d=0; d<4; d++) {
      int nr = r + dx[d], nc = c + dy[d];
      if (chk(nr, nc) && !get_flag(nr, nc) && board[nr][nc] == word[idx]) {
        if (idx == word.length()-1) return true;
        else {
          set_flag(nr, nc, true);
          if (search(board, nr, nc, word, idx+1)) return true;
          set_flag(nr, nc, false);
        }
      }
    }
    return false;
  }

  bool exist(vector<vector<char> > &board, string word) {
    R = board.size(); if (!R) return false;
    C = board[0].size(); if (!C) return false;
    if (!word.length()) return true;

    cout << "R=" << R << ", C=" << C << endl;
    for (int i=0; i<R; i++) {
      for (int j=0; j<C; j++)
        cout << board[i][j];
      cout << endl;
    }
    cout << "--------------------" << endl;
    cout << word << endl;
    cout << "====================" << endl;
    
    FLAG = new bool[R*C];
    for (int i=0; i<R; i++)
      for (int j=0; j<C; j++)
        if (board[i][j] == word[0]) {
          memset(FLAG, false, sizeof(bool)*R*C);
          if (search(board, i, j, word, 1)) return true;
        }

    return false;
  }
};

int main() {
  vector<vector<char> > board;
  vector<char> line;
  line.push_back('X'); line.push_back('Y'); line.push_back('Z'); line.push_back('E');
  board.push_back(line); line.clear();
  line.push_back('S'); line.push_back('F'); line.push_back('Z'); line.push_back('S');
  board.push_back(line); line.clear();
  line.push_back('X'); line.push_back('D'); line.push_back('E'); line.push_back('E');
  board.push_back(line); line.clear();

  Solution solut;
  cout << solut.exist(board, "XYZZED") << endl; 
  cout << solut.exist(board, "SEE") << endl; 
  cout << solut.exist(board, "XYZY") << endl; 
}
