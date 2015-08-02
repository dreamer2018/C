/*************************************************************************
	> File Name: pipe_test.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
    > Created Time: Sun 02 Aug 2015 02:24:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

void write_pipe(int fd)
{
    char *message="hello pipe test\n";
    if(write(fd,message,strlen(message)+1))
        printf("write success\n");
}
void read_pipe(int fd)
{
    char *message;
    message=(char *)malloc(100*sizeof(char));
    if(read(fd,message,100))
    {
        printf("get pipe:%s\n",message);
    }
    else
    {
        printf("get message fail\n");
    }
    free(message);
}
int main()
{
    int fd[2];
    pid_t pid;
    if(pipe(fd))
    {
        printf("make a pipe fail\n");
        return 0;
    }
    pid=fork();
    switch(pid)
    {
        case 0:
            write_pipe(fd[1]);
            exit(0);
        case -1:
            printf("fork a new process fial");
            exit(0);
        default:
            read_pipe(fd[0]);
            exit(0);
    }
    return 1;
}

