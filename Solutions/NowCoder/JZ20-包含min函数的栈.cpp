// 2021/07/26 
// Note: 开个平行的辅助栈即可
 
class Solution {
private:
  stack<int> val;
  stack<int> min_val;
public:
  void push(int value) {
    val.push(value);
    if (min_val.empty()) min_val.push(value); //  注意这里判空
    else min_val.push(value <= min_val.top() ? value : min_val.top());
  }
  void pop() {
    val.pop();
    min_val.pop();
  }
  int top() {
    return val.top();
  }
  int min() {
    return min_val.top();
  }
};
