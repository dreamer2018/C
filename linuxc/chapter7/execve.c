#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
void main(int argc,char *argv[],char **environ)
{
    pid_t pid;
    int stat_val;
    printf("exec example :\n");
    pid=fork();
    switch(pid)
    {
        case -1:
            printf("creat new process error\n");
            exit(1);
        case 0:
            printf("child process is runing!\n");
            printf("my pid=%d,pirentid=%d\n",getpid(),getppid());
            printf("uid=%d,gid=%d\n",getuid(),getgid());
            execve("processimage",argv,environ);
            printf("process never to here!\n");
            exit(0);
        default:
            printf("parent process is runing\n");
            break;
    }
   // wait(&stat_val);
    printf("%d\n",wait(&stat_val));
    exit(0);
}
