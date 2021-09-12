#include <iostream>

[[deprecated]]
void f(int* p);

void f(int* p)
{
    std::cout << "hello\n";
}

[[nodiscard]]
int forty2(void)
{
    return 42;
}

int main(void)
{
    f(nullptr);
    forty2();
    return 0;
}