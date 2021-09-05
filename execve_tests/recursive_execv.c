#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char* const runthis_program = "a.out";
int main(int argc, char* argv[])
{
    //careful having a heap allocated string since
    //all the calling process gets replaced with the called
    //process, and therefore also the stack, uninit memory, and
    //the heap are all "reset". Be very careful

    char* exec_argv[3];

    int passedInt = (argc > 1) ? atoi(argv[1]) : 1;
    char intTostr[101];

    if (passedInt > 1e2)
    {
        printf("Fuh, I am outta here ong\n");
        return 0;
    }

    printf("%d\n", passedInt);
    snprintf(intTostr, 100, "%d", passedInt + 1);

    exec_argv[0] = runthis_program;
    exec_argv[1] = (char *)intTostr;
    exec_argv[2] = NULL; //final argv param must be NULL, according to execve

    execv(runthis_program, exec_argv);
    
    return 0;
}