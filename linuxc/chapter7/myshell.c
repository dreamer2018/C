#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>

//函数声明部分

int find_command(char *command);
void do_cmd(int argcount,char arglist[100][256]);
int explain_input(char *buf,char arglist[][256]);
void get_input(char *buf);
void print_prompt();

void print_prompt() //打印myshell的提示符
{
    printf("my_shell:*_*$");  //打印shell的命令提示
}
void get_input(char *buf)/*获得用户输入的待执行命令，参数buf存放输入的命令，如果命令过长，则报错退出，输入的以换行结束*/
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
/*
int explain_input(char *buf,char arglist[][256]) //解析buf中的命令，每个选项都存放在arglist中
{
    int i,j,k=0,n=-1;
    for(i=0;buf[i]!='\n';i++)   //外层循环用于排除前面的空格对命令的影响
    {
        if(buf[i]==' ')
            continue;
        for(j=i;buf[j]!='\n';j++)   //内层循环用于解析出命令及其命令后面的附加参数
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
                n=-1;11
                k++;
            }
        }
        break;
    }
    k++;
    return k;
}*/

int explain_input(char *buf,char arglist[][256]) //解析buf中的命令，每个选项都存放在arglist中
{
    int i=0,j=0,k=0;
    while(buf[i]!='\n')
    {
        if(buf[i]==' ')
        {
            i++;
            continue;
        }
        j=0;
        while(buf[i]!=' ' && buf[i]!='\n')
        {
            arglist[k][j]=buf[i];
            i++;
            j++;
        }
        k++;
    }
    return k;
}
void do_cmd(int argcount,char arglist[100][256]) //执行arglist命令，argcount为待执行的命令个数
{
    int flag=0;
    int i;
    int how=0;
    int background=0;     //后台运行标识
    char *arg[argcount+1]; //程序运行参数保存
    char *argnext[argcount+1]; //管道的第二个程序运行参数保存
    char *file;     //输出，输入重定向文件名保存
    int fd,fd2;
    pid_t pid;
    int status;
    for(i=0;i<argcount;i++)
    {
       arg[i]=arglist[i];
    }
    arg[argcount]=NULL;
    for(i=0;i<argcount;i++)
    {
        if(strncmp(arg[i],"&",1)==0)
        {
            if(i==argcount-1)
            {
                background=1;
                arg[argcount-1]=NULL; // 命令参数要以空结束
                break;
            }
            else
            {
                printf("Command Error\n");
                return ;
            }
        }
    }
    for(i=0;arg[i]!=NULL;i++)
    {
        if(!strcmp(arg[i],">"))    //输出重定向符判断
        {
            flag++;
            how=1;
            if(arg[i+1]==NULL||i==0)
            {
                flag++;
            }
        }
        if(!strcmp(arg[i],">>"))  /*输出重定向符判断，于>区别在前者是以追加方式写入，后者只是写入，文件存在会将其内容清空*/
        {
            flag++;
            how=4;
            if(arg[i+1]==NULL || i==0)
            {
                flag++;
            }
        }
        if(!strcmp(arg[i],"<"))
        {
            flag++;
            how=2;
            if(i==0 ||arg[i+1]==NULL)
                flag++;
        }
        if(strcmp(arg[i],"|")==0)
        {
            flag++;
            how=3;
            if(arg[i+1]==NULL||i==0)
            {
                flag++;
            }
        }
    }
    if(flag>1)
    {
        printf("Command Error\n");
        return ;
    }
    if(how==1)
    {
        for(i=0;arg[i]!=NULL;i++)
        {
            if(!strcmp(arg[i],">"))
            {
                file=arg[i+1];
                arg[i]=NULL;
            }
        }
    }
    if(how==2)
    {
        for(i=0;arg[i]!=NULL;i++)
        {
            if(!strcmp(arg[i],"<"))
            {
                file=arg[i+1];
                arg[i]=NULL;
            }
        }
    }
    if(how==4)
    {
        for(i=0;arg[i]!=NULL;i++)
        {
            if(!strcmp(arg[i],">>"))
            {
                file=arg[i+1];
                arg[i]=NULL;
            }
        }
    }
    if(how==3)
    {
        for(i=0;arg[i]!=NULL;i++)
        {
            if(!strcmp(arg[i],"|"))
            {
                arg[i]=NULL;
                int j;
                for(j=i+1;arg[j]!=NULL;j++)
                {
                    argnext[j-i-1]=arg[j];
                }
                argnext[j-i-1]=arg[i];
                break;
            }
        }
    }
    pid=fork();
    switch(how)
    {
        case 0:
            if(pid==0) //确保子进程运行
            {
                if(!find_command(arg[0]))
                {
                    printf("%s:Not Found This Commond!\n",arg[0]);
                    exit(0);
                }
                execvp(arg[0],arg); //子进程运行其他程序，arg[0]为程序名，arg为程序的附带参数
                exit(0);
            }
            break;
         case 1:
            if(pid==0)
            {
                if(!find_command(arg[0]))
                {
                    printf("%s:Not Found This Commond!\n",arg[0]);
                    exit(0);
                }
                fd=open(file,O_RDWR|O_CREAT|O_TRUNC,0644);
                dup2(fd,1);  //在标准输入之前调用dup，dup2函数
                execvp(arg[0],arg);
                exit(0);
            }
            break;
        case 2:
            if(pid==0)
            {
                if(pid==0)
                {
                    if(!find_command(arg[0]))
                    {
                        printf("%s:Not Found Commond!\n",arg[0]);
                        exit(0);
                    }
                }
                fd=open(file,O_RDONLY);
                if(fd==-1)
                {
                    printf("%s:Not Found This File\n",file);
                }
                else
                {
                    dup2(fd,0);
                    execvp(arg[0],arg);
                }
                exit(0);
            }
        case 4:
            if(pid==0)
            {
                if(!find_command(arg[0]))
                {
                    printf("%s:Not Found This Commond!\n",arg[0]);
                    exit(0);
                }
                fd=open(file,O_RDWR|O_CREAT|O_APPEND,0644);
                dup2(fd,1);
                execvp(arg[0],arg);
                exit(0);
            }
            break;
        case 3:
            if(pid==0)
            {
                int status2;
                pid_t pid2;
                pid2=fork();
                if(pid2==0)
                {
                    if(!find_command(arg[0]))
                    {
                        printf("%s:Not Found Commond!\n",arg[0]);
                        exit(0);
                    }
                    fd2=open("/tmp/data",O_RDWR|O_CREAT|O_TRUNC,0644);
                    dup2(fd2,1);
                    execvp(arg[0],arg);
                    exit(0);
                }
                if(waitpid(pid2,&status2,0)==-1)
                {
                    printf("wait for child process error!");
                }
                if(!find_command(argnext[0]))
                {
                    printf("%s:commond not found\n",argnext[0]);
                    exit(0);
                }
                fd=open("/tmp/data",O_RDONLY);
                dup2(fd,0);
                execvp(argnext[0],argnext);
                remove("/tmp/data");
                exit(0);
            }
            break;
        default:
            break;
    }
    if(background==1)
    {
        printf("[1] %d\n",pid);
        return;
    }
    if(waitpid(pid,&status,0)==-1)
        printf("Wait for child process error!\n");
}
int find_command(char *command)//在当前目录下，/bin，/usr/bin下查找命令的可执行程序
{
    //文件目录解析函数，获取当前目录所有文件
    int i=0,j,count=0;
    DIR *dir;
    struct dirent *ptr;
    char *path[]={"./","/bin","/usr/bin"};
    if(strncmp(command,"./",2)==0)
        command=command+2;
    while(path[i]!=NULL)
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
                closedir(dir);
                return 1;
            }
        }
        closedir(dir);
        i++;
    }
}
/*
void main()
{
    int argcount,i;
    char *buf;
    char arglist[100][256]; // 最多输入100条命令，每条命令不超过255个字符
    buf=(char *)malloc(256*sizeof(char));
    while(1)
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
        argcount=explain_input(buf,arglist);
        do_cmd(argcount,arglist);
        for(i=0;i<argcount;i++)
        {
            memset(arglist[i],0,256);
        }
    }
}*/
void main()
{
        int i,argcount;;
        char buf[256];
        char arglist[100][256];
        print_prompt();
        get_input(buf);
        argcount=explain_input(buf,arglist);
        for(i=0;i<argcount;i++)
        {
            printf("%s\n",arglist[i]);
        }
}