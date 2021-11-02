// 2021/10/02 
// Note: 

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define MAXLEN 10000

int cntT[127] = { 0 };   // hash for chars in T
int cnt[127] = { 0 };    // hash for chars in size window

class Solution {
public:
  void preproc(string &s) {
    for (int i=0; i<s.length(); i++)
      cntT[s[i]]++;
  }
  bool chk(string &s) {
    for (int i=0; i<s.length(); i++)
      if (cnt[s[i]] < cntT[s[i]])
        return false;
    return true;
  }
  string minWindow(string S, string T) {
    memset(cntT, 0, sizeof(cntT));
    memset(cnt, 0, sizeof(cnt));
    preproc(T);

    int lens = S.length();
    int i = 0, j = -1, minlen = MAXLEN+1, idx = -1;
    do {
      j++; cnt[S[j]]++;      // expand right
      while (i<=j && chk(T)) {    // shrink left
        printf("i=%d j=%d\n", i, j);
        int len = j - i + 1;
        if (len < minlen) {
          minlen = len;
          idx = i;
        }
        cnt[S[i]]--; i++;
      }
    } while (i<=j && j<lens-1);
    return minlen == -1 ? "" : S.substr(idx, minlen);
  }
};

int main() {
  Solution sol;
  
  cout << sol.minWindow("ab", "a") << endl;
  cout << sol.minWindow("XDOYEZODEYXNZ", "XYZ") << endl;
  cout << sol.minWindow("abcAbB", "AA") << endl;
}