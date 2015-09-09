/*************************************************************************
	> File Name: 2.2.2.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Wed 09 Sep 2015 12:33:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct
{
    ElemType elem[MAXSIZE];
    int n;
}Seqlist;

void Init(Seqlist *S)
{
    S->n=0;
}

int Insert(Seqlist *S,ElemType e)
{
    if(S->n>=MAXSIZE-1)
    {
        printf("Seqlist is full!\n");
        return 0;
    }
    S->n++;
    S->elem[S->n]=e;
    return 1;
}

//删除多个元素
int Delete_Element(Seqlist *S,ElemType e)
{
    int i,j;
    if(S->n<1)
    {
        printf(" Seqlist is Empty!\n");
        return 0;
    }
    for(i=S->n;i>0;i--)
    {
        if(S->elem[i]==e)
        {
            for(j=i;j<S->n;j++)
            {
                S->elem[j]=S->elem[j+1];
            }
            S->n--;
        }
    }
    return 1;
}

int Seqlist_Print(Seqlist *S)
{
    int i;
    if(S->n==0)
    {
        printf("Seqlist is Empty!\n");
        return 0;
    }
    for(i=1;i<=S->n;i++)
    {
        printf("%d\t",S->elem[i]);   
    }
    printf("\n");
    return 1;
}

//线性表的逆置
int Merge(Seqlist *S)
{
    int i;
    ElemType swap;
    if(S->n==0)
    {
        printf("Seqlist is Empty!\n");
        return 0;
    }
    for(i=1;i<=(S->n)/2 ;i++)
    {
        swap=S->elem[i];
        S->elem[i]=S->elem[S->n-i+1];
        S->elem[S->n-i+1]=swap;
    }
    return 1;
}

int main()
{
    int i;
    ElemType e,r;
    Seqlist *S;
    S=(Seqlist *)malloc(sizeof(Seqlist));
    Init(S);
    for(i=0;i<5;i++)
    {
        scanf("%d",&e);
        Insert(S,e);
    }
    Seqlist_Print(S);
    Merge(S);
    /*
    scanf("%d",&r);
    Delete_Element(S,r);
    */
    Seqlist_Print(S);
    
}
