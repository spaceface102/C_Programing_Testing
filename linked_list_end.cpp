#include <iostream>
#include <list>

class Test
{
public:
    Test(void)
    {
        std::cout << "Calling default constructor of test!\n";
    }
};

int main(void)
{
    std::list<int> x = {1, 2, 3, 4, 5, 6, 7};
    const std::list<int>::iterator it = x.end();

    //random test
    #if 0
    std::cout << &(*(it)) << "\n";
    std::cout << &(*(it++++++++)) << "\n";
    std::cout << &(*(it)) << "\n\n";

    std::cout << &(*(it)) << "\n";
    std::cout << &(*(++it)) << "\n";
    std::cout << &(*(++it)) << "\n";
    std::cout << &(*(it)) << "\n";
    #endif

    std::cout << *x.end() << "\n";

    x.pop_back();
    //std::cout << (it == x.end()) << "\n";
    std::cout << *x.end() << "\n";
    std::cout << *(----x.end()) << "\n";
    std::cout << *it << "\n\n";

    std::cout << (*(++++x.end())) << "\n";
    //std::cout << (&(*it) == &(*x.end())) << "\n";

    std::cout << "\n\n";
    std::list<Test> y;
    std::cout << "\n";
    *y.end();
    *(++y.end());
    return 0;
}