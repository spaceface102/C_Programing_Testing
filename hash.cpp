#include <iostream>
#include <functional>
#include <unordered_map>

struct A
{
public:
    int a;
    int b;
};

class B
{
public:
    B(int a, int b) noexcept : a{a}, b{b} {}
private:
    int a;
    int b;
};

namespace std
{
    template<>
    struct hash<A>
    {
        std::size_t operator()(const A& obj)
        {
            return (std::hash<int>{}(obj.a) << 1) ^ (std::hash<int>{}(obj.b));
        }
    };

    template<>
    struct hash<B>
    {
        std::size_t operator()(const B& obj)
        {
            return 
            std::_Hash_impl::hash(static_cast<const void*>(&obj), sizeof(obj));
        }
    };
}


template<typename T>
T func(void)
    {return T();}

template<>
int func<int>(void)
    {return 42;}

int main(void)
{
    A a = {0xf, 1};
    B b = {1, 2};
    std::cout << std::hash<std::size_t>{}(1000) << "\n";
    std::cout << std::hash<A>{}(a) << "\n";

    std::cout << func<int>() << '\n' << func<double>() << '\n';

    #if 0
    //just returns the address of the pointer!
    std::cout << '\n' << std::hex << std::hash<const char*>{}("I am stupid!\n") << '\n';
    char* ptr = "I am stupid!\n";
    std::cout << static_cast<void*>(ptr) << "\n";
    #endif

    std::cout << "\n\n\n" << std::hash<std::string>{}("I fall in love with mindy :)") << "\n";
    std::cout << std::hex << std::hash<std::string>{}("I am stupid!\n") << "\n\n";

    std::cout << std::hex << std::hash<B>{}(b) << "\n";
    return 0;
}