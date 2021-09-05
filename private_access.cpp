#include <iostream>

class private_first
{
private:
    int hello;
    int x;
    int y,z;
public:
    private_first(void) = delete;

    private_first(int a, int b, int c, int d)
        : hello(a), x(b), y(c), z(d)
    {}
    //EOF

    void sayHello(void)
    {
        std::cout << "Hello!\n";
    }
    //EOF
};

class private_last
{
public:
    private_last(void) = delete;

    private_last(int a, double b, int c, int d)
        : hello(a), x(b), y(c), z(d)
    {}
    //EOF

    void sayHello(void)
    {
        std::cout << "Hello!\n";
    }
    //EOF

private:
    int hello;
    double x;
    int y, z;
};

struct getThatData
{
    int a, b, c, d;
};

int main(void)
{
    private_first test(4, 42, 43, 10000);
    private_last test1(5, 3, 33333, 122e7);

    std::cout << ((getThatData *)(&test))->a << "\n";
    std::cout << ((getThatData *)(&test))->b << "\n";
    std::cout << ((getThatData *)(&test))->c << "\n";
    std::cout << ((getThatData *)(&test))->d << "\n";

    std::cout << "\n";

    void* ptr = (void *)(&test1);

    std::cout << *(int *)(ptr + 0) << "\n";
    //compiler is adding some padding between the
    //the first int hello, and second double x
    //in order to make sure it can beneift from
    //data alignment
    std::cout << *(double *)(ptr + 8) << "\n";
    std::cout << *(int *)(ptr + 16) << "\n";
    std::cout << *(int *)(ptr + 20) << "\n";

}