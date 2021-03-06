/*************************************************************************
	> File Name: doub_pipe.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Sun 02 Aug 2015 03:02:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<wait.h>


void pipe_rw_1(int fd1,int fd2)
{
    char *message_w="this is duoble pipe_1 for write\n";
    char message_r[100];

    read(fd1,message_r,100);
    write(fd2,message_w,strlen(message_w)+1);
    
   // read(fd1,message_r,100);
    printf(" 1:get message is %s\n",message_r);
}
void pipe_rw_2(int fd1,int fd2)
{
    char *message_w="this is duoble pipe_2 for write\n";
    char message_r[100];
    
    write(fd2,message_w,strlen(message_w)+1);
    
    read(fd1,message_r,100);
    printf(" 2:get message is %s\n",message_r);
}
int main()
{
    int fd1[2],fd2[2];
    int stat_val;
    pid_t pid;
    
    printf("this doub pipe test\n");
    if(pipe(fd1))
    {
        printf("pipe 1 create fail\n");
        return 0;
    }
    if(pipe(fd2))
    {
        printf("pipe 2 create fail\n");
        return 0;
    }
    pid=fork();
    switch(pid)
    {
        case -1:
            printf("create new process fail\n");
            exit(1);
        case 0:
            close(fd1[0]);
            close(fd2[1]);
            pipe_rw_1(fd2[0],fd1[1]);
            exit(0);
        default:
            close(fd1[1]);
            close(fd2[0]);
            pipe_rw_2(fd1[0],fd2[1]);
            wait(&stat_val);
            exit(0);
    }
}
