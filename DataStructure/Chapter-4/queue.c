#include <stdio.h>
#include <stdlib.h>

struct node{
		char data;
		struct node *nextnode;
	};
typedef struct node Node;
typedef Node *NextNode;

 void enqueue(NextNode *head,NextNode *tail,char c)
{
	NextNode new=malloc(sizeof(Node));
	new->data=c;
	new->nextnode=NULL;
	
	if(*head==NULL)
	{
		*head=new;
	}
	else
	{
		(*tail)->nextnode=new;
	}
	(*tail)=new;

}

void dequeue(NextNode *head,NextNode *tail)
{
	NextNode temp;
	temp=*head;
	*head=(*head)->nextnode;
	if(*head==NULL)
	{
		*tail=NULL;
	}
	free(temp);
}

void printlist(NextNode current)
{
	if(current==NULL)
	{
		printf("List is empty");
	}
	else
	{	
		puts("The list is:\n");
		while(current!=NULL)
		{
			printf("%c-->",current->data);
			current=current->nextnode;
		}
		puts("NULL\n");
	}
}
	
void main ()
{
	NextNode head=NULL;
	NextNode tail=NULL;
	int choice;
	char value;
	printf("1. Enter 1 to insert data\n2. Enter 2 to Delete data\n3. Enter 3 to end\n");
	scanf("%d",&choice);
	while(choice!=3)
	{
		switch(choice)
		{
			case 1:
				printf("Enter the character");
				scanf("\n%c",&value);
				enqueue(&head,&tail,value);
				break;
			case 2:
				if(head!=NULL)
					{
						dequeue(&head,&tail);
					}
				else
					{
						printf("List is empty");
					}
					break;
			case 3:
				break;
			default:
				printf("Don't try to be oversmart");
				break;
		}
		printf("1. Enter 1 to insert data\n2. Enter 2 to Delete data\n3. Enter 3 to end\n");
	scanf("%d",&choice);
	}
	printlist(head);
}
