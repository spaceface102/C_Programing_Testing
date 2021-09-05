#include <iostream>

int global = 5;

int test(void)
{
    return ++global;
}

int main(void)
{
    int global;

    global = 3;
    
    std::cout << test() << "\n";
    std::cout << global << "\n";
    std::cout << ::global << "\n";
    return 0;
}