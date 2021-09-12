#include <iostream>

template <typename T>
class Test : public T
{

};

class Cool
{
public:
    void Hello(void) {std::cout << "Hello World!\n";}
};

int main(void)
{
    Test<Cool> h;
    h.Hello();

    Test<std::ostream> hmm;
    hmm << "hello"; //doesn't do shit, but it sure does compiler
    return 0;
}