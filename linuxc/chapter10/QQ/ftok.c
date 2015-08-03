/*************************************************************************
	> File Name: ftok.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Mon 03 Aug 2015 04:34:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>

int main()
{
    int i;
    for(i=250;i<260;i++)
    {
        printf("key[%d]=%ul\n",i,ftok("/",i));
    }
    printf("----------------------\n");
    for(i=0;i<10;i++)
    {
        printf("key[%d]=%ul\n",i,ftok("/",i));     
    }
}
