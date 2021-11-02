// 2021/07/29 
// Note: 部分快速排序

class Solution {
public:
  int quick_select(vector<int> &input, int l, int r) {
    int pivot = input[l];
    while (l < r) {
      while (l < r && pivot <= input[r]) r--;      // would infinite loop if strictly `<`
      input[l] = input[r];
      while (l < r && input[l] <= pivot) l++;
      input[r] = input[l];
    }
    input[l] = pivot; // l==r assrted when loop breaks out
    return l;
  }
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (!k || k>input.size()) return vector<int>();
    if (k == input.size()) return input;

    int l = 0, r = input.size() - 1;
    while (l < r) {                             // 近似于二分搜索
      int p = quick_select(input, l, r);        // p is index
      if (p + 1 == k) break;                    // p不一定总能精确命中k-1
      else if (p + 1 < k) l = p + 1;
      else r = p - 1;
    }

    return vector<int>(input.begin(), input.begin() + k); // 前k个必然已经排好序或者部分有序
  }
};
