#include <iostream>

int main(void)
{
    int* ptr;
    const int* const& ref_ptr = ptr;
    const int* const_ptr = ptr;
    //ref_ptr = 3;
    return 0;
}