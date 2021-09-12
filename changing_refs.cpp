#include <iostream>

int main(void)
{
    int hello = 0;
    int& ref = hello;

    std::cout << ref << "\n";
    hello = 42;
    std::cout << ref << "\n";
    return 0;
}