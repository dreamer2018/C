/*************************************************************************
	> File Name: orphan.c
	> Author: ZhouPan
	> GitHub: dreamer2018
	> Blog: http://blog.csdn.net/it_dream_er
	> Mail: zhoupan@xiyoulinux.org
	> About: 孤儿进程测试
	> Created Time: 2017年05月03日 星期三 09时19分56秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        //this is parent
        printf("%d",getpid());
        printf("parent exit!");
    }
    else if(pid == 0)
    {
        // this is child
        int i;
        for(i=0;i<5;i++)
        {
            printf("%d\n",i);
            sleep(1);
        }
        printf("parent id %d\n",getppid());
        printf("child exit!");
    }
    else
    {
        printf("fork error!");
        // this is error
    }
}
