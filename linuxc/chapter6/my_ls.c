/*#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
#include<dirent.h>
#include<grp.h>
#include<pwd.h>*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <linux/limits.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define PARAM_NONE 0 //无参数
#define PARAM_A    1 //-a
#define PARAM_L    2 //-l
#define MAXROWLEN  80 //一行最多显示的字符数

int g_leave_len = MAXROWLEN; //一行是剩余长度，用于输出对齐
int g_maxlen;                //存放某目录下最长文件名的长度


#define MAX_LINE 80
#define MAX_STRING 256   //最长文件名

//链表头插法初始化
#define List_Init(list,list_node_t){                     \
    list=(list_node_t *)malloc(sizeof(list_node_t));    \
    list->next=NULL;                                    \
}
//链表头插法宏定义
#define List_AddHead(list,newNode){      \
    newNode->next=list->next;           \
    list->next=newNode;                 \
}
typedef struct str_sort
{
    char str[256];
    char str2[256];
    struct str_sort *next;
}str_node_t;
//函数声明部分

void my_stat(int flag,char *name);
void my_err(const char *err_string,int line);
char *analy_filetype(struct stat *buf);
void print_filemode_usr(struct stat *buf);
void print_filemode_gro(struct stat *buf);
void print_filemode_oth(struct stat *buf);
void print_usr_name(struct stat *buf);
void print_gro_name(struct stat *buf);
void print_time(time_t st_time);
int display(int flag,char *path);
//int display_R(int flag,char *path);
void sort(int count,str_node_t *head);
int print_info_srv(int count,int flag,str_node_t *head);


int display(int flag,char *path)
{
    int i=0,j,count=0;
    DIR *dir;
    struct dirent *ptr;
    char cwd[256];
    getcwd(cwd,256);
    chdir(path);
    str_node_t *newNode,*head;
    List_Init(head,str_node_t);
    if((dir=opendir(path))==NULL)
    {
        perror("opendir");
        return -1;
    }
    while((ptr=readdir(dir))!=NULL)
    {
        i++;
        newNode=(str_node_t *)malloc(sizeof(str_node_t));
        strcpy(newNode->str,ptr->d_name);
        List_AddHead(head,newNode);
    }
    count=i;
    print_info_srv(count,flag,head);
    closedir(dir);
    chdir(cwd);
}

/*
void my_error(const char* errstring, int line)
{
    fprintf(stderr,"line:%d",line);
    perror(errstring);
    exit(1);
}
void display(int flag,char *path)
{
    DIR* dir;
    struct dirent *dirent;
    str_node_t *newNode,*head,*p;
    char str[PATH_MAX+1];
    int count = 0;                  //总共有多少个文件
    if((dir = opendir(path)) == NULL)
    {
        my_error("opendir",__LINE__);
    }
    //获取文件总数和最长文件名
    while((dirent = readdir(dir)) != NULL)
    {
        if(g_maxlen < strlen(dirent->d_name))
            g_maxlen = strlen(dirent->d_name);
        count++;
    }
    closedir(dir);

    if(count>256)
        my_error("文件太多超过了256个",__LINE__);
}
int print_info_srv(int count,int flag,str_node_t *head)
{
    int i,j,len = strlen(path);
    //获取目录下所有的文件名
    dir = opendir(path);
    for(i=0;i<count;i++)
    {
        dirent=readdir(dir);
        if(dirent == NULL)
        {
            my_error("readdir",__LINE__);
        }
        strncpy(str,path,len);
        str[len] = 0;
        strcat(str,dirent->d_name);
        str[len+strlen(dirent->d_name)] = 0;
        newNode=(str_node_t *)malloc(sizeof(str_node_t));
        strcpy(newNode->str,str);
        strcpy(newNode->str2,dirent->d_name);
        List_AddHead(head,newNode);
    }*/
int print_info_srv(int count,int flag,str_node_t *head)
{
    int i;
    str_node_t *p;
    sort(count,head);
    p=head;
    for(i=0;i<count;i++)
    {
        p=p->next;
        if(flag==-1 || flag==0)
        {
            if(!strcmp(p->str,".")||!strcmp(p->str,".."))
                continue;
            my_stat(flag,p->str);
        }
        else
        {
           my_stat(flag,p->str);
        }
    }
    printf("\n");
}

void sort(int count,str_node_t *head)
{
    int i,j;
    char temp[256];
    str_node_t *p;
    for(i=1;i<=count;i++)
    {
        p=head->next;
        for(j=1;j<count;j++)
        {
            if(strcmp(p->str,p->next->str)>0)
            {
                strcpy(temp,p->str);
                strcpy(p->str,p->next->str);
                strcpy(p->next->str,temp);
            }
            p=p->next;
        }
    }
}
    /*
    for(i=0;i<=count;i++)
    {
        p=head->next;
        for(j=1;j<count;j++)
        {
            if(strcmp(p->str,p->next->str)>0)
            {
                strcpy(temp,p->str);
                strcpy(p->str,p->next->str);
                strcpy(p->next->str,temp);
            }
            p=p->next;
        }
    }*/
/*
int display_R(int flag,char *path)
{
    DIR* dir;
    struct dirent *dirent;
    struct stat buf;
    str_node_t *newNode,*head,*p;
    char str[PATH_MAX+1];
    int count = 0;      //总共有多少个文件
    if((dir = opendir(path)) == NULL)
    {
        my_error("opendir",__LINE__);
    }

    //取得最长文件名
    while((dirent = readdir(dir)) != NULL)
    {
        if(g_maxlen < strlen(dirent->d_name))
            g_maxlen = strlen(dirent->d_name);
        count++;
    }
    closedir(dir);

    if(count>256)
        my_error("文件太多超过了256个",__LINE__);

    int i,j,len = strlen(path);
    //获取目录下所有的文件名
    dir = opendir(path);
    for(i=0;i<count;i++)
    {
        dirent = readdir(dir);
        if(dirent == NULL)
        {
            my_error("readdir",__LINE__);
        }
        strncpy(str,path,len);
        str[len] = 0;
        strcat(str,dirent->d_name);
        str[len+strlen(dirent->d_name)] = 0;
        newNode=(str_node_t *)malloc(sizeof(str_node_t));
        strcpy(newNode->str,str);
        List_AddHead(head,newNode);
    }
    sort(count,head);
    p=head;
    for(i=0;i<count;i++)
    {
        p=p->next;
        lstat(p->str,&buf);
        if(!strcmp(p->str,".")||!strcmp(p->str,".."))
        {
            continue;
        }
        if(S_ISDIR(buf.st_mode))
        {
            printf("%s",p->str);
            display_R(2,p->str);
        }
        else
        {
            printf("%s",p->str);
        }
    }
    closedir(dir);
    return 1;
}*/


void my_stat(int flag,char *name)
{
    struct stat buf;
    lstat(name,&buf);
    if(flag==0 || flag==2)
    {
            printf("%s",analy_filetype(&buf));
            print_filemode_usr(&buf);
            print_filemode_gro(&buf);
            print_filemode_oth(&buf);
            printf("%d",buf.st_nlink);
            print_usr_name(&buf);
            print_gro_name(&buf);
            printf("%6d",buf.st_size);
            print_time(buf.st_mtime);
            printf(":%-10s\n",name);
    }
    else
    {
    	printf("%-15s",name);
    }
}
char *month_analy(int month)
{
    switch(month)
    {
        case 0:
            return "Jan";
        case 1:
            return "Feb";
        case 2:
            return "Mar";
        case 3:
            return "Apr";
        case 4:
            return "May";
        case 5:
            return "Jun";
        case 6:
            return "Jul";
        case 7:
            return "Aug";
        case 8:
            return "Sep";
        case 9:
            return "Oct";
        case 10:
            return "Nov";
        case 11:
            return "Dec";
    }
}
void print_time(time_t st_time)
{
    struct tm p;
    gmtime_r(&st_time,&p);
    printf(" %3s",month_analy(p.tm_mon));
    if(p.tm_mday<10)
    {
        printf(" 0%d",p.tm_mday);
    }
    else
    {
        printf(" %2d",p.tm_mday);
    }
    if(p.tm_hour<2 || p.tm_hour>=23)
    {
        printf(" 0%d:",(p.tm_hour+8));
    }
    else
    {
        printf(" %2d:",p.tm_hour+8);
    }
    if(p.tm_min<10)
    {
        printf("0%d",p.tm_min);
    }
    else
    {
        printf("%2d",p.tm_min);
    }
}
void my_err(const char *err_string ,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

char *analy_filetype(struct stat *buf)  //文件类型解析函数
{
    if(S_ISLNK(buf->st_mode))
    {
        return "l";    //符号链接
    }
    else if(S_ISREG(buf->st_mode))
    {
        return "-";   //普通文件
    }
    else if(S_ISDIR(buf->st_mode))
    {
        return "d";   //目录文件
    }
    else if(S_ISCHR(buf->st_mode))
    {
        return "c";  //字符特殊文件
    }
    else if(S_ISBLK(buf->st_mode))
    {
        return "b";  //块特殊文件
    }
    else if(S_ISFIFO(buf->st_mode))
    {
        return "f";  //命名管道
    }
    else if(S_ISSOCK(buf->st_mode))
    {
        return "s";   //套接字
    }
}

void print_filemode_usr(struct stat *buf)   //文件所有者
{
    //文件所有者权限
    if(buf->st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if(buf->st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if(buf->st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
}

void print_filemode_gro(struct stat *buf)  //文件所数组
{
    //文件用户组权限
    if(buf->st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if(buf->st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buf->st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
}

void print_filemode_oth(struct stat *buf)  //其他用户
{
    //其他用户权限
    if(buf->st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if(buf->st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if(buf->st_mode & S_IXOTH)
        printf("x ");
    else
        printf("- ");
}

void print_usr_name(struct stat *buf) //通过uid 输出用户名
{
    struct passwd *pwd;
    pwd=getpwuid(buf->st_uid);
    printf(" %s",pwd->pw_name);
}
void print_gro_name(struct stat *buf) //通过gid输出用户组名a
{
    struct group *gup;
    gup=getgrgid(buf->st_gid);
    printf(" %s",gup->gr_name);
}
int main(int argc,char **argv)
{
   // display_R(2,argv[1]);

    int flag;          //flag=-1 :ls        flag=0 :ls -l   flag=1 ls -a  flag=2  ls -al/-la
    if(1==argc) //analysis: ls
    {
        flag=-1;
        display(flag,"./");
        return 0;
    }
    else if(argc==2 && !strcmp("-l",argv[1]))  //analysis: ls -l
    {
        flag=0;
        display(flag,"./");
    }
    else if(argc==2 && !strcmp("-a",argv[1]))  //analysis: ls -a
    {
        flag=1;
        display(flag,"./");
    }
    else if(argc==2 && !strcmp("-al",argv[1])) //analysis: ls -al
    {
        flag=2;
        display(flag,"./");
    }
    else if(argc==2 && !strcmp("-la",argv[1])) //analysis : ls -la
    {
        flag=2;
        display(flag,"./");
    }
    else if(argc==2) //analysis: ls file
    {
        flag=-1;
        display(flag,argv[1]);
    }
    else if(argc==3 && !strcmp("-l",argv[1]))  //analysis: ls -l file
    {
        flag=0;
      //  printf("%s",argv[2]);
        display(flag,argv[2]);
    }
    else if(argc==3 && !strcmp("-a",argv[1]))  //analysis : ls -a file
    {
        flag=1;
        display(flag,argv[2]);

    }
    else if(argc==3 && !strcmp("-al",argv[1])) //analysis :ls -al file
    {
        flag=2;
        display(flag,argv[2]);
    }
    else if(argc==3 && !strcmp("-la",argv[1])) //analysis :ls -la file
    {
        flag=2;
        display(flag,argv[2]);
    }
    /*
    else if(argc==2 && !strcmp("_R",argv[2]))
    {
        display_R("./");
    }
    else
    {
        printf("Not Support This Commond\n");
    }*/
    return 0;
}
