/*************************************************************************
	> File Name: SequenctSearch.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.15 10:47
 ************************************************************************/
#include<stdio.h>

int SequenctSearch(int key, int data[], int len)
{
    int i;
    for(i=0;i<len; i++)
    {
        if(data[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int data[6]={1,5,9,3,4,7};
    int rut = SequenctSearch(9,data,6);
    printf("%d\n",rut);
}
