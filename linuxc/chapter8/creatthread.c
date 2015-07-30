#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int *thread(void *arg)
{
    pthread_t newthid;
    newthid=pthread_self();
    printf("This thread id is %u\n",newthid);
    return NULL;
}
int main(void)
{
    pthread_t thid;

    printf("this thread id is %u\n",pthread_self());
    if(pthread_create(&thid,NULL,(void *)thread,NULL)!=0)
    {
        printf("thread creat fail !\n");
        exit(1);
    }
    sleep(1);
    exit(0);
}
