#include <iostream>
#include <cstdint>
int main(void)
{
    int var = 0xFEEDBEEF;
    int numBytes = sizeof(var);

    for (int i = 0; i < numBytes; i++)
        std::cout << std::hex << (int)*((uint8_t*)(&var) + i) << " ";
    return 0;
}