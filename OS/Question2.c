#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>
#include <stdlib.h>

/* 允许建立的子进程个数最大值 */
#define MAX_CHILD_NUMBER 10
/* 子进程睡眠时间 */
#define SLEEP_INTERVAL 2

int proc_number=0; /* 子进程的自编号，从0开始 */

void do_something();

int main(int argc, char* argv[])
{
    int child_proc_number = MAX_CHILD_NUMBER; /* 子进程个数 */
    int i, ch;
    pid_t child_pid;
    pid_t pid[10]={0}; /* 存放每个子进程的id */
    if (argc > 1)
    {
        /* 命令行参数中的第一个参数表示建立几个子进程，最多10个 */
        child_proc_number = atoi(argv[1]);
        /*如果命令行中输入的进程数大于10，则给child_proc_number赋值为10*/
        child_proc_number= (child_proc_number > 10) ? 10 : child_proc_number;
    }
    for (i=0; i<child_proc_number; i++)
    {
        /* 在这里填写代码，建立child_proc_number个子进程
        * 子进程要执行
        * proc_number = i;
        * do_something();
        * 父进程把子进程的id保存到pid[i] */

        child_pid = fork();
        if(child_pid == 0)
        {
            proc_number=i;
            do_something();
        }
        else
        {
            pid[i] = child_pid;
        }
    }

    /* 让用户选择杀死哪个进程。输入数字(自编号)表示杀死该进程
    * 输入q退出 */
    while ((ch = getchar()) != 'q')
    {
        for(i=0;i<10;i++)
        {
            printf("%d\t",pid[i]);
        }
        if (isdigit(ch))
        {
            /* 在这里填写代码，向pid[ch-'0']发信号SIGTERM，
            * 杀死该子进程 */
            kill(pid[ch-'0'],SIGTERM);
        }
    }

    /* 在这里填写代码，杀死本组的所有进程 */

    return kill(0,SIGTERM);
}
void do_something()
{
    for(;;)
    {
        /* 打印子进程自编号。为清晰，在每个号码前加“号码+3”个空格
        * 比如号码是1，就打印" 1" */
        printf("This is process No.%*d\n",proc_number+3,proc_number);
        sleep(2); /* 主动阻塞两秒钟 */
    }
}
