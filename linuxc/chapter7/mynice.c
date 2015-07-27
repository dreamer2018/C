#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    pid_t pid;
    int stat_val=0;
    int oldpri,newpri;
    printf("nice study:");
    pid=fork();
    switch(pid)
    {
        case 0:
            printf("Child is running ,Curpid=%d,Parentpid=%d\n",pid,getppid());
            oldpri=getpriority(PRIO_PROCESS,0);
            printf("Old priority=%d\n",oldpri);
            newpri=nice(2);
            printf("new priority=%d\n",newpri);
            exit(0);
        case -1:
            printf("Create new process error");
            break;
        default:
            printf("Parent is running ,Childpid=%d,Parentpid=%d\n",pid,getpid());
            break;
    }
    wait(&stat_val);
    exit(0);
}
