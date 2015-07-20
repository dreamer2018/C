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
                printf("I am Child Process myid=%d myParentid=%d\n",getpid(),getppid());
                break;
                sleep(3);
            }
        case -1:
            printf("create process error");
            break;
            exit(-1);
        default:
            printf("I am Parent Process myid=%d\n",getpid());
            break;
            exit(0);
    }
    exit(0);
}
