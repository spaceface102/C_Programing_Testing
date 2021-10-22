#include <iostream>

class Test
{
public:
    //Test(void) {std::cout << "Doing something\n";}
    Test(void) = delete;
    explicit Test(int) {std::cout << "Hello!\n";}
};

class Runner
{
public:
    //Runner(void) = default;
    Runner(void) : x{0} {};
    //Runner(void) {x = Test{0};}

    Runner& operator=(const Runner&) = delete;
private:
    Test x;
};

struct Data
{
    int x[42] = {0};
    const char* str;
};

std::ostream& operator<<(std::ostream& out, const Data& obj)
{
    for (int a : obj.x)
        out << a << ", ";

    return out;
}

int main(void)
{
    //Test d[32]; won't work because a lack of a default constructor
    Runner g;
    Runner y;

    //g = y; deleted assignment operator
    Runner z = Runner{}; //this is fine because using constructor

    {
        int a[40];
        int (*a_ptr)[40];
        int b[40];
        int (*b_ptr)[40];

        a_ptr = &a;
        b_ptr = &b;

        a_ptr = b_ptr;
    }

    {
        Data y;
        Data z;

        std::cout << y << "\n\n";
        std::cout << z << "\n\n";
        y = z;
        std::cout << y << "\n\n";
        std::cout << z << "\n\n";
    }
    return 0;
}