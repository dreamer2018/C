//
// Created by zhoupan on 3/10/17.
//

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

#define MAX_LINE 80
#define MAX_STRING 256   //最长文件名

//链表头插法初始化
#define List_Init(list, list_node_t){                     \
    list=(list_node_t *)malloc(sizeof(list_node_t));    \
    list->next=NULL;                                    \
}
//链表头插法宏定义
#define List_AddHead(list, newNode){      \
    newNode->next=list->next;           \
    list->next=newNode;                 \
}
typedef struct str_sort {
    char str[256];
    char str2[256];
    struct str_sort *next;
} str_node_t;
//函数声明部分

void my_stat(int flag, char *name);

void my_err(const char *err_string, int line);

char *analy_filetype(struct stat *buf);

void print_filemode_usr(struct stat *buf);

void print_filemode_gro(struct stat *buf);

void print_filemode_oth(struct stat *buf);

void print_usr_name(struct stat *buf);

void print_gro_name(struct stat *buf);

void print_time(time_t st_time);

int display(int flag, char *path);

int display_R(char *path);

void sort(int count, str_node_t *head);

int print_info_srv(int count, int flag, str_node_t *head);


int display(int flag, char *path)  //文件目录解析函数，获取当前目录所有文件
{
    int i = 0, count = 0;
    DIR *dir;
    struct dirent *ptr;
    char cwd[256];
    getcwd(cwd, 256);
    chdir(path);
    str_node_t *newNode, *head;
    List_Init(head, str_node_t);
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }
    while ((ptr = readdir(dir)) != NULL) {
        i++;
        newNode = (str_node_t *) malloc(sizeof(str_node_t));
        strcpy(newNode->str, ptr->d_name);
        List_AddHead(head, newNode); //头插法建立新链表
    }
    count = i;
    print_info_srv(count, flag, head);
    closedir(dir);
    chdir(cwd);
    return 0;
}

int display_R(char *path) //专为ls -R 设计的用于递归的函数
{
    int i = 0, count = 0;
    DIR *dir;
    struct dirent *ptr;
    struct stat buf;
    char cwd[256];
    getcwd(cwd, 256); //获得当前路径
    chdir(path);    //切换到path所代表的路径
    str_node_t *newNode, *head, *p;
    List_Init(head, str_node_t);
    if ((dir = opendir("./")) == NULL) {
        perror("opendir");
        return -1;
    }
    while ((ptr = readdir(dir)) != NULL) {
        i++;
        newNode = (str_node_t *) malloc(sizeof(str_node_t));
        strcpy(newNode->str, ptr->d_name);
        List_AddHead(head, newNode);
    }
    count = i;
    sort(count, head);
    p = head;
    for (i = 0; i < count; i++) {
        p = p->next;
        lstat(p->str, &buf);
        if (!strcmp(p->str, ".") || !strcmp(p->str, "..") || p->str[0] == '.')  //去除掉此文件夹下的. .. 和.开头的隐藏文件
        {
            continue;
        }
        if (S_ISDIR(buf.st_mode)) //判断是否为目录
        {
            printf("\n\033[34m%s", cwd); //改变颜色为蓝色
            printf("%s/\033[0m\n", p->str);
            display_R(p->str);
        } else {
            printf("%-15s\t", p->str);
        }
    }
    printf("\n");
    closedir(dir);
    chdir(cwd);  //切换回原路径
    return 1;
}

int print_info_srv(int count, int flag, str_node_t *head)     //打印文件信息服务函数
{
    int i;
    str_node_t *p;
    sort(count, head);      //对文件名进行排序
    p = head;
    for (i = 0; i < count; i++) {
        p = p->next;
        if (flag == -1 || flag == 0) {
            if (!strcmp(p->str, ".") || !strcmp(p->str, "..") || p->str[0] == '.') {
                continue;
            }
            my_stat(flag, p->str);
            if (i == count - 1) {
                printf("\n");
            }
        } else {
            my_stat(flag, p->str);
        }
    }
    return 0;
}

void sort(int count, str_node_t *head) //文件名排序函数，使用的是冒牌排序法
{
    int i, j;
    char temp[256];
    str_node_t *p;
    for (i = 1; i <= count; i++) {
        p = head->next;
        for (j = 1; j < count; j++) {
            if (strcmp(p->str, p->next->str) > 0) {
                strcpy(temp, p->str);
                strcpy(p->str, p->next->str);
                strcpy(p->next->str, temp);
            }
            p = p->next;
        }
    }
}

void my_stat(int flag, char *name)  //打印文件相关信息
{
    struct stat buf;
    lstat(name, &buf);
    if (flag == 0 || flag == 2) {
        printf("%s", analy_filetype(&buf));
        print_filemode_usr(&buf);
        print_filemode_gro(&buf);
        print_filemode_oth(&buf);
        printf("%3d", buf.st_nlink);
        print_usr_name(&buf);
        print_gro_name(&buf);
        printf("%6d", buf.st_size);
        print_time(buf.st_mtime);
        if (S_ISDIR(buf.st_mode)) {
            printf(" \033[34m%-10s\033[0m\n", name);
        } else {
            printf(" %-10s\n", name);
        }
    } else {
        if (S_ISDIR(buf.st_mode)) {
            printf(" \033[34m%-10s\033[0m", name);
        } else {
            printf("%-14s", name);
        }
    }
}

char *month_analy(int month)     //月份解析函数
{
    switch (month) {
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
        default:
            return "";
    }
}

void print_time(time_t st_time) //日期解析函数
{
    struct tm p;
    gmtime_r(&st_time, &p);
    printf(" %3s", month_analy(p.tm_mon));
    if (p.tm_mday < 10) //小于十的前面补零
    {
        printf(" 0%d", p.tm_mday); //小于十的前面补零
    } else {
        printf(" %2d", p.tm_mday);
    }
    if (p.tm_hour < 2 || p.tm_hour >= 23) {
        printf(" 0%d:", (p.tm_hour + 8));  //此处系统使用的是国际标准时间，中国位于东八区，比标准时间早8个小时，故要加上八
    } else {
        printf(" %2d:", p.tm_hour + 8);
    }
    if (p.tm_min < 10) {
        printf("0%d", p.tm_min);
    } else {
        printf("%2d", p.tm_min);
    }
}


char *analy_filetype(struct stat *buf)  //文件类型解析函数
{
    if (S_ISLNK(buf->st_mode)) {
        return "l";    //符号链接
    } else if (S_ISREG(buf->st_mode)) {
        return "-";   //普通文件
    } else if (S_ISDIR(buf->st_mode)) {
        return "d";   //目录文件
    } else if (S_ISCHR(buf->st_mode)) {
        return "c";  //字符特殊文件
    } else if (S_ISBLK(buf->st_mode)) {
        return "b";  //块特殊文件
    } else if (S_ISFIFO(buf->st_mode)) {
        return "f";  //命名管道
    } else if (S_ISSOCK(buf->st_mode)) {
        return "s";   //套接字
    }
    return "";
}

void print_filemode_usr(struct stat *buf)   //文件所有者
{
    //文件所有者权限
    if (buf->st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if (buf->st_mode & S_IWUSR)
        printf("w");
    else
        printf("-");
    if (buf->st_mode & S_IXUSR)
        printf("x");
    else
        printf("-");
}

void print_filemode_gro(struct stat *buf)  //文件所数组
{
    //文件用户组权限
    if (buf->st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if (buf->st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if (buf->st_mode & S_IXGRP)
        printf("x");
    else
        printf("-");
}

void print_filemode_oth(struct stat *buf)  //其他用户
{
    //其他用户权限
    if (buf->st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if (buf->st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if (buf->st_mode & S_IXOTH)
        printf("x ");
    else
        printf("- ");
}

void print_usr_name(struct stat *buf) //通过uid 输出用户名
{
    struct passwd *pwd;
    pwd = getpwuid(buf->st_uid);
    printf(" %s", pwd->pw_name);
}

void print_gro_name(struct stat *buf) //通过gid输出用户组名a
{
    struct group *gup;
    gup = getgrgid(buf->st_gid);
    printf(" %s", gup->gr_name);
}

int main(int argc, char **argv) {
    int flag;           //flag=-1 [ls] flag=0 [ls -l]     flag=1 [ls -a]  flag=2  [ls -al/-la]
    if (1 == argc)         //analysis: ls
    {
        flag = -1;
        display(flag, ".");
        return 0;
    } else if (argc == 2 && !strcmp("-l", argv[1]))  //analysis: ls -l
    {
        flag = 0;
        display(flag, ".");
    } else if (argc == 2 && !strcmp("-a", argv[1]))  //analysis: ls -a
    {
        flag = 1;
        display(flag, ".");
    } else if (argc == 2 && !strcmp("-al", argv[1])) //analysis: ls -al
    {
        flag = 2;
        display(flag, ".");
    } else if (argc == 2 && !strcmp("-la", argv[1])) //analysis : ls -la
    {
        flag = 2;
        display(flag, ".");
    } else if (argc == 2) //analysis: ls file
    {
        flag = -1;
        display(flag, argv[1]);
    } else if (argc == 3 && !strcmp("-l", argv[1]))  //analysis: ls -l file
    {
        flag = 0;
        display(flag, argv[2]);
    } else if (argc == 3 && !strcmp("-a", argv[1]))  //analysis : ls -a file
    {
        flag = 1;
        display(flag, argv[2]);

    } else if (argc == 3 && !strcmp("-al", argv[1])) //analysis :ls -al file
    {
        flag = 2;
        display(flag, argv[2]);
    } else if (argc == 3 && !strcmp("-la", argv[1])) //analysis :ls -la file
    {
        flag = 2;
        display(flag, argv[2]);
    } else if (argc == 2 && !strcmp("-R", argv[1]))  //analyse: ls -R
    {
        display_R(".");
    } else if (argc == 3 && !strcmp("-R", argv[1]))   //analyse : ls -R file
    {
        display_R(argv[2]);
    } else {
        printf("Not Support This Commond\n"); //与以上不匹配，报错
    }
    return 0;
}