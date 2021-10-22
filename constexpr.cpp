#include <iostream>

struct Test
{
    int a;
    int b;
    int c;
};


constexpr Test hello(int x)
{
    return {x<<1, x<<2, x<<3};
}

int main(void)
{
    constexpr int x = 32;
    const int y = 32;
    constexpr Test g = hello(x);
    constexpr Test d = hello(y);
    std::cout << "hello world\n";
    return 0;
}