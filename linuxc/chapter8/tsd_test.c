/*************************************************************************
	> File Name: tsd_test.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Thu 30 Jul 2015 05:29:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_key_t key;

void *thread( void * arg )
{
    int tsd = 5 ;
    pthread_setspecific( key ,(void *)&tsd );
    printf("%lu\n",pthread_getspecific(key));
}
int main()
{
    int tsd=2;
    pthread_t thid;
    pthread_key_create( &key ,NULL);
    pthread_create(&thid,NULL,thread,NULL);
    sleep(3);
    pthread_setspecific(key, (void *)&tsd);
    printf("%lu\n",pthread_getspecific(key));
    pthread_key_delete(key);
}
