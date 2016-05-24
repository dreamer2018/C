/*************************************************************************
	> File Name: 4.c
	> Author: ZhouPan / github: dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Created Time: Mon 02 May 2016 09:15:09 PM CST
  > Function:
 ************************************************************************/

#include<stdio.h>
struct test{
    int a;
    double b;
    char c;
    short d;
};
void main()
{
    struct test s;
    printf("%d",sizeof(s));
}
