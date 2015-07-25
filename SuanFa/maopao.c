#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
#define List_Init(list,list_node_t){                     \
    list=(list_node_t *)malloc(sizeof(list_node_t));    \
    list->next=NULL;                                    \
}
#define List_AddHead(list,newNode){      \
    newNode->next=list->next;           \
    list->next=newNode;                 \
}
typedef struct str_sort
{
    char str[256];
    struct str_sort *next;
}str_node_t;
void sort()
{
    int i=0,j;
    char temp[256];
    str_node_t *newNode,*head,*p;
    List_Init(head,str_node_t);
    while(i<MAX)
    {
        i++;
        newNode=(str_node_t *)malloc(sizeof(str_node_t));
        scanf("%s",newNode->str);
        getchar();
        List_AddHead(head,newNode);
    }
    p=head->next;
    i=0;
    while(i<MAX)
    {
        i++;
        printf("%s\n",p->str);
        p=p->next;
    }
    for(i=1;i<=MAX;i++)
    {
        p=head->next;
        for(j=1;j<MAX;j++)
        {
            if(strcmp(p->str,p->next->str)>0)
            {
                strcpy(temp,p->str);
                strcpy(p->str,p->next->str);
                strcpy(p->next->str,temp);
            }
            p=p->next;
        }
    }
    i=0;
    p=head->next;
    while(i<MAX)
    {
        i++;
        printf("%s",p->str);
        p=p->next;
    }
}
void main()
{
    sort();
}
