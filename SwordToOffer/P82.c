/*************************************************************************
	> File Name: P82.c
	> Author:  ZhouPan
	> GitHub:  https://github.com/dreamer2018
	> Mail:  zhoupan@xiyoulinux.org
	> Blog:  http://blog.csdn.net/it_dream_er
	> Created Time: Sun 05 Mar 2017 09:21:23 PM CST
 ************************************************************************/

#include<stdio.h>
int IsPow2(int n)
{
    int j = n-1;
    return j&n ? 0:1;
}
int main()
{
    IsPow2(5) ? printf("是的"):printf("不是！");
}
