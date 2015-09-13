/*************************************************************************
	> File Name: 1.9.1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Sun 13 Sep 2015 08:49:19 PM CST
 ************************************************************************/

#include<stdio.h>

int SelectByValue(int a[],int n,int value)
{
    int i;
    for(i=n-1;i>0;i--)
    {
        if(a[i]==value)
            break;
    }
    return i;
}

int main()
{
    int i,a[5];
    
    for(i=1;i<5;i++)
    {
        a[i]=i;
    }
    
    printf("%d",SelectByValue(a,5,8));
}
