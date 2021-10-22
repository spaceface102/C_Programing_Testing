#include <iostream>
class Test
{
public:
    Test* getthis(void)
    {
        return this;
    }
};

int main(void)
{
    Test something;
    Test* a = something.getthis();

    std::cout << &something << '\n';
    std::cout << a << '\n';
    std::cout << ((&something) == a) << '\n';
    return 0;
}