#include <list>
#include <iostream>

template<typename E>
std::ostream& operator<<(std::ostream& out, const std::list<E>& list)
{
    for (const auto& elem : list)
        std::cout << elem << ", ";
    return out;
}

int main(void)
{
    std::list<int> x(12, 32);
    std::list<int> y;
    std::list<int> z;

    auto printAllThree = [&](void) -> void 
    {    
        std::cout << "x (size = " << x.size() << "): "  << x << "\n";
        std::cout << "y (size = " << y.size() << "): "  << y << "\n";
        std::cout << "z (size = " << z.size() << "): "  << z << "\n\n";
    };

    printAllThree();
    y = std::move(x);
    printAllThree();
    z = std::move(x);
    printAllThree();
    z = std::move(y);
    printAllThree();




    //this is just a side quest
    std::ostream& (*hmm)(std::ostream&, const std::list<int>&) = operator<<<int>;
    return 0;
}