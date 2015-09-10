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
    scanf("%d %f",&id,&score);
    head->id=id;
    head->score=score;
    p=head;
    while(p->id>0)
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
    p->next=head;
    return head;
}

int Find(stu *s)
{
    if(s==NULL)
    {
        printf("Linklist is empty!\n");
        return 0;
    }
    stu *p,*q;
    p=s;
    while(p->next->next!=s)
    {
        p=p->next;
    }
    q=p->next;
    p->next=s;
    free(q);
    return 1;
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
    int i=0;
    stu *head,*p;
    head=Tail();
    p=head;

    while(i<4)
    {
        i++;
        printf("%d %f\n",p->id,p->score);
        p=p->next;
    }
    Find(p->next->next);
    i=0;
    while(i<4)
    {
        i++;
        printf("%d %f\n",p->id,p->score);
        p=p->next;
    }

}
