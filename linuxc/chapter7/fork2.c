#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    char *msg;
    int k;
    printf("Create New Process!\n");
    pid=fork();
    switch(pid)
    {
        case 0:
            msg="Child process is runing";
            k=3;
            break;
        case -1:
            printf("create process error");
            break;
        default:
            msg="Parent process is runing";
            k=5;
            break;
    }
    while(k>0)
    {
        puts(msg);
        sleep(1);
        k--;
    }

}
