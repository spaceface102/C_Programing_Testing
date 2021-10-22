#include <vector>

template<typename E>
class Test : public std::vector<E>
{
};

int main(void)
{
    Test<int> x;

    x.push_back(1);
    return 0;
}