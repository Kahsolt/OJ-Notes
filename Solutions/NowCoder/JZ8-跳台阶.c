// 2021/07/02 
// Note: 找规律填数
 
int jumpFloor(int n) {
    if (n <= 3) return n;
    
    n -= 2;
    int f0 = 1, f1 = 2;
    while (n--) {
        int f2 = f0 + f1;
        f0 = f1; f1 = f2; 
    }
    return f1;
}