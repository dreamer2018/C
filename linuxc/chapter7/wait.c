#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
    pid_t pid;
    int exit_code;
    char *msg;
    int k;
    printf("how to get exit code\n");
    pid=fork();
    switch(pid)
    {
        case 0:
            msg="Child process is running";
            k=5;
            exit_code=37;
            break;
        case -1:
            printf("creat a process error");
            exit(1);
        default:
           printf("Parents procee is running");
            exit_code=0;
    }
    if(pid!=0)
    {
        pid_t Child_pid;
        int stat_val;
        Child_pid=wait(&stat_val);
        printf("Child process has exit ,pid=%d\n",Child_pid);
        if(WIFEXITED(stat_val))
        {
            printf("Child exited with code %d\n",WEXITSTATUS(stat_val));

        }
        else
        {
            printf("Child exit abnormally\n");
        }
    }
    else
    {
        while(k-->0)
        {
            puts(msg);
            sleep(1);
        }
    }
    exit(exit_code);
}
