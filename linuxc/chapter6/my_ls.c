#include<sys/types.h>
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
#include<pwd.h>
#define MAX_STRING 100

//函数声明部分
int my_readir(const char *path);
void my_stat(char *name);
void my_err(const char *err_string,int line);
char *analy_filetype(mode_t st_mode);
void print_filemode_usr(mode_t st_mode);
void print_filemode_gro(mode_t st_mode);
void print_filemode_oth(mode_t st_mode);
void print_usr_name(uid_t st_uid);
void print_gro_name(gid_t st_gid);
void print_time(time_t st_time);

typdef struct file
{
    char name[MAX_STRING];
    struct file *next;
}file_node_t;
int my_readir(const char *path)
{
    DIR *dir;
    struct dirent *ptr;
    if((dir=opendir(path))==NULL)
    {
        perror("opendir");
        return -1;
    }

    while((ptr=readdir(dir))!=NULL)
    {
        my_stat(ptr->d_name);
    }
    closedir(dir);
    return 0;
}
void list_sort()
{
}
void my_stat(char *name)
{
    struct stat buf;
    stat(name,&buf);
    printf("%s",analy_filetype(buf.st_mode));
    print_filemode_usr(buf.st_mode);
    print_filemode_gro(buf.st_mode);
    print_filemode_oth(buf.st_mode);
    printf("%d",buf.st_nlink);
    print_usr_name(buf.st_uid);
    print_gro_name(buf.st_gid);
    printf("%6d",buf.st_size);
    print_time(buf.st_mtime);
    printf(" %-10s\n",name);
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
    printf(" %3s %2d %2d:%2d",month_analy(p.tm_mon),p.tm_mday,(p.tm_hour+8),p.tm_min);
}
void my_err(const char *err_string ,int line)
{
    fprintf(stderr,"line:%d",line);
    perror(err_string);
    exit(1);
}

char *analy_filetype(mode_t st_mode)  //文件类型解析函数
{
    if(S_ISLNK(st_mode))
    {
        return "l";    //符号链接
    }
    else if(S_ISREG(st_mode))
    {
        return "-";   //普通文件
    }
    else if(S_ISDIR(st_mode))
    {
        return "d";   //目录文件
    }
    else if(S_ISCHR(st_mode))
    {
        return "c";  //字符特殊文件
    }
    else if(S_ISBLK(st_mode))
    {
        return "b";  //块特殊文件
    }
    else if(S_ISFIFO(st_mode))
    {
        return "f";  //命名管道
    }
    else if(S_ISSOCK(st_mode))
    {
        return "s";   //套接字
    }
}

void print_filemode_usr(mode_t st_mode)   //文件所有者
{
    //文件所有者权限
    if(st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if(st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if(st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
}

void print_filemode_gro(mode_t st_mode)  //文件所数组
{
    //文件用户组权限
    if(st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if(st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if(st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
}

void print_filemode_oth(mode_t st_mode)  //其他用户
{
    //其他用户权限
    if(st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if(st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if(st_mode & S_IXOTH)
        printf("x ");
    else
        printf("- ");
}

void print_usr_name(uid_t st_uid) //通过uid 输出用户名
{
    struct passwd *pwd;
    pwd=getpwuid(st_uid);
    printf(" %s",pwd->pw_name);
}
void print_gro_name(gid_t st_gid) //通过gid输出用户组名a
{
    struct group *gup;
    gup=getgrgid(st_gid);
    printf(" %s",gup->gr_name);
}
int main(int argc,char **argv)
{
    if(argc<2)
    {

    }
    if(my_readir(argv[1])<0)
    {
        exit(0);
    }
    return 0;
}
