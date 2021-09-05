#include <stdlib.h>

int main(int argc, char* argv[])
{
    int x, y;

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    int vla[x][y];
    int (*ptr_to_vla)[x][y];

    ptr_to_vla = &vla;
    return 0;
}