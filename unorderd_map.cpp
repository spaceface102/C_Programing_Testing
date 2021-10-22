#include <unordered_map>
#include <string>
int main(void)
{
    std::unordered_map<std::string, int> x;
    x.operator[]("I love you") = 42;

    std::unordered_map<std::string, std::unordered_map<std::string, int>> a;
    return 0;
}