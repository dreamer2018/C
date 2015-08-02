/*************************************************************************
	> File Name: cd.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Sun 02 Aug 2015 07:39:39 AM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

void my_cd(char *arg)
{
    errno=0;
    char buf1[512],buf2[512];
    getcwd(buf2,511);
    printf("%s\n",buf2);
    if(chdir(arg)<0)
    {
        printf("%s:%s\n",arg,strerror(errno));
    }
    getcwd(buf1,511);
    printf("%s\n",buf1);
}
void main(int argc,char *argv)
{
    int i;
    char buf[512],ch;
    for(i=0;i<511;i++)
    {
        ch=getchar();
        if(ch=='\n')
        {
            buf[i]='\0';
            break;
        }
        buf[i]=ch;
    }
    my_cd(buf);
}
