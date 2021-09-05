#include <iostream>

class dumb
{
public:
    virtual void hello(void) = 0;
    static void hello(int x)
    {
        std::cout << x << " Different!\n";
    }
};

void dumb::hello(void)
{
    std::cout << "hello hello\n";
}

class stupid : public dumb
{
public:
    void hello(void) override
    {
        std::cout << "der\n";
    }
};

int main(void)
{
    stupid yes;
    yes.hello();
    yes.dumb::hello();
    yes.dumb::hello(42);
    dumb::hello(999);
    return 0;
}