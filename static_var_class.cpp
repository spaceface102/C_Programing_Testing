#include <iostream>

struct Stupid
{
    static const int g;
    int a;
};

const int Stupid::g = 50;

int main(void)
{
    std::cout << Stupid::g << "\n";
    Stupid();
    std::cout << Stupid::g << "\n";
    std::cout << Stupid::g << "\n";
    Stupid();
    std::cout << Stupid::g << "\n";
    return 0;
}