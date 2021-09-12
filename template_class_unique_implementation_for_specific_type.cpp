#include <iostream>
#include <array>

template<typename T>
class Test
{
public:
    void hello(void);
private:
    T aType;
};

//obviously not all types have .size() method
//and therefore will cause an error
template<typename T>
void Test<T>::hello(void)
{
    std::cout << aType.size() << "\n";
}

//overides the stock hello implentation
//with this one for type double
template<>
void Test<double>::hello(void)
{
    std::cout << "Now we rolling biches\n";
}

int main(void)
{
    Test<std::array<int, 100>> umi;
    Test<double> dd;

    umi.hello();
    dd.hello();
    return 0;
}