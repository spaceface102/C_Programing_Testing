#include <array>
#include <iostream>
#include <vector>
#include <variant>

void* operator new[](std::size_t size)
{
    std::cout << "Allocated memory: " << size << '\n';
    return malloc(size);
}

int main(void)
{
    //std::cout << sizeof(std::array<int, 10>) << '\n';
    //std::cout << sizeof(std::array<int, 20>) << '\n';
    //std::cout << sizeof(std::array<int, 30>) << '\n';
//
    //std::cout << sizeof(std::vector<std::array<int, 10>>) << '\n';
    //std::cout << sizeof(std::vector<std::array<int, 20>>) << '\n';
    //std::cout << sizeof(std::vector<std::array<int, 30>>) << '\n';
//
    std::vector<std::array<int, 10>> x(10);
    x.reserve(512);
std::variant<int, double> x;
    return 0;
}