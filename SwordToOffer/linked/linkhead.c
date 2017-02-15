/*************************************************************************
	> File Name: linked_1.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.04 08:59
 ************************************************************************/
/*
 * 链表相关操作
 *
 */
#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int id;
    float score;
    struct Student *next;
};

//链表的创建(头插法)
struct Student* createLinkInHead();
//链表的创建（尾插法）
struct Student* createLinkInTail();
//链表的插入
int insertIntoLink(int point,int id,float score, struct Student *head);
//链表的删除
int deleteFromLink(int id, struct Student **head);
//链表的输出
void printLink(struct Student *head);
//链表的逆序
void reservedLink(struct Student **head);



//链表的输出
void printLink(struct Student *head)
{
    struct Student *p;
    p=head;
    while(p != NULL)
    {
        printf("%d\t\t%f\n",p->id,p->score);
        p = p->next;
    }
}
//逆序输出
void printReserve(struct Student *p)
{
    if(p != NULL)
    {
        printReserve(p->next);
        printf("%d\t\t%f\n",p->id,p->score);
    }
}
//链表的创建(头插法)
struct Student* createLinkInHead()
{
    int id;
    float score;
    struct Student *head=NULL,*p,*q;
    while(1)
    {
        scanf("%d %f",&id,&score);
        if(id <= 0)
        {
            break;
        }
        p = (struct Student *)malloc(sizeof(struct Student));
        p->id = id;
        p->score = score;
        if(head == NULL)
        {
            head=p;
            q=head;
        }
        else
        {
            q->next = p;
            q = p;
        }
    }
    return head;
}
//链表的创建（尾插法）
struct Student* createLinkInTail()
{
    int id;
    float score;
    struct Student *head,*p,*q;
    head = (struct Student *)malloc(sizeof(struct Student));
    head->next=NULL;
    while(1)
    {
        scanf("%d %f",&id,&score);
        if(id <= 0)
        {
            break;
        }
        p = (struct Student *)malloc(sizeof(struct Student));
        p->id = id;
        p->score = score;
        q = head->next;
        head->next = p;
        p->next = q;
    }
    return head;
}

//链表的插入
int insertIntoLink(int point,int id,float score, struct Student *head)
{
    struct Student *p,*q,*n;
    p=head;
    while(p!=NULL)
    {
        if(p->id == point)
        {
            q=p->next;
            n=(struct Student *)malloc(sizeof(struct Student));
            n->id = id;
            n->score = score;
            p->next = n;
            n->next = q;
            return 1;
        }
        p=p->next;
    }
    return 0;
}

//链表的逆序
void reservedLink(struct Student **head)
{
    if(*head == NULL)
    {
        return;
    }
    struct Student *p,*q,*r;
    p=*head;
    q = p->next;
    p->next = NULL;
    while(q!=NULL)
    {
        r=q->next;
        q->next = p;
        p=q;
        q=r;
    }
    *head = p;
}

//链表的删除
int deleteFromLink(int id, struct Student **head)
{
    struct Student *p,*q;
    p=*head;
    while(p!=NULL)
    {
        if(p->id == id && p == *head)
        {
            *head = (*head)->next;
            free(p);
            break;
        }
        else if(p->id == id)
        {
            q->next = p->next;
            free(p);
        }
        q=p;
        p=p->next;
    }
}

int main()
{
    struct Student *head;
    head = createLinkInHead();
    //head = createLinkInTail();
    //printLink(head->next);
    //insertIntoLink(2,6,120,head);
    printLink(head);
    reservedLink(&head);
    //printReserve(head);
 //   int id;
 //   scanf("%d",&id);
 //   deleteFromLink(id,&head);
    printLink(head);
}
