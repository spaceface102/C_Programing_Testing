#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int (*array)[3][2] = (int (*)[3][2])malloc(sizeof(*array));

    for (int i = 0; i < 3; i++)
        for (int k = 0; k < 2; k++)
            (*array)[i][k] = (i*3) + k;

    int test[4][2];
    return 0;
}
