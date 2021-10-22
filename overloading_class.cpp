#include <iostream>
#include <string>
class Test
{
public:
    //defining this as explcit makes the overloading more strict,
    //and won't allow for std::cout << x to implicitly convert to int
    explicit operator int(void)
    {
        std::cout << "Converting to a mfn integer!\n";
        return 42;
    }

    explicit operator double*(void)
    {
        std::cout << "Converting to a mf double pointer!\n";
        return nullptr;
    }

    explicit operator std::string(void)
    {
        std::cout << "Converting to a string!\n";
        return "Hello World!\n";
    }
};

#if 0
std::ostream& operator<<(std::ostream& out, const Test& obj)
{
    out << "using overloaded operator<<(std::ostream& out, const Test& obj)\n";
    return out;
}
#endif

int main(void)
{
    Test x;
    int y  = int{x};
    std::cout << "Have not printed yet\n" << int(x) << "Done printing\n";
    std::cout << static_cast<double*>(x) << "\n";

    std::string hello = std::string(x);
    return 0;
}