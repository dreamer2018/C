#include<stdio.h>
#define SIZE 9
int insert(int a[],int i)
{
    int j,k=-1,n,rtn=-1;
    int b[SIZE-1];
    n=SIZE;
    if(i<0 || i>n)
    {
        return rtn;
    }
    for(j=0;j<n;j++)
    {
        if(i!=j)
        {
            k++;
            b[k]=a[j];
        }
        else
        {
            rtn=a[i];
        }
    }

    if(rtn!=-1)
    {
        for(i=0;i<n-1;i++)
        {
            printf("%d\t",b[i]);
        }
        printf("\n");
    }
    return rtn;
}
void main()
{
    int i,rtn;
    int a[SIZE]={4,9,15,28,30,30,42,51,62};
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\nPlease Input locate:");
    scanf("%d",&i);
    rtn=insert(a,i-1);
    if(-1==rtn)
    {
       printf("Fail !\n");
    }
    else
    {
        printf("%d\n",rtn);
    }
}
