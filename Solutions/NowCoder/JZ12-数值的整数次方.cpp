// 2021/07/02 
// Note: 标准答案使用了快速幂算法
 
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent < 0) {             // 预处理负指数
            exponent = -exponent;
            base = 1 / base;
        }
        double x = base, r = 1.0;
        while (exponent) {
            if (exponent & 1) r *= x;   // 如果比特位为1，将该步的基数乘入答案
            x *= x;                     // 将基数平方化
            exponent >>= 1;
        }
        return r;
    }
};