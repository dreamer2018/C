#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int id;
    float score;
    struct student *next;
    struct student *pre;
}stu;
void Head()
{
    int a;
    float b;
    stu *New,*Old,*head,*p,*end;
    New=Old=(stu *)malloc(sizeof(stu));
    printf("Please Input:");
    scanf("%d %f",&a,&b);
    getchar();
    if(0!=a)
    {
        New->id=a;
        New->score=b;
        New->next=NULL;
        end=New;
    }
    while(Old->id!=0)
    {
        New=(stu *)malloc(sizeof(stu));
        printf("Please Input:");
        scanf("%d %f",&a,&b);
        getchar();
        if(a!=0)
        {
            New->id=a;
            New->score=b;
            head=New;
            New->next=Old;
            Old->pre=New;
            Old=New;
        }
        else
        {
            free(New);
            break;
        }
    }
    p=end;
   // p=head;
    while(p!=NULL)
    {
        printf("id :%d\t",p->id);
        printf("score:%0.2f\n",p->score);
       // p=p->next;
        p=p->pre;
    }
}
void Tail()
{
    int a;
    float b;
    stu *New,*Old,*head,*p,*end;
    New=Old=(stu *)malloc(sizeof(stu));
    printf("Please Input:");
    scanf("%d %f",&a,&b);
    getchar();
    if(0!=a)
    {
        head=New;
        New->id=a;
        New->score=b;
        New->pre=NULL;
    }
    while(Old->id!=0)
    {
        New=(stu *)malloc(sizeof(stu));
        printf("Please Input:");
        scanf("%d %f",&a,&b);
        getchar();
        if(a!=0)
        {
            New->id=a;
            New->score=b;
            Old->next=New;
            New->pre=Old;
            New->next=NULL;
            Old=New;
        }
        else
        {
            end=Old;
            free(New);
            break;
        }
    }
    p=end;
    while(p!=NULL)
    {
        printf("id :%d\t",p->id);
        printf("score:%0.2f\n",p->score);
        p=p->pre;
    }
}
void main()
{
   Head();
   //Tail();
}
