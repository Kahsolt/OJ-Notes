#include <iostream>
#include <string>
using namespace std;

// 2018-07-30
// 树遍历：输入两个字符串，前序+中序 => 后序
//

char ans[30];
int idx = 0;  // counter

void solve(string s1, string s2) {
  if (s1.length() == 0) return;  // empty tree
  if (s1.length() == 1)        // only one root node
    { ans[idx++] = s1[0]; return; }
  
  // postorder traversal
  int idx = s2.find(s1[0]);      // find root inorder then split it
  solve(s1.substr(1, idx), s2.substr(0, idx));  // put left tree
  solve(s1.substr(idx+1, s1.length()-idx-1),    // put right tree
        s2.substr(idx+1, s2.length()-idx-1));
  ans[idx++] = s1[0]; // put root
}

int main() {
  string pre, in; cin >> pre >> in;
  solve(pre, in);
  ans[pre.length()] = '\0';   // fix str
  cout << ans;
}
