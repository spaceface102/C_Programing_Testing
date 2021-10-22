#include <list>
#include <iostream>

int main(void)
{
    #if 0
    {
        std::list<int> hello = {1, 2, 3};
        std::list<int>::iterator it = hello.begin();

        ++it;
        hello.pop_front();

        std::cout << it.operator*() << "\n";
    }

    std::list<int> x = {1, 2, 3, 4, 5, 6, 7};
    auto it = ++(++(++x.begin()));
    
    for (const auto& node : x)
        std::cout << node << ", ";
    std::cout << "\n";
    std::cout << *it << "\n";

    x.insert(it, 1);
    x.insert(it, 2);
    x.insert(x.begin(), 42);
    x.insert(--x.end(), {234, 43, 574});
    for (const auto& node : x)
        std::cout << node << ", ";
    std::cout << "\n";
    std::cout << *it << "\n";
    #endif

    std::list<int> x;
    const std::list<int> y;
    auto it_x = x.begin(); //iterator
    auto it_y = y.begin(); //const_iterator

    return 0;
}