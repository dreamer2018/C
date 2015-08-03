/*************************************************************************
	> File Name: service.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Mon 03 Aug 2015 11:13:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

#define BUF_SIZE 1024
#define FIFO_WRITE "writefifo"
#define FIFO_READ "readfifo"

int main()
{
    int errno=0;
    int wfd,rfd;
    char buf[BUF_SIZE];
    int len;

    umask(0);
    if(mkfifo(FIFO_WRITE,S_IFIFO|0666)) //创建一个有名管道
    {
        printf("Create %s fail because:%s",FIFO_WRITE,strerror(errno));
        exit(0);
    }
    
    umask(0);
    if((wfd=open(FIFO_WRITE,O_WRONLY))==-1)     //打开管道写端
    {
        printf("Open %s errno,because :%s",FIFO_WRITE,strerror(errno));
        exit(0);
    }

    while((rfd=open(FIFO_READ,O_RDONLY))==-1)  //打开管道读端
    {
        sleep(1);   //如果打开失败，沉睡一秒，重新读取
    }

    while(1)
    {
        printf("Service:");
        fgets(buf,BUF_SIZE,stdin);  //获取用户的输入
        buf[(strlen(buf)-1)]='\0'; //字符串要以‘\0‘结尾
        
        if(!strcmp(buf,"quit"))     //若字符串为quit，则退出
        {
            close(wfd);
            unlink(FIFO_WRITE);     //断开连接
            close(rfd);
            exit(0);
        }
        
        write(wfd,buf,strlen(buf)+1); //向通道中写入东西
        
        len=read(rfd,buf,BUF_SIZE);  //从通道中获取信息
        if(len>0)
        {
            buf[len]='\0';
            printf( "Client :%s\n",buf );
        }
    }
}
