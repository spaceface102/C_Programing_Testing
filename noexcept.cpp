#include <iostream>

int test(int index) noexcept
{
    if (index%99)
        //will cause termination since function signature 
        //says noexcept, if it said noexcept(false) we would
        //all be good
        throw 20;
    return 4;
}

int main(void)
{
    test(99);
    test(100);
    return 0;
}