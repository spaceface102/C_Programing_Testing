#include <iostream>

class Test
{
public:
    typedef int aType;

    int x;
};

int main(void)
{
    Test::aType hello;

    return 0;
}