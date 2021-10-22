#include <cstdlib>
#include <cstdint>
#include <vector>

struct Generalize
{
public:
    Generalize(const void* passed_in_data, std::size_t size)
    {
        data = new std::uint8_t[size];
        for (std::size_t i = 0; i < size; i++)
            data[i] = static_cast<const std::uint8_t*>(passed_in_data)[i];
    }

    ~Generalize(void)
    {
        delete [] data;
    }


//data
    std::uint8_t* data;
};

class Interface
{
public:
    virtual operator Generalize(void) const = 0;
};

class Test : public Interface
{
public:
    operator Generalize(void) const override
    {
        return Generalize(this, sizeof(Test));
    }
};


//MAYBE USE A FUCKING UNION!!!!!!!!
//OR std::variant
int main(void)
{
    Test x;
    Generalize y = Generalize(x);
    return 0;
}