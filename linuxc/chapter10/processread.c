/*************************************************************************
	> File Name: processread.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Mon 03 Aug 2015 09:06:45 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

int main()
{
    char buf[1024];
    int fd;
    
    umask(0);
    fd=open("myfifo",O_RDONLY);
    read(fd,buf,1024);
    printf("read :%s\n",buf);
    close(fd);
    exit(0);
}
