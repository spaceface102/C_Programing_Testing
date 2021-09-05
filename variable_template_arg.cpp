template<int size>
class dumb
{
    int array[size];
};

int main(void)
{
    const int x = 5;
    dumb<x> hello;
    return 0;
}