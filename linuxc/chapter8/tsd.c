/*************************************************************************
	> File Name: tsd.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Thu 30 Jul 2015 04:17:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

pthread_key_t key;

void *thread2(void *arg)
{
   // int tsd=5;
   // printf("thread %u is running \n",pthread_self());
   // pthread_setspecific( key,(void *)tsd);
    printf("thread %u return %u \n",pthread_self(),pthread_getspecific( key));
}
void * thread1(void *arg)
{
    int tsd =0;
    pthread_t thid2;

    printf("thread %u is running \n",pthread_self);
    pthread_setspecific(key,(void *)tsd);
    pthread_create(&thid2 ,NULL ,thread2,NULL);
    sleep(5);
    printf("thread %u return %u \n",pthread_self(),pthread_getspecific(key));
}
int main()
{
    pthread_t thid1;
    printf("main thread begins running\n");
    pthread_key_create(&key ,NULL);
    pthread_create(&thid1,NULL,thread1,NULL);
    sleep(6);
    pthread_key_delete(key);
    printf("main thread exit\n");
    return 0;
}

