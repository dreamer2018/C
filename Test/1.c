/**************************************************************************************************
	> File Name: 1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月18日 星期三 14时34分15秒
 ************************************************************************************************/

#include<stdio.h>
int Fun()
{
    int a=1000;
    printf("hello\n");
}
int Func()
{
    int a=10;
    a=10+2;
    Fun();
    //printf("hello");
}
int main()
{
    printf("%d\n",Func());
}
