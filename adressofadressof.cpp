#include <iostream>

int main(void)
{
    int x = 42;

    std::cout << x << "\n";
    std::cout << &x << "\n";
    //std::cout << &(&x) << "\n"; ILLEGAL OPERATION as &x is rvalue

    return 0;
}