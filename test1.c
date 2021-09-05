#include <stdio.h>

void test(int (*array)[3]);

int main(void)
{
    int array[3];
    int array1[42];
    test(&array);
    //test(array1);
    return 0;
}

void test(int (*array)[3])
{
    printf("%ld\n", sizeof(*array));
}
