#include <cassert>
#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

template<typename E>
auto func(E x)
{
    return x + 42;
}

class Test
{
public:
    Test(void) {};
    Test(int x) {};
    Test operator+(const Test& that) {return Test{42};};
};

//a lot of containers return int& (for example) for the overloaded
//operator[], and unfortunately, for some reason I can not add a const
//qualifer to the type deduced, therefore the data passed in must be a ref...
//WAIT, maybe type casting to a const version of the container would therefore
//force the container to deduce a const int& and therefore we are golden!!!!!
//looks hacky, and I am unsure if this is intended behavior
template<typename E>
void ordered_insert(E& container, decltype(static_cast<const E&>(container)[0]) data)
{
    assert(container.size() > 0 && "Container must have a size > 0!\n");
    std::size_t i = container.size() - 1;
    for (; i >= 1 && container[i - 1] > data; i--)
        container[i] = container[i - 1];
    container[i] = data;
}

//WAIT, I think the compiler can probably deduce the type of the second
//thing without using decltype.....
template<typename E, typename E_elem>
void use_this_instead(E& container, const E_elem& data)
{
    assert(container.size() > 0 && "Container must have a size > 0!\n");
    std::size_t i = container.size() - 1;
    for (; i >= 1 && container[i - 1] > data; i--)
        container[i] = container[i - 1];
    container[i] = data;
}

template<typename E>
std::ostream& display(const E& container, std::ostream& out = std::cout)
{
    for (auto&& element : container)
        out << element << ", ";
    return out;
}

int main(void)
{
    #if 0
    auto x = func(43);
    auto y = func(42.9);
    auto z = func(Test{42});
    decltype(x) a = 43;
    decltype((x)) b = x;
    #endif

    std::vector<int> x = {1, 2, 4, 5, 6, 7};
    std::array<int, 6> y = {1, 2, 4, 5, 6, 7};
    std::vector<int>& x_ref = x;

    display(x) << '\n';
    display(y) << '\n';

    ordered_insert(x_ref, 0);
    ordered_insert(x, 42);


    use_this_instead(y, 342);
    display(x) << '\n';
    display(y) << '\n';

    return 0;
}