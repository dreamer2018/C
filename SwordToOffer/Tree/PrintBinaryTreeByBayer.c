/*************************************************************************
	> File Name: PrintBinaryTreeByBayer.c
	> Author:  ZhouPan
	> GitHub:  https://github.com/dreamer2018
	> Mail:  zhoupan@xiyoulinux.org
	> Blog:  http://blog.csdn.net/it_dream_er
	> Created Time: Mon 06 Mar 2017 03:49:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define SQU_MAX 100

//定义二叉树节点
struct BinaryTreeNode
{
    int id;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

//保存节点内容和节点高度
struct BinaryTreeWithHight
{
    int height;
    struct BinaryTreeNode *data;
};

//队列结构体
typedef struct
{
    struct BinaryTreeWithHight *data[SQU_MAX];
    int top;
    int length;
}Queue;

//创建二叉树
struct BinaryTreeNode* createBinaryTree()
{
    int id;
    scanf("%d",&id);
    if (id == 0)
    {
        return NULL;
    }
    struct BinaryTreeNode *root;
    root=(struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    root->id=id;
    root->left = createBinaryTree();
    root->right = createBinaryTree();
    return root;
}

//先序遍历二叉树
void printBinaryTreeFirst(struct BinaryTreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\t\n",root->id);
    printBinaryTreeFirst(root->left);
    printBinaryTreeFirst(root->right);
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


//入队列
int InsertQueue(struct BinaryTreeWithHight *data, Queue *queue)
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

//出队列
struct BinaryTreeWithHight *DeleteQueue(Queue *queue)
{
    if(IsEmpty(queue))
    {
        printf("队列为空！\n");
        return NULL;
    }
    int tail = (queue->top - queue->length + SQU_MAX + 1) % SQU_MAX;
    struct BinaryTreeWithHight *rtu;
    rtu = queue->data[tail];
    queue->length--;
    return rtu;
}

//按层遍历
int PrintBinaryTreeByBayer(struct BinaryTreeNode*root, Queue *queue)
{
    if(root == NULL)
    {
        return -1;
    }

    //队列层数或高度
    int curr_hight=1;

    struct BinaryTreeWithHight *data;
    data = (struct BinaryTreeWithHight *)malloc(sizeof(struct BinaryTreeWithHight));
    data->data=root;
    data->height=curr_hight;

    //将根结点入队列
    InsertQueue(data,queue);

    while(!IsEmpty(queue))
    {
        struct BinaryTreeWithHight *tmp;

        //将根队列出栈
        tmp = DeleteQueue(queue);

        //如果遍历到新的层，则先回车再输出
        if(tmp->height > curr_hight)
        {
            curr_hight++;
            printf("\n");
        }
        //输出
        printf("%d\t", tmp->data->id);

        //如果左子树不为空
        if(tmp->data->left != NULL)
        {

            //入队列
            struct BinaryTreeWithHight *left;
            left = (struct BinaryTreeWithHight *)malloc(sizeof(struct BinaryTreeWithHight));
            left->height=tmp->height+1;
            left->data = tmp->data->left;
            InsertQueue(left,queue);
        }
        //如果右子树不为空
        if(tmp->data->right != NULL)
        {
            //入队列
            struct BinaryTreeWithHight *right;
            right = (struct BinaryTreeWithHight *)malloc(sizeof(struct BinaryTreeWithHight));
            right->height = tmp->height+1;
            right->data = tmp->data->right;
            InsertQueue(right, queue);
        }
    }
    return 0;
}

//初始化队列
void InitQueue(Queue **queue)
{
    *queue=(Queue *)malloc(sizeof(Queue));
    (*queue)->top = -1;
    (*queue)->length = 0;
}

int main()
{
    struct BinaryTreeNode *root;
    root = createBinaryTree();
    printBinaryTreeFirst(root);
    Queue *queue;
    InitQueue(&queue);
    PrintBinaryTreeByBayer(root,queue);
    printf("\n");
}
