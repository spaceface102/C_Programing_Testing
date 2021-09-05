#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char* envp[])
{
    printf("%s\n", getenv("PWD"));

    for (int i = 0; envp[i] != NULL; i++)
        printf("%s\n", envp[i]);
}