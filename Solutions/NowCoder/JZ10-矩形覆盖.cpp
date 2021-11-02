// 2021/07/02 
// Note: 动态规划地从小到大推算
 
class Solution {
public:
    int rectCover(int n) {
        if (n <= 1) return n;

        n -= 2;
        int f0 = 1, f1 = 2;
        while (n--) {
            int f2 = f0 + f1;
            f0 = f1; f1 = f2; 
        }
        return f1;
    }
};