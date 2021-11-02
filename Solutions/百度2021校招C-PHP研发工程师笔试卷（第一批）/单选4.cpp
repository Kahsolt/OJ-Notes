#include <iostream>
#include <memory>
using namespace std;
void fun(std::shared_ptr<int> p)
{
    *p = 5;
}
int main()
{
    int arar = 6;
    for (int i = 0; i < 1000000; i++)
    {
        std::shared_ptr<int> p = std::make_shared<int>(arar);
        fun(p);
        std::cout << *p;
    }
    return 0;
}
