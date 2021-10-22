#include <iostream>

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int& ref = array[1];

    std::cout << ref << "\n";
    array[1] = 99;
    std::cout << ref << "\n";

    return 0;
}