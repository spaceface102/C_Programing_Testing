#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc <= 1)
        return -1;
    
    size_t n = strtol(argv[1], NULL, 10);
    int x[n][n];

    //since x is VLA (variable length array) please
    //do note that typeof is indeed dynamic.
    typeof(x) B; //this is a compiler extension
    printf("%lu\n", sizeof(typeof(x)));

    //honestly though, I don't think that it is worth
    //the trouble for must programs, as compilation
    //at least in my experience, gets a little weird
    return 0;
}