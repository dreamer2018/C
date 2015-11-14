/*************************************************************************
	> File Name: BucketSort.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Declared: Signed on behalf of not only belongs , but also represent a responsibility!
	> Created Time: 2015年11月14日 星期六 13时29分56秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
void Sort(int a[],int n,int *Bucket)
{
    int i;
    for(i=0;i<n;i++)
    {
        Bucket[a[i]]++;
    }
}

void Print(int *a,int n) //输出排序结果
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i];j++)
        {
            printf("%d\t",i);
        }
    }
    printf("\n");
}

int main()
{
    int num[]={1,5,8,3,4};
    int Bucket[10];
    memset(Bucket,0,sizeof(Bucket));
    Sort(num,5,Bucket);
    Print(Bucket,10);
}
