#include<stdio.h>
#define SIZE_ONE 3
#define SIZE_TWO 4
#define SIZE SIZE_ONE+SIZE_TWO
int insert(int a[],int b[],int c[])
{
    int i,j,k,n;
    n=SIZE_TWO-1;
    for(i=0;i<SIZE_TWO;i++)
    {
        c[i]=b[i];
    }
    for(j=0;j<SIZE_ONE;j++)
    {
        n++;
        if(a[j]<c[0])
        {
            for(i=n;i>0;i--)
            {
                c[i]=c[i-1];
            }
            c[0]=a[j];
            continue;
        }
        if(a[j]>c[n-1])
        {
            c[n]=a[j];
            continue;
        }
        for(i=0;i<n;i++)
        {
            if(a[j]>=c[i] && a[j]<=c[i+1])
            {
                for(k=n;k>i+1;k--)
                {
                    c[k]=c[k-1];
                }
                c[i+1]=a[j];
                break;
            }
        }
    }
}
void main()
{
    int i,rtn;
    int a[SIZE_ONE]={10,13,15};
    int b[SIZE_TWO]={4,5,6,7};
    int c[SIZE];
    rtn=insert(a,b,c);
    printf("\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d\t",c[i]);
    }
}
