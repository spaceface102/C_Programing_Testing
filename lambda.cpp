#include <iostream>

int main(void)
{
    const int dd = 34;
    int (*x)(int) = [](int value) -> int {std::cout << value << "\n"; return 42;};

    std::cout << x(8888) << "\n";
    return 0;
}