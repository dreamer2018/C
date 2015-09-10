#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;
}SeqList;
SeqList *L;

//顺序表的初始化
void init_SeqList(SeqList *L)
{
    L->length=0;
}

//顺序表的创建
int Insert(SeqList *L,ElemType s)
{
    if(L->length>=MAXSIZE-1)
    {
        printf("表满\n");
        return 0;
    }
    L->length++;
    L->elem[L->length]=s;
    return 1;
}

//顺序表的插入
int Insert_SeqList(SeqList *L,int i,ElemType x)
{
    int j;
    if(L->length==MAXSIZE-1)
    {
        printf("表满");
        return 0;   
    }
    if(i<1 || i>L->length+1)
    {
        printf("位置错");
        return 0;
    }
    for(j=L->length;j>=i;j--)
        L->elem[j+1]=L->elem[j];
    L->elem[i]=x;
    L->length++;
    return 1;
}
//顺序表的删除 
int Delete_SeqList(SeqList *L,int i)
    {
        int j;
        ElemType *x;
        if(i<1 || i>L->length)
        {    printf("不存在第i个元素");return 0;}
        *x=L->elem[i];
        for(j=i;j<=L->length-1;j++)
            L->elem[j]=L->elem[j+1];
        L->length--;
        return *x;
    }

//顺序表中按值查询
int Location_SeqList(SeqList *L,ElemType x)
{
    int i=1;
    while(i<=L->length && L->elem[i]!=x)
        i++;
    if(i>L->length) return 0;
    else return i;
}

//两个顺序表合并
SeqList *merge(SeqList *A,SeqList *B)
{
    SeqList *C;
    C=(SeqList *)malloc(sizeof(SeqList));
    init_SeqList(C);
    int i=1,j=1,k=1;
    while(i<=A->length && j<=B->length)
    {
        if(A->elem[i]>=B->elem[j])
            C->elem[k++]=B->elem[j++];
        else 
            C->elem[k++]=A->elem[i++];
    }
    printf("%d %d \n",i,j);
    while(i<=A->length)
        C->elem[k++]=A->elem[i++];
    while(j<=B->length)
        C->elem[k++]=B->elem[j++];
    C->length=A->length+B->length;
    return C;
}


//顺序表的输出
int Print(SeqList *L)
{
    int i;
    for(i=1;i<=L->length;i++)
        printf("%d\t",L->elem[i]);
}

void main()
{
    int i,x,s,flag=1;
    SeqList *A,*B,*C;
    L=(SeqList *)malloc(sizeof(SeqList));
    A=(SeqList *)malloc(sizeof(SeqList));
    B=(SeqList *)malloc(sizeof(SeqList));
    C=(SeqList *)malloc(sizeof(SeqList));
    //顺序表的初始化 
    init_SeqList(L);
    init_SeqList(A);
    init_SeqList(B);
    init_SeqList(C);
    //顺序表的创建 
    /*
    flag=1;

    while(i<5)
    {
        printf("input s\n");
        scanf("%d",&s);
        flag=Insert(L,s);
        i++;
    }
    printf("L:\n");
    Print(L);

    //顺序表的删除
    printf("input i:\n");
    scanf("%d",&i);
    x=Delete_SeqList(L,i);
    printf("\n");
    Print(L);
    
    //顺序表的插入
    printf("please input i,x:\n");
    scanf("%d%d",&i,&x);
    flag=Insert_SeqList(L,i,x);
    if(flag==1) printf("插入成功\n");
    printf("\n");
    Print(L);
    
    //顺序表中按值查找
    printf("input x\n");
    scanf("%d",&x);
    flag=Location_SeqList(L,x);
    if(flag==0) printf("找值在第%d个位置\n",flag);
    */
    //两个顺序表合并
    flag=1;
    while(flag<5)
    {
        printf("input s:\n");
        scanf("%d",&s);
        Insert(A,s);
        flag++;
    }
    printf("A:\n");
    Print(A);

    flag=1;
    while(flag<5)
    {
        printf("input s:\n");
        scanf("%d",&s);
        Insert(B,s);
        flag++;
    }
    printf("\nB:\n");
    Print(B);
    printf("\n+++++++++++++++++++++++++++++++++++++++++++\n");
    C=merge(A,B);
    Print(C);
    printf("\n");
}
