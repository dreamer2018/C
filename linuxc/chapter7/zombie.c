/*************************************************************************
	> File Name: zombie.c
	> Author: ZhouPan
	> GitHub: dreamer2018
	> Blog: http://blog.csdn.net/it_dream_er
	> Mail: zhoupan@xiyoulinux.org
	> About: 僵尸进程
	> Created Time: 2017年05月03日 星期三 09时33分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        //this is parent
        printf("%d",getpid());
        sleep(10);
        wait(0);
        printf("parent exit!");
    }
    else if(pid == 0)
    {
        // this is child
        sleep(4);
        printf("child exit!");
    }
    else
    {
        printf("fork error!");
        // this is error
    }
}
