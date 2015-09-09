/*************************************************************************
	> File Name: 2.2.5.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Wed 09 Sep 2015 07:18:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef int LinkType;
typedef struct Example
{
    LinkType i;
    struct Example *next;
}Linklist;

void Init(Linklist *h)
{
    h=(Linklist *)malloc(sizeof(Linklist));
    h->next=h;
}

Linklist *Insert()
{
    int l;
    Linklist *p,*q,*r;
    p=(Linklist *)malloc(sizeof(Linklist));
    scanf("%d",l);
    p->i=l;

    while(1)
    {
        q=(Linklist *)malloc(sizeof(Linklist));
        q->i=l;
        q->p
    }
    q->next=p;

}
 
int main()
{
     
}
