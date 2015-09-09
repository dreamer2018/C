/*************************************************************************
	> File Name: 2.2.1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Tue 08 Sep 2015 04:16:42 PM CST
 ************************************************************************/

#include<stdio.h>

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
        swap=elem[i];
        elem[i]=elem[S->n-i+1];
        elem[S->n-1]=swap;
    }
    return 1;
}

//链表的逆置
int Merge(Linklist *h)
{
    Linklist *p,*q;
    if(h->next==NULL)
    {
        printf("Linklist is Empty!\n");
        return 0;
    }
    p=h->next;
    h->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=h->next;
        h->next=p;
        p=q;
    }
    return 1;
}

int main()
{
    
}
