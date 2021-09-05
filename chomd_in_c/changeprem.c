#include <stdio.h>
#include <sys/stat.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[])
{
    //S_ISVTX is not avaliable for whatever reason
    char basemodeName[] = "S_IXXXX";
    const char* modeNames[] = 
    {
        "S_ISUID", "S_ISGID", //S_ISVTX
        "S_IRUSR", "S_IWUSR", "S_IXUSR", 
        "S_IRGRP", "S_IWGRP", "S_IXGRP",
        "S_IROTH", "S_IWOTH", "S_IXOTH"
    };

    unsigned int mode[] = 
    {
        S_ISUID, S_ISGID, //S_ISVTX
        S_IRUSR, S_IWUSR, S_IXUSR, 
        S_IRGRP, S_IWGRP, S_IXGRP,
        S_IROTH, S_IWOTH, S_IXOTH
    };

    FILE* currentFile;
    char basefname[] = "permssion_file_";
    uint64_t numModes = sizeof(mode)/sizeof(unsigned int);
    char fname[sizeof(basefname) + sizeof(basemodeName) - 1]; //only one null terminating char needed

    strncpy(fname, basefname, sizeof(basefname));
    for (uint64_t i = 0; i < numModes; i++)
    {
        //start copying over the null termianting char in basefname
        strncpy(fname + sizeof(basefname) - 1, modeNames[i], sizeof(basemodeName));
        currentFile = fopen(fname, "w");
        fclose(currentFile);
        chmod(fname, mode[i]);
    }

    return 0;
}