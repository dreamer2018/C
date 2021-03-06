/*************************************************************************
    > File Name: client.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Mon 03 Aug 2015 02:01:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

#define BUF_SIZE 1024
#define FIFO_READ "writefifo"
#define FIFO_WRITE "readfifo"

int main()
{
    int rfd,wfd;
    char buf[BUF_SIZE];
    int len;
    errno=0;

    umask(0);
    if( mkfifo( FIFO_WRITE, S_IFIFO|0666 ) )
    {
        printf("creat fifo %s fail,because:%s ",FIFO_WRITE, strerror(errno));
        exit(1);
    }

    while((rfd=open(FIFO_READ,O_RDONLY))==-1)
    {
        sleep(1);
    }

    wfd=open(FIFO_WRITE, O_WRONLY);
    if(wfd==-1)
    {
        printf("Fail to open %s ,because: %s",FIFO_WRITE,strerror(errno));
        exit(-1);
    }

    while(1)
    {
        len=read(rfd,buf,BUF_SIZE);
        if(len>0)
        {
            buf[len]='\0';
            printf("Service:%s\n",buf);
        }
        
        printf("Client :");
        fgets(buf,BUF_SIZE,stdin);
        buf[strlen(buf)-1]='\0';
        if(strncmp(buf,"quit",4)==0)
        {
            close(wfd);
            unlink(FIFO_WRITE);
            close(rfd);
            exit(0);
        }
        write(wfd,buf,strlen(buf));
    }
}
