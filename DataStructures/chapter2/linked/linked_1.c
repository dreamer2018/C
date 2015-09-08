/*************************************************************************
	> File Name: linked_1.c
	> Author: ZhouPan / github:dreamer2018 
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: Mon 07 Sep 2015 04:00:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

typedef struct student
{
    int id;
    float score;
    struct student *next;
}stu;

stu *Tail()
{
    int id;
    float score;
    stu *head,*p,*q;
    head=(stu *)malloc(sizeof(stu));
    p=head;
    while(1)
    {
        scanf("%d %f",&id,&score);
        getchar();
        if(id<=0)
        {
            break;
        }
        q=(stu *)malloc(sizeof(stu));
        q->id=id;
        q->score=score;
        p->next=q;
        p=q;
    }

    return head;
}

int Merge(stu *head)
{
    if(head==NULL || head->next==NULL)
    {
        printf("pos id error\n");
        return 0;
    }
    stu *p,*q;
    p=head->next;
    head->next=NULL;
    while(p)
    {
        q=p->next;
        p->next=head->next;
        head->next=p;
        p=q;
    }
    return 1;
}
int main()
{
    stu *head,*p;
    head=Tail();
    p=head;
    while(p->next)
    {
        p=p->next;
        printf("%d %f\n",p->id,p->score);
    }
    Merge(head);
    p=head;
    while(p->next)
    {
        p=p->next;
        printf("%d %f\n",p->id,p->score);
    }
}
