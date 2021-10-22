#include <iostream>

int main(void)
{
    {
        int x = 42;
        int* x_ptr = &x;
        int** x_ptr_ptr = &x_ptr;

        std::cout << x << "\n";
        std::cout << x_ptr << "\n";
        std::cout << x_ptr_ptr << "\n\n";

        **x_ptr_ptr = 69;
        std::cout << x << "\n";
        std::cout << x_ptr << "\n";
        std::cout << x_ptr_ptr << "\n\n";

        *x_ptr_ptr = reinterpret_cast<int*>(0xFEEDBEEF);
        std::cout << x << "\n";
        std::cout << x_ptr << "\n";
        std::cout << x_ptr_ptr << "\n\n";
    }

    {        
        int x = 42;
        int y = 43232;
        int* x_ptr = &x;
        int* y_ptr = &y;
        int* random_ptr;
        int* const& x_ptr_ref = x_ptr;
        int* const* gg = &x_ptr_ref;
        //int** zg = &x_ptr_ref; ILLEGAL

        std::cout << *x_ptr << "\n";
        std::cout << x_ptr << "\n";
        std::cout << x_ptr_ref << "\n\n";

        gg = &y_ptr;
        *x_ptr_ref = 99999;
        random_ptr = *gg;
        std::cout << *x_ptr << "\n";
        std::cout << x_ptr << "\n";
        std::cout << x_ptr_ref << "\n\n";

    }
    return 0;
}