/*************************************************************************
	> File Name: ShellSort.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.15 13:54
 ************************************************************************/
#include<stdio.h>

void ShellSort(int data[], int len)
{
    int i,j,k;
    //改变缩进量
    for(i=len/2;i>0;i/=2)
    {
        for(j=0;j<i;j++)
        {
            for(k=j+i;k<len;k+=i)
            {
                if(data[k] < data[k-i])
                {
                    int tmp = data[k];
                    int h=k-i;
                    while(h>=0 && data[h] > tmp)
                    {
                        data[h+i]=data[h];
                        h-=i;
                    }
                    data[h+i]=tmp;
                }
            }
        }
    }
}
void Print(int data[], int len)
{
    int i = 0;
    for(i=0;i<len;i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
}
int main()
{
    int data[]={4,6,2,1,5,3,4,1,2,3};
    Print(data,10);
    ShellSort(data,10);
    Print(data,10);
}
