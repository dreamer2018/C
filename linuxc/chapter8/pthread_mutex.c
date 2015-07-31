/*************************************************************************
	> File Name: pthread_mutex.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Fri 31 Jul 2015 08:29:51 AM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;;
int temp=0;

void write_mutex();
void read_mutex();

int main()
{
    pthread_t thread;
    pthread_create( &thread, NULL, (void *)write_mutex,NULL);
   // pthread_mutex_t mutex;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER ;
   // pthread_mutex_init(&mutex,NULL);
   // write_mutex();
    sleep(1);
    read_mutex();
}
void write_mutex()
{
    pthread_mutex_lock( &mutex ) ;
    temp++;
    printf( "temp_W=%d",temp );
    pthread_mutex_unlock( &mutex ) ;
}
void read_mutex()
{
    pthread_mutex_lock( &mutex  );
    temp=4;
    printf( "temp_R=%d",temp );
    pthread_mutex_unlock( &mutex  );
}
