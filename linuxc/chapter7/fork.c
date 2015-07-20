#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    printf("Create New Process!\n");
    pid=fork();
    switch(pid)
    {
        case 0:
            printf("CurPid id=%d Parent id=%d\n",pid,getppid());
            break;
        case -1:
            printf("create process error");
            break;
        default:
            printf("child id=%d Parent id=%d\n",pid,getpid());
            break;
    }
    exit(0);
}
