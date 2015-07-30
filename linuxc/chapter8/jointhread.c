/*************************************************************************
	> File Name: jointhread.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Thu 30 Jul 2015 01:49:06 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void assisthread(void *arg)
{
    printf("this is test join thread!,threadid:%u\n",pthread_self());
    sleep(3);
    pthread_exit((void *)1);
}
void main()
{
    int status;
    pthread_t thread;
    pthread_create(&thread,NULL,(void *)assisthread,NULL);
    pthread_join(thread,(void*)&status);
    printf("%u %d\n",thread,status);
}

