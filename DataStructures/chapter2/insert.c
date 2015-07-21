#include<stdio.h>
#define SIZE 9
int insert(int a[],int e,int i)
{
    int j,k=-1,n,rtn=0;
    int b[SIZE+1];
    n=SIZE;
    if(i<0 || i>n)
    {
        return rtn;
    }
    for(j=0;j<n;j++)
    {
        k++;
        if(i==j)
        {
            rtn=1;
            b[k]=e;
            k++;
            b[k]=a[j];
        }
        else
        {
            b[k]=a[j];
        }
    }
    if(rtn)
    {
        for(i=0;i<n+1;i++)
        {
            printf("%d\t",b[i]);
        }
        printf("\n");
    }
    return rtn;
}
void main()
{
    int e,i,rtn;
    int a[SIZE]={4,9,15,28,30,30,42,51,62};
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nPlease Input locate/element :");
    scanf("%d %d",&i,&e);
    rtn=insert(a,e,i-1);
    if(!rtn)
    {
       printf("Fail !\n");
    }
}
