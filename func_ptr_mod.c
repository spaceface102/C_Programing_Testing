#include <stdio.h>

typedef void (*func_ptr)(double);

void yes(double d)
    {printf("Called function yes!\n");}
void no(double d)
    {printf("Called function no!\n");}

void test(func_ptr h)
{
    h = yes;
}

int main(void)
{
    func_ptr g = no;
    g(4.5);
    test(g);
    g(4.2);
    return 0;
}