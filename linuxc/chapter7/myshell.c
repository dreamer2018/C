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
int explain_input(char *buf,char arglist[][256]) //解析buf中的命令，每个选项都存放在arglist中
{
    int i,j,k=0,n=-1;
    for(i=0;buf[i]!='\n';i++)
    {
        if(buf[i]==' ')
            continue;
        for(j=i;buf[j]!='\n';j++)
        {
            n++;
            if(buf[j]!=' ')
            {
                arglist[k][n]=buf[j];
            }
            else
            {
                n++;
                arglist[k][n]='\0';
                n=-1;
                k++;
            }
        }
        break;
    }
    k++;
    return k;
}
void do_cmd(int argcount,char arglist[100][256]) //执行arglist命令，argcount为待执行的命令个数
{

}
int find_command(char *command)//在当前目录下，/bin，/usr/bin下查找命令的可执行程序
{
    //文件目录解析函数，获取当前目录所有文件
    int i=0,j,count=0;
    DIR *dir;
    struct dirent *ptr;
    char path[][9]={"./","/bin","/usr/bin"};
    while(path[i]!=NULL);
    {
        if((dir=opendir(path[i]))==NULL)
        {
            perror("opendir");
            return -1;
        }
        while((ptr=readdir(dir))!=NULL)
        {
            if(!strcmp(ptr->d_name,command))
            {
                return 1;
            }
        }
        closedir(dir);
        i++;
    }
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
    argcount=explain_input(buf,arglist);
    for(i=0;i<argcount;i++)
    {
        printf("%s\n",arglist[i]);
    }
}
