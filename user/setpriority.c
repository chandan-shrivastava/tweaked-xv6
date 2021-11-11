#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        printf("Error: Invalid number of arguments.\n");
        exit(1);
    }
    int newp = 0, pid = 0;
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        newp *= 10;
        newp += (argv[1][i] - '0');
    }
    for (int i = 0; i < strlen(argv[2]); i++)
    {
        pid *= 10;
        pid += (argv[2][i] - '0');
    }
    if (newp < 0 || newp > 100)
    {
        printf("Error: Invalid value of priority.\n");
        exit(1);
    }
    int oldp = setpriority(newp, pid);
    if (oldp == -1)
    {
        printf("Error: no process exists with given PID.\n");
        exit(1);
    }
    else
    {
        printf("Process with PID: %d updated from priority %d to %d.\n", pid, oldp, newp);
        exit(0);
    }
}