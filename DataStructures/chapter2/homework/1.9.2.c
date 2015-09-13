/*************************************************************************
	> File Name: 1.9.2.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Sun 13 Sep 2015 08:59:05 PM CST
 ************************************************************************/

#include<stdio.h>
void Get_Max(int a[],int n,int *max_max,int *max)
{
    int i;
    int min;
    *max_max=a[1];
    for(i=2;i<n;i++)
    {
        if(*max_max<a[i])
        {
            *max_max=a[i];
        }
        if(min>a[i])
        {
            min=a[i];
        }
    }
    *max=min;
    for(i=1;i<n;i++)
    {
        if(a[i]>*max && *max_max>a[i])
        {
            *max=a[i]; 
        }
    }
}
int main()
{
    int max_max,max;
    int i,a[6];
    for(i=1;i<6;i++)
    {
        scanf("%d",&a[i]);
    }
    Get_Max(a,6,&max_max,&max);
    printf("max_max=%d,max=%d\n",max_max,max);
}
