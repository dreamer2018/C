/*************************************************************************
	> File Name: test_select.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Wed 05 Aug 2015 08:34:04 AM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

void display_time(char *string)
{
    int seconds;
    seconds=time((time_t *)NULL);
    printf("%s,%d\n",string,seconds);
}

int main()
{
    fd_set readfds;
    struct timeval timeout;
    int ret;

    FD_ZERO(&readfds);
    FD_SET(0,&readfds);

    timeout.tv_sec=10;
    timeout.tv_usec=0;

    while(1)
    {
        display_time("before select");
        ret=select(1,&readfds,NULL,NULL,&timeout);
        display_time("after select");
        
        switch(ret)
        {
            case 0:
                printf("No date in ten seconds\n");
                exit(0);
                break;
            case -1:
                perror("select");
                exit(0);
            default:
                getchar();
                printf("Date is available now.\n");
        }
    }
}
