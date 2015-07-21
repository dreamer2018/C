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
            while(1)
            {
                printf("A Background Process PID=%d ParentPID=%d\n",getpid(),getppid());
                sleep(3);
            }
        case -1:
            printf("create process error");
            exit(-1);
        default:
            printf("I am Parent Process myid=%d\n",getpid());
            exit(0);
    }
    return 0;
}
