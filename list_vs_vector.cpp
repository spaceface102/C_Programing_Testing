#include <iostream>
#include <list>
#include <vector>

int main(void)
{
    std::vector<std::size_t> vector(1e6, 42);
    std::list<std::size_t> list(1e6, 42);

    return 0;
}