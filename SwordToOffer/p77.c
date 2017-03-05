/*************************************************************************
	> File Name: p77.c
	> Author:  ZhouPan
	> GitHub:  https://github.com/dreamer2018
	> Mail:  zhoupan@xiyoulinux.org
	> Blog:  http://blog.csdn.net/it_dream_er
	> Created Time: Sun 05 Mar 2017 06:19:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>

int CountLine(char symbol[])
{
    int i,sum=0,len = strlen(symbol);
    printf("%d\n",len);
    for(i=0;i<len;i++)
    {
        sum+=(symbol[i]-64)*pow(26,len-i-1);
    }
    return sum;
}
int main()
{
    char symbol[20];
    scanf("%s",symbol);
    printf("%d\n",CountLine(symbol));
}
