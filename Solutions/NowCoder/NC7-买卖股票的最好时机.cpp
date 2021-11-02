// 2021/07/29 
// Note: 贪心找极差
 
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    auto it = prices.begin();
    int lowest = *it++, r = 0;
    for (; it!=prices.end(); ++it) {
      if (*it < lowest) lowest = *it;
      if (*it - lowest > r) r = *it - lowest;
    }
    return r;
  }
};
