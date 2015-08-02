/*************************************************************************
	> File Name: monitor.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Sun 02 Aug 2015 09:43:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<wait.h>
#include<string.h>

int main(int arg,char *argv[],char **environ)
{
    int fd[2];
    pid_t pid;
    int stat_val;

    if(arg<2)
    {
        printf("wrong parameters \n");
        exit(0);
    }
    if(pipe(fd))
    {
        perror("pipe failed\n");
        exit(0);
    }
    pid=fork();
    switch(pid)
    {
        case -1:
            perror("fork failed!\n");
            exit(0);
        case 0:
            close(0);
            dup(fd[0]);
            execve("ctrlpocess",(void *)argv,environ);
            exit(0);
        default:
            close(fd[0]);
            write(fd[1],argv[1],strlen(argv[1]));
            break;
    }
    wait(&stat_val);
    exit(0);
}
