/*************************************************************************
	> File Name: condition.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Fri 31 Jul 2015 10:04:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void *thread1(void *arg)
{
    pthread_cleanup_push((void *)pthread_mutex_lock,&mutex);

    while(1)
    {
        printf("thread1 is running \n");
        pthread_mutex_lock(&mutex);
        printf("thread1 applied the condition \n");
        pthread_mutex_unlock(&mutex);
        sleep(4);
    }

    pthread_cleanup_pop(0);
}
void thread2(void *arg)
{
    while(1)
    {
        printf("thread2 is running \n");
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond,&mutex);
        printf("thread2 applied the condition \n");
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main(void)
{
    pthread_t tid1,tid2;

    printf("condition variable study! \n");
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_create(&tid1,NULL,(void *)thread1,NULL);
    pthread_create(&tid2,NULL,(void *)thread2,NULL);

    do
    {
        pthread_cond_signal(&cond);
    }while(1);
    sleep(50);
    pthread_exit(0);
}

