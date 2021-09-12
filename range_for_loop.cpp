#include <iostream>

int main(void)
{
    const char str[5] = {'h', 'e', 'l', 'l', 'o'};
    const char *gg = "I am writing some bs";
    std::cout << str << "\n";

    for (char c : str)
        std::cout << c << "\n";

    return 0;
}