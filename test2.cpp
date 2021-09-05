#include <iostream>

int main(void)
{
/*
    A nice little trick if you want to treat reference
    to array as normal variable, note, this probably
    shouldn't be done, because once the memory allocated
    gets freed we are all fucked, espcieall since you
    can't change what the array references to.  
*/
    int (*arrayPtr)[2][3] = (int (*)[2][3])new int[2][3];
    int (&array)[2][3] = *arrayPtr;
    delete [] arrayPtr;

/*
    here is a shortened version, but you have to remember
    to free the memory using the address of the reference
*/
    int (&array)[2][3] = *((int (*)[2][3])new int[2][3]);
    delete [] &array;

    return 0;
}