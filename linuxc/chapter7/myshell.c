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
    printf("my_shell:*_* $");
}
void get_input(char *buf)//获得用户输入的待执行命令，参数buf存放输入的命令，如果命令过长，则报错退出，输入的以换行结束
{

}
void explain_input(char *buf,int *argcount,char *arglist[][]) //解析buf中的命令，每个选项都存放在arglist中
{
}
void do_cmd(int argcount,char arglist[][]) //执行arglist命令，argcount为待执行的命令个数
{
}
int find_command(char *command)//在当前目录下，/bin，/usr/bin下查找命令的可执行程序
{
}
void main()
{

}
