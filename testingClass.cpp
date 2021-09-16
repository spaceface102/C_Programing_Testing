#include <iostream>

class Test
{
public:
    Test(void)
        : objNumber(++numberOf_ConstructedObjects), justANumber(0)
    {
        std::cout << "DEFAULT Constructing Test Obj#" << (char)objNumber << "\n";
    }

    Test(int aNumber)
        : objNumber(++numberOf_ConstructedObjects), justANumber(aNumber)
    {
        std::cout 
        << "Constructing Test Obj#" << (char)objNumber 
        << " with aNumber = " << justANumber << "\n";
    }

    Test(const Test& that) 
        : objNumber(++numberOf_ConstructedObjects)
    {
        std::cout 
        << "Copy Constructoring Test Obj#" << (char)objNumber 
        << " using Obj#" << (char)that.objNumber << "\n"; 
        this->justANumber = that.justANumber;
    }

    Test(Test&& temp_that) 
        : objNumber(++numberOf_ConstructedObjects)
    {
        std::cout 
        << "MOVE Constructoring Test Obj#" << (char)objNumber 
        << " using temp_Obj#" << (char)temp_that.objNumber << "\n"; 
        this->justANumber = temp_that.justANumber;
    }

    Test& operator=(const Test& that) 
    {
        this->justANumber = that.justANumber;
        std::cout 
        << "Overloaded assignment operator: "
        << "Obj#" << (char)this->objNumber 
        << " = Obj#" << (char)that.objNumber << "\n";

        return *this;
    }

    Test& operator=(Test&& temp_that)
    {
        this->justANumber = temp_that.justANumber;
        std::cout 
        << "Overloaded MOVE assignment operator: "
        << "Obj#" << (char)this->objNumber << " = temp_Obj#" 
        << (char)temp_that.objNumber << "\n";

        return *this;
    }

    Test aSelfReturn(void)
    {
        return *this;
    }

    void doSomething0(const Test& that)
        {*this = internalMethod0(that);}

    Test doSomething0_1(const Test& that)
    {
        *this = internalMethod0(that);
        return *this;
    }

    void doSomething1(const Test& that)
        {*this = internalMethod1(that);}

    Test doSomething1_1(const Test& that)
    {
        *this = internalMethod1(that);
        return *this;
    }

    int getObjNumber(void)
        {return objNumber;}

    int getJustANumber(void)
        {return justANumber;}

private:
    int justANumber;
    const int objNumber;
    static int numberOf_ConstructedObjects;

    Test internalMethod0(const Test& that)
    {
        Test output;
        return output;
    }
    Test internalMethod1(const Test& that)
    {
        Test output;
        output.justANumber = 9999;
        return output;
    }

};
int Test::numberOf_ConstructedObjects = 'a' - 1;

void func0(Test x) {}
void func1(Test& x) {}
void func2(const Test& x) {}
Test makeTest(int number) {const int temp = number; return Test{temp};}

int main(void)
{
    Test a;
    Test b(42);

    //a.aSelfReturn();
    //a.doSomething0(a);
    Test c;
    c = a.doSomething0_1(a);
    //a.doSomething1(a);
    //a.doSomething1_1(a);
//
    //a.doSomething0(b);
    //a.doSomething0_1(b);
    //a.doSomething1(b);
    //a.doSomething1_1(b);
}