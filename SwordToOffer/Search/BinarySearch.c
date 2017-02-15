/*************************************************************************
	> File Name: linked_1.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.07 20:35
 ************************************************************************/
#include<stdio.h>

//二分查找
int BinarySearch(int key,int data[], int length);


//二分查找
int BinarySearch(int key, int data[], int length)
{
    int start=0,end = length-1;
    while(start <= end)
    {
        int middle = (start + end)/2;

        if(key > data[middle])
        {
            start = middle + 1;
        }
        else if(key < data[middle])
        {
            end = middle -1;
        }
        else
        {
            return end;
        }
    }
    return -1;
}


int main()
{
    int data[]={1,2,3,4,6,8,9};
    printf("%d\n",BinarySearch(9,data,7));
}
