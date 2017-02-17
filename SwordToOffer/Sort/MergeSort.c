/*************************************************************************
	> File Name: MergeSort.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.07 20:35
 ************************************************************************/
#include<stdio.h>

//归并排序递归实现


//将两个有序数组合并
void Merge(int data[],int start,int middle,int end,int Temp[])
{
    int i=start,j=middle+1,k=0;
    while(i<=middle && j<=end)
    {
        if(data[i]>data[j])
        {
            Temp[k++] = data[j++];
        }
        else
        {
            Temp[k++] = data[i++];
        }
    }
    //将剩余部分加入
    while(i<=middle)
    {
        Temp[k++] = data[i++];
    }
    while(j<=end)
    {
        Temp[k++] = data[j++];
    }

    //将排序后的结果保存会原序列
    for(i=0;i<k;i++)
    {
        data[start+i] = Temp[i];
    }
}
void MergeSort(int data[], int start,int end,int Temp[])
{
    if(start < end)
    {
        int middle = (start+end)/2;
        //对左半部分排序
        MergeSort(data,start,middle,Temp);
        //对右半部分排序
        MergeSort(data,middle+1,end,Temp);
        //将左右两部分合并
        Merge(data,start,middle,end,Temp);
    }
}
void Print(int data[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",data[i]);
    }
    printf("\n");
}
int main()
{
    int data[10] = {4,6,2,1,5,3,4,1,2,3};
    Print(data,10);
    int Temp[10]={};
    MergeSort(data,0,9,Temp);
    Print(data,10);
}
