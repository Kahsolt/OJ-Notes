// 2021/07/02 
// Note: 
 
int Fibonacci(int n) {
    if (n <= 1) return n;
    
    n -= 1;
    int f0 = 0, f1 = 1;
    while (n--) {
        int f2 = f0 + f1;
        f0 = f1; f1 = f2; 
    }
    return f1;
}