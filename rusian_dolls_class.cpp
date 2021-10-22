#include <iostream>

template<typename E>
class Outer
{


private:
    template<typename T>
    class Inner
    {
    public:
        int a;
        int b;
        int c;
    };

private:
    Inner<E> x;


public:
    Inner<E> whatInner(void) {return Inner<E>{};}
    void doSomething(void)
    {
        x.a = 42; //won't work if a is a private member of class Inner!
    }
};

int main(void)
{
    Outer<double> x;
    x.whatInner();
    x.doSomething();
    return 0;
}