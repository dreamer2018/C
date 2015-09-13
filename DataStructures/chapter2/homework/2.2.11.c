/*************************************************************************
	> File Name: 2.2.11.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Sat 12 Sep 2015 02:41:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct josephus
{
    int data;
    struct josephus *next;
}Josephus;

Josephus * Insert(int n)
{
    int i;
    Josephus *p,*q,*head;
    head=(Josephus *)malloc(sizeof(Josephus));
    scanf("%d",&head->data);
    q=head;
    for(i=0;i<n-1;i++)
    {
        p=(Josephus *)malloc(sizeof(Josephus));
        scanf("%d",&p->data);
        q->next=p;
        q=p;
    }
    q->next=head;
    return head;
}

int Delete(Josephus *s,int i)
{
    int n;
    Josephus *p;
    p=s;
    while(p->next!=s)
    {
        p=p->next;
    }
    p->next=s->next;
    n=s->data;
    //free(s);
    return n;
}

int main()
{
    int n,m,i;
    Josephus *head,*p,*q;
    printf("请输入 m=");
    scanf("%d",&m);
    if(m<=0)
    {
        printf("你输入的不合法\n");
        return 0;
    }
    printf("请输入n：");
    scanf("%d",&n);
    if(n<m)
    {
        printf("不满足：n>=m\n");
        return 0;
    }
    printf("_________________________\n");
    head=Insert(n);
    printf("_________________________\n");
    p=head;
    while(n>0)
    {
        for(i=1;i<m;i++)
        {
            p=p->next;
        }
        q=p->next;
        printf("%d\t",Delete(p,n));
        p=q;
        n--;
    }
    printf("\n");
}
