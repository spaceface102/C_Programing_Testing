#include <unistd.h>
#include <stdio.h>

char* const execName = "hello.py";
int main(int argc, char* argv[])
{
    char* const execv_argv[3] = {execName, "1234", NULL};
    execv(execName, execv_argv);
    return 0;
}
