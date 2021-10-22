#include <variant>
#include <iostream>
#include <cstdint>
#include <array>

#define SIZE_DEMO 0
#define TESTING 0

//I am not so sure about this one, maybe just typedefing this
//joint might be better...
template<typename ...Types>
class Test : public std::variant<Types...>
{
};

typedef std::variant<double, int> myVariant;

//Since the type of variant will be know, it is ok to do this
class Better_Test
{
public:
    Better_Test& operator=(const Better_Test&) = default;

    template<typename T>
    void operator=(T&& data) noexcept
    {
        var = data;
    }

    template<typename T>
    auto get(void) noexcept
    {
        return std::get<T>(var);
    }

private:
    myVariant var;
};


myVariant func0(void)
{
    myVariant temp = 10;
    return temp;
}

void func1(myVariant& var)
{
    var = 42.0;
}

int main(void)
{
    #if SIZE_DEMO
    std::cout << sizeof(std::variant<int>) << '\n';
    std::cout << sizeof(std::variant<int, double>) << '\n';
    std::cout << sizeof(std::variant<std::uint8_t, double>) << '\n';
    std::cout << sizeof(std::variant<std::array<int, 100>>) << '\n';
    std::cout << sizeof(std::variant<std::array<int, 100>, std::array<int, 50>, double>) << '\n';
    #endif

    #if TESTING
    std::variant<std::variant<int, double>, long> a;
    a = std::variant<int, double>{};
    //a = std::variant<double, int>{};  order matters! 
    std::variant<int, double> b = std::get<std::variant<int, double>>(a);

    std::cout << std::get<int>(func0()) << '\n';
    myVariant e{333};
    func1(e);
    std::cout << std::get<double>(e) << '\n';

    Better_Test hmm;
    hmm = 888;

    int der = hmm.get<int>();
    std::cout << hmm.get<int>() << '\n';
    std::cout << hmm.get<double>() << '\n';
    #endif


    std::variant<int, double, long> data{3L};
    long& along = std::get<long>(data);
    along = 32;
    std::cout << std::get<long>(data) << '\n';
    return 0;
}