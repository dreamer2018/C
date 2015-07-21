#include<stdio.h>
#include<string.h>
#define SIZE 5
int locate_i(int a[],int i)  //根据位置i查找数组元素
{
    int j,n;
    int swap,rtn=-1;
    n=SIZE;
    if(i<0||i>n)
    {
        return rtn;
    }
    for(j=1;j<=n;j++)
    {
        if(i==j)
        {
            rtn=a[i-1];
        }
    }
    return rtn;
}
int locate_e(int a[],int e) //根据元素e查找其所在位置
{
    int rtn=-1,i,n;
    n=SIZE;
    for(i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            rtn=i;
        }
    }
    return rtn;
}
void main()
{
    int i,j,e,rtn;
    int a[SIZE]={3,2,7,6,8};
    for(j=0;j<SIZE;j++)
    {
        printf("%d\t",a[j]);
    }
    printf("\nPlease input :");
    scanf("%d",&i);
  //  scanf("%d",&e);
    rtn=locate_i(a,i);
  //   rtn=locate_e(a,e);
    if(rtn==-1)
    {
        printf("Not Found!\n");
    }
    else
    {
        printf("a[%d]=%d\n",i-1,rtn);
     //   printf("a[%d]=%d\n",rtn,e);
    }
}
