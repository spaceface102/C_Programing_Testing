#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>

template<typename Ttype, std::size_t Tsize>
std::ostream& operator<<(std::ostream& out, const std::array<Ttype, Tsize>& array)
{
    for (const auto& element : array)
        out << element << ", ";
    return out;
}

int main(void)
{
    {
        std::array<int, 2> x{0x41424344, 0x45464748};
        std::array<char, 8> z;

        std::copy(x.begin(), x.end(), z.begin());

        std::cout << x << "\n";
        std::cout << z << "\n";
    }

    {
        std::array<int, 2> x{0x41424344, 0x45464748};
        std::array<char, 8> z;

        memcpy(z.begin(), x.begin(), x.size()*sizeof(int));

        std::cout << x << "\n";
        std::cout << z << "\n";        
    }
    return 0;
}