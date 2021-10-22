#include <iostream>

class Test
{
public:
    ~Test(void)
        {std::cout << "Bye Bye!\n";}
    //static method by default
    void operator delete(void* addr)
    {
        std::cout << "I ain't going to do shit but fuck it\n";
        if (addr != nullptr)
            std::cout << "Oopsie, memory leak :(\n";
        //delete (Test*)addr; ahaha recursive call
        std::free(addr); 
        //this is problematic though, using free on memory that
        //was allocated with new might result in undefined behavior
        //and the destructor might not be called :( (well at least
        //according to stack overflow)
    }
};

int main(void)
{
    Test x;
    Test* y = new Test();

    x.operator delete(NULL);
    Test::operator delete(NULL);
    delete y;
    return 0;
}