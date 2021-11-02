#include<iostream>
void func(int *a, int &c)
{
    a = &c;
}
int main()
{
    int b = 1;
    int *a = &b;
    int c = 2;
    func(a, c);
    std::cout << *a << std::endl;
    return 0;
}