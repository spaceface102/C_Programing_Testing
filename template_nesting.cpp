#include <iostream>

template<std::size_t Tbase>
class Test
{
public:
    template<std::size_t Tanother_base>
    Test<Tanother_base> doSomething(const Test<Tbase>& that);
};

template<std::size_t Tbase> 
    template<std::size_t Tanother_base>
Test<Tanother_base> Test<Tbase>::doSomething(const Test<Tbase>& that)
{
    return Test<Tanother_base>();
}


int main(void)
{
    Test<5> x;

    x.doSomething<50>(x);
    return 0;
}