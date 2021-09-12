#include <iostream>

class Base
{};

class Derived : public Base
{};

class EvenMoreDerived : public Derived
{};

class SameAsDerived : public Base
{};

int main(void)
{
    Derived hello;
    EvenMoreDerived yes_sir;
    Base& first = hello;
    Base& second = yes_sir;
    Derived& third = yes_sir;
    //SameAsDerived& fourth = yes_sir; //cant do this shit 
}