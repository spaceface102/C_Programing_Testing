#include <string>
#include <iostream>

int main(void)
{
    std::string test;

    test.resize(10);

    test.at(1) = 'b';
    test.at(4) = 'h';
    test.at(9) = 'a';
    std::cout << test << "\n";
    std::cout << test.size() << "\n";
    return 0;
}