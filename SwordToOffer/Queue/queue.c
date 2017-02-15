/*************************************************************************
	> File Name: linked_1.c
	> Author: ZhouPan / github:dreamer2018
	> Mail: zhoupans_mail@163.com
	> Blog: blog.csdn.net/it_dream_er
	> Created Time: 2016.02.07 19.06
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>


#define SQU_MAX 10
#define SQU_TYPE int

typedef struct
{
    SQU_TYPE data[SQU_MAX];
    int top;
    int length;
}Queue;

//初始化一个栈
void InitQueue(Queue **queue);
//清空队列
void ClearQueue(Queue *queue);
//插入新元素
int InsertQueue(SQU_TYPE data,Queue *queue);
//删除新元素
SQU_TYPE DeleteQueue(Queue *queue);
//返回队列长度
int QueueLength(Queue *queue);
//判空
int IsEmpty(Queue *queue);
//判满
int IsFull(Queue *queue);



//初始化一个栈
void InitQueue(Queue **queue)
{
    *queue=(Queue *)malloc(sizeof(Queue));
    (*queue)->top = -1;
    (*queue)->length = 0;
}

//清空队列
void ClearQueue(Queue *queue)
{
    queue->length=0;
}
//插入新元素
int InsertQueue(SQU_TYPE data, Queue *queue)
{
    if(IsFull(queue))
    {
        printf("队列已满！\n");
        return 0;
    }
    queue->top = (queue->top+1) % SQU_MAX;
    queue->length++;
    queue->data[queue->top]=data;
    return 1;
}

//删除新元素
SQU_TYPE DeleteQueue(Queue *queue)
{
    if(IsEmpty(queue))
    {
        printf("队列为空！\n");
        return 0;
    }
    int tail = (queue->top - queue->length + SQU_MAX + 1) % SQU_MAX;
    SQU_TYPE rtu;
    rtu = queue->data[tail];
    queue->length--;
    return rtu;
}
//返回队列长度
int QueueLength(Queue *queue)
{
    return queue->length;
}
//判空
int IsEmpty(Queue *queue)
{
    if(queue->length == 0)
    {
        return 1;
    }
    return 0;
}
//判满
int IsFull(Queue *queue)
{
    if(queue->length == SQU_MAX)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int i;
    Queue *queue;
    InitQueue(&queue);
    InsertQueue(100,queue);
    printf("%d\n",queue->data[queue->top]);
    for(i=10;i<100;i++)
    {
        printf("%d",i);
        if(!InsertQueue(i,queue))
        {
            break;
        }
    }
    for(i=0;i<5;i++)
    {
        printf("%d",i);
        if(!DeleteQueue(queue))
        {
            break;
        }
    }
    printf("%d\n",queue->top);
}
