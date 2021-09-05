#include <stdio.h>

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%ld\n", sizeof(int[2][3]));
    //the size of operator works on VLAs!
    printf("%ld\n", sizeof(int[x][y]));

    int z[x][y];
    printf("%ld\n", sizeof(z));
    printf("%ld\n", sizeof(z[0]));
    printf("%ld\n", sizeof(z[0][0]));
}