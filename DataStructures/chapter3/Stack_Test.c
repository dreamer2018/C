/*************************************************************************
	> File Name: Stack_Test.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Tue 15 Sep 2015 09:27:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int top;
}StackNode;

void Init(StackNode *S)
{
    S->top=-1;
}

int Push(StackNode *S,ElemType e)
{
    if(S->top>=MAXSIZE-1)
    {
        printf("Stack is full!\n");
        return 0;
    }
    S->top++;
    S->elem[S->top]=e;
    return 1;
}

int Pop(StackNode *S,ElemType *e)
{
    if(S->top<0)
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *e=S->elem[S->top];
    S->top--;
}
int main()
{
    int e;
    StackNode *S;
    S=(StackNode *)malloc(sizeof(StackNode));
    Init(S);
    while(1)
    {
        scanf("%d",&e);
        if(!Push(S,e))
        {
            break;   
        }
    }
    while(1)
    {
        if(!Pop(S,&e))
        {
            break;   
        }
        printf("%d\t",e);
    }
    printf("\n");
}
