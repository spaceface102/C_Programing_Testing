#include <variant>
#include <iostream>

typedef std::variant<int, double> MyVariant;

struct Test
{
public:
    template<typename T>
    Test(const T& obj) : var{obj} {}

    MyVariant var;
};

template<typename T>
auto&& func1(T&& x)
{
    return x;
}

int main(void)
{
    Test x = 42;
    std::get<int>(x.var);
    std::get<double>(Test{42.0}.var);

    const int a = 4;
    func1(a);
    return 0;
}