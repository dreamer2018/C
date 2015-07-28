#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#include<sys/stat.h>
void print_prompt() //打印myshell的提示符
{
    printf("my_shell:*_*$");
}
void get_input(char *buf)//获得用户输入的待执行命令，参数buf存放输入的命令，如果命令过长，则报错退出，输入的以换行结束
{
    int i=0;
    while(1)
    {
        buf[i]=getchar();
        if(buf[i]=='\n')
        {
            break;
        }
        else
        {
            i++;
        }
    }
}
void explain_input(char *buf,int *argcount,char arglist[100][256]) //解析buf中的命令，每个选项都存放在arglist中
{
    int i,j,k=0;
    for(i=0;i<256;i++)
    {
        if(buf[i]==' ')
            continue;
        for(j=0;j<256;j++)
        {
            if(buf[i]!=' ')
            {
                arglist[k][j]=buf[i];
            }
            else
            {
                k++;
            }
        }
        break;
    }
}
void do_cmd(int argcount,char arglist[100][256]) //执行arglist命令，argcount为待执行的命令个数
{
}
int find_command(char *command)//在当前目录下，/bin，/usr/bin下查找命令的可执行程序
{
}

void main()
{
    int argcount,i;
    char *buf;
    char arglist[100][256]; // 最多输入100条命令，每条命令不超过255个字符
    buf=(char *)malloc(256*sizeof(char));
/*    while(1)
    {
        memset(buf,0,256);
        print_prompt();
        get_input(buf);
        if(!strcmp("exit\n",buf)||!strcmp("logout\n",buf))
        {
            break;
        }
        for(i=0;i<100;i++)
        {
            arglist[i][0]='\0';
        }
        argcount=0;
        explain_input(buf,&argcount,arglist);
        do_cmd(argcount,arglist);
    }*/
    get_input(buf);
    printf("%s",buf);
}
