// 2021/07/29 
// Note: 死记硬背记结论罢

class Solution {
public:
  // 字典序法： https://blog.csdn.net/babynumber/article/details/42706757
  // 有序、去重
  vector<string> Permutation(string str) {
    vector<string> r;
    int len = str.length();
    char tmp;
    sort(str.begin(), str.end());
    r.push_back(str);

    while (true) {
      // step 1: 从右到左寻找一个x[i]<x[i+1]的邻对
      int i = len - 2;
      for (; i>=0 && str[i]>=str[i+1]; i--);
      if (i == -1) break;   // 若找不到说明已经完全字典逆序，结束

      // step 2: 在x[i]的右边找到最小的比它大的数字x[j](到着找必然是第一个)
      int j = len - 1;
      for (; j>i && str[i]>=str[j]; j--);
      tmp = str[i], str[i] = str[j], str[j] = tmp;

      // step 3: 将x[i]的右边的串reverse
      for (i=i+1, j=len-1; i<j; i++, j--)
        tmp = str[i], str[i] = str[j], str[j] = tmp;

      // 加入结果
      r.push_back(str);
    }
    return r;
  }
  // 邻位互换法: https://blog.csdn.net/BabyNumber/article/details/43866675
  // 无序、去重
  vector<string> Permutation2(string str) {
    vector<string> r;
    int len = str.length();
    char tmp;
    bool dir[len], tmp2;    // 0-left, 1-right
    memset(dir, false, sizeof(dir));
    sort(str.begin(), str.end());   // 从最小的字典序开始
    r.push_back(str);

    while (true) {
      // step 1: 找出值最大的可活动的x[i]，可活动指x[i]比dir[i]方向上的邻居大
      int idx = -1, max_v = -1;
      for (int i=0; i<len; i++) {
        int j = dir[i] ? i + 1: i - 1;
        if (j < 0 || j >= len) continue;
        if (str[i] > str[j])           // active
          if (str[i] > max_v)          // maximum
            {max_v = str[i]; idx = i;}
      }
      if (idx == -1) break;   // 若找不到说明已经完全字典逆序，结束

      // step 2: 交换x[i]和其指向的邻居x[j]
      int neigh = dir[idx] ? idx + 1: idx - 1;
      tmp = str[idx], str[idx] = str[neigh], str[neigh] = tmp;
      tmp2 = dir[idx], dir[idx] = dir[neigh], dir[neigh] = tmp2; // NOTE: 不要忘了交换这个标记数组！

      // step 3: 将值比x[i]大的数方向反转
      for (int i=0; i<len; i++)
        if (str[i] > str[idx])
          dir[i] = !dir[i];

      // 加入结果
      r.push_back(str);
    }
    sort(r.begin(), r.end());   // 需对结果再排序
    return r;
  }
};
