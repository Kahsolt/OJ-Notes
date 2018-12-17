#include <iostream>
using namespace std;
#define N 100

// 2018/08/14

template <typename T> class BiStack {
private:
    T* _data;
    size_t _size;
    int _top1, _top2;
public:
    BiStack(int size=10) : _size(size), _top1(0), _top2(size-1)
      { _data = new T[size]; }
    const void push1(T val) { _data[_top1++] = val; }
    const void push2(T val) { _data[_top2--] = val; }
    const T pop1() { return _data[--_top1]; }
    const T pop2() { return _data[++_top2]; }
    virtual ~BiStack() { delete[] _data; }
};

int main() {
    BiStack<int> s(2);
    s.push1(1);
    s.push2(2);
    printf("%d\n", s.pop1());
    printf("%d\n", s.pop2());
    s.push1(3);
    s.push1(4);
    s.push2(5); // overwrite!
    s.push2(6);
    printf("%d\n", s.pop1());
    printf("%d\n", s.pop1());
    printf("%d\n", s.pop2());
    printf("%d\n", s.pop2());
}