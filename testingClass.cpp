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

    ~Test(void)
    {
        std::cout << "Killing Obj#" << (char)objNumber << "\n";
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
void func3(Test&& x) {std::cout << "Inside func3\n";}
//Test&& func4(void) {std::cout << "Inside func4\n"; return Test{};} BAD!
Test&& func5(void) {static Test x{42}; std::cout << "Inside func5\n"; return std::move(x);}
Test makeTest(int number) {const int temp = number; return Test{temp};}

int main(void)
{
    //Test a;
    //Test b(42);

    //a.aSelfReturn();
    //a.doSomething0(a);
    //Test c;
    //c = a.doSomething0_1(a);
    //a.doSomething1(a);
    //a.doSomething1_1(a);

    //a.doSomething0(b);
    //a.doSomething0_1(b);
    //a.doSomething1(b);
    //a.doSomething1_1(b);

    //Test a;
    //Test& b = a;
    //Test&& c = std::move(b);
    //Test&& d = std::move(a);
    
    //Test&& a = Test{1};
    //a.aSelfReturn();

    //Test a;
    //Test&& b = Test{};
    //a = b;

    //Test a;
    //Test&& b = std::move(a);
    //a = b;

    //Test a;
    //func3(Test{});
    //func3(std::move(a));

    //func4();
    //std::cout << "Hello!\n";

    //Test a;
    //Test b;
    //a = func5();
    //b = func5();

    //Test a = makeTest(43);
    //std::cout << "spacer\n";
    //Test b = func5();
}