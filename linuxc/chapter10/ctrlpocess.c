/*************************************************************************
	> File Name: ctrlpocess.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Sun 02 Aug 2015 09:23:13 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


int main(int arg,char *argv[])
{
    int n;
    char buf[1024];

    while(1)
    {
        if((n=read(0,buf,1024))>0)
        {
            buf[n]='\0';
            printf("ctrlpocess receive :%s\n",buf);
            
            if(!strcmp(buf,"exit"))
            {
                exit(0);
            }
            if( !strcmp(buf,"getpid" ))
            {
                printf("my pid=%d\n",getpid());
                sleep(3);
                exit(0);
            }
        }
    }
}

