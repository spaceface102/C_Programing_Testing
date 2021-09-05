#include "somebs.h"

void test(int (*arrayPtr)[]);

int main(void)
{
    int array[5];
    int array2D[5][5];

    test(&array);
    test(array2D);  //this works because int (*)[] is just basically a 2D array....
                    //but probably more accurately, a double pointer
}

void test(int (*arrayPtr)[])
{}
