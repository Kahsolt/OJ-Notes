// 2021/07/02 
// Note: 经典位运算trick
 
class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while (n) {
             n = n & (n-1);    // 将最低位的1抹去
             cnt++;
         }
         return cnt;
     }
};