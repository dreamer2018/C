/*************************************************************************
	> File Name: checkerror.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Sat 01 Aug 2015 05:37:05 PM CST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>

int main()
{
    FILE *fp;

    errno=0;

    fp=fopen("test","r");

    if(fp==NULL)
    {
        printf("文件打开失败！errno=%d\n",errno);
    }
    else
    {
        printf("文件打开成功！errno=%d\n",errno);
        fclose(fp);
    }
}

