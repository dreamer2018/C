/*************************************************************************
	> File Name: processwrite.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Mon 03 Aug 2015 09:15:13 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
    int fd;
    char buf[40]="hello world,this message send by fifo !";
    
    umask(0);

    if(mkfifo( "myfifo" , S_IFIFO| 0666)==-1)
    {
        printf("create new fifo fail!\n");
        exit(1);
    }
    if((fd=open("myfifo",O_WRONLY))==-1)
    {
        printf("open fail !\n");
        exit(1);
    }

    write(fd,buf,strlen(buf)+1);

    close(fd);
    exit(0);
}
