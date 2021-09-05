#include <iostream>


class base //final "adding final means that this class can NOT be inherted from"
{
public:
    base(void)
    {
        std::cout << "Constructing base\n";
    }
    virtual ~base(void) //alows to call derived class destructor through base ptr
    {
        std::cout << "Deleting base\n";
    }

    void talk(void)
    {
        std::cout << "Hello from base!\n";
    }
};

class cool final : public base
{
public:
    cool(void)
    {
        std::cout << "Constructing cool\n";
    }
    ~cool(void)
    {
        std::cout << "Deleting cool\n";
    }
};

//example of trying to inheret from a "final" class
class stupid : public cool
{

};

int main(void)
{
    return 0;
}