/*************************************************************************
	> File Name: 5.c
	> Author: ZhouPan / github: dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Created Time: Thu 05 May 2016 08:17:30 PM CST
    > Function:
 ************************************************************************/

#include<stdio.h>
int v0=3;
int v1[2]={1,2};
int v2;
void func(void)
{
    int i,v3=3;
    static int v4=7;
    int sum=0;
    v4=v4>>1;
    sum=v0+v1[1]+v1[2]+v2+v3+v4;
    printf("%d",sum);
}
int main()
{
    v2=3;
    func();
    return 0;
}
