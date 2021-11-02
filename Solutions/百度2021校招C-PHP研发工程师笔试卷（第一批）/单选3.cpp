#include<iostream>
using namespace std;
class A {
public:
    virtual void x() = 0;
};
class B :public A {
public:
    virtual void x(int a) {  }
};
int main()
{
    A *a = new B;
    delete a;
    return 0;
}