/*************************************************************************
	> File Name: link.c
	> Author: ZhouPan / github: dreamer2018
	> Mail: zhoupans_mail@163.com
	> Created Time: Tue 10 May 2016 11:51:41 AM
    > Function:
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
    int id;
    char name[20];
    int age;
    struct student *next;
};

struct student *create()
{
    int t_id,t_age;
    char t_name[20];
    scanf("%d %s %d",&t_id,t_name,&t_age);
    if(t_id == 0)
    {
        return NULL;
    }
    struct student *p,*head=NULL;
    p=(struct student *)malloc(sizeof(struct student));
    p->id=t_id;
    strcpy(p->name,t_name);
    p->age=t_age;
    head=p;
    p->next=NULL;
    while(1)
    {
        scanf("%d %s %d",&t_id,t_name,&t_age);
        if(t_id == 0)
        {
            break;
        }
        struct student *q;
        q=(struct student *)malloc(sizeof(struct student));
        q->id=t_id;
        strcpy(q->name,t_name);
        q->age=t_age;
        q->next=p->next;
        p->next=q;
        p=q;
    }
    return head;
}
struct student * delete(struct student *head,int sign)
{
    struct student *p;
    p=head;
    while(p != NULL)
    {
        printf("%d %s %d\n",p->id,p->name,p->age);
        p=p->next;
    }
}
void print(struct student *head)
{
    struct student *p,*head=NULL;
    head=create();
    p=head;
    while(p != NULL)
    {
        printf("%d %s %d\n",p->id,p->name,p->age);
        p=p->next;
    }
}
int main()
{
    struct student *p,*head=NULL;
    head=create();
    p=head;
    while(p != NULL)
    {
        printf("%d %s %d\n",p->id,p->name,p->age);
        p=p->next;
    }
    return 0;
}
