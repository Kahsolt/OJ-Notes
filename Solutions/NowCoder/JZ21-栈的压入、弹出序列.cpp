// 2021/07/26 
// Note: 模拟吞吐即可
 
class Solution {
public:
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> s;
    for (int i=0, j=0; i<pushV.size(); i++) {
      s.push(pushV[i]);
      while (!s.empty() && popV[j] == s.top()) { j++; s.pop(); }
    }
    return s.empty();
  }
};
