/*************************************************************************
	> File Name: Service.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Wed 05 Aug 2015 10:21:26 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<error.h>

#define SERV_PORT 8080
#define MAX_LIST 10
#define USERNAME 0
#define PASSWORD 1
#define BUFMAX 1024
#define INYALLD_USERINFO 'n'
#define VALID_USERINFO 'y'

//链表头插法初始化


#define List_Init(list,list_node_t){                    \
    list=(list_node_t *)malloc(sizeof(list_node_t));    \
    list->next=NULL;                                    \
} 

//链表头插法宏定义

#define List_AddHead(list,newNode){         \
    newNode->next=list->next;               \
    list->next=newNode;                     \
}

//用户信息结构体
struct user
{
    char name[40];
    char password[40];
};

//上线用户信息保存

typedef struct online
{
    char username[40];
    int sock_fd;
    struct online *next;
} online_node_t;

online_node_t *online_head;

//创建用户在线信息的单向链表


//链表初始化


struct user users[]={{"admin","admin"},{"guest","guest"},{" "," "}};

int find_name(char *name) //出错返回-2，找不到用户名返回-1，找到返回下标
{
    int i;

    if(name==NULL)
    {
        printf("用户名无效！\n");
        return -2;
    }
    else
    {
        for(i=0;users[i].name[0]!=' ';i++)
        {

            {
                return i;
            }
        }
        return -1;
    }
}

void send_data(int conn_fd,char *string)
{

    if(send(conn_fd,string,strlen(string),0)<0)
    {
        perror("send");
    }       
}

void send_data_to(char *string)
{
    online_node_t *p;
    p=online_head->next;
    while(p!=NULL)
    {
        send_data(p->sock_fd,string);
        p=p->next;
    }
}

void On_Info_Add(char *str,int sock_fd)
{
    online_node_t *p;
    p=(online_node_t *)malloc(sizeof(online_node_t));
    strcpy(p->username,str);
    p->sock_fd=sock_fd;
    printf("Test_1:%s %d\n",p->username,p->sock_fd);
    //List_AddHead(online_head,p);         
    p->next=online_head->next;               
    printf("test__\n");
    online_head->next=p;                     
    printf("Test_2:%s %d\n",p->username,p->sock_fd);
}
int main()
{
    int sock_fd;
    int conn_fd;
    int optval;
    int len;
    int ret;
    int flag_recv=0;
    int switch_num;
    pid_t pid;
    struct sockaddr_in srv_sock,clt_sock;
    online_node_t *p; 
    List_Init(p,online_node_t);
    char recv_buf[BUFMAX];

    //创建一个TCP 套接字
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd<0)
    {
        perror("socket");
    }

    //设置该套接字使之可以重新绑定
    optval=1;
    
    if(setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int))<0)
    {
        perror("setsockopt");
    }
    
    //初始化本地端
    memset(&srv_sock,0,sizeof(struct sockaddr_in ));
    
    srv_sock.sin_family=AF_INET;
    srv_sock.sin_port=htons(SERV_PORT);
    srv_sock.sin_addr.s_addr=htonl(INADDR_ANY);
    
    //绑定套接字到本地端
    if(bind(sock_fd,(struct sockaddr *)&srv_sock,sizeof(struct sockaddr_in ))<0)
    {
        perror("bind");
    }
    
    //设置监听
    if(listen(sock_fd,MAX_LIST)<0)
    {
        perror("listen");
    }

    len=sizeof(struct sockaddr_in);

    while(1)
    {
        //通过accept接受客户端连接请求，返回套接字用于收发数据
        conn_fd=accept(sock_fd,(struct sockaddr *)&clt_sock,&len);
        if(conn_fd<0)
        {
            perror("accept");
        }
        printf("accept a new client ip: %s \n",inet_ntoa(clt_sock.sin_addr));
        
        
        
        //创建一个子进程用于接受客户端连接请求
        if((pid=fork())==0)
        {
            while(1)
            {
                if((ret=recv(conn_fd,recv_buf,sizeof(recv_buf),0))<0)
                {
                    perror("recv");
                    exit(1);
                }
                recv_buf[ret-1]='\0';
                
                if(flag_recv==USERNAME)
                {
                    switch_num=find_name(recv_buf);
                    
                    switch(switch_num)
                    {
                        case -1:
                            send_data(conn_fd,"n\n");
                            break;
                        case -2:
                            exit(1);
                            break;
                        default:
                            send_data(conn_fd,"y\n");
                            flag_recv=PASSWORD;
                            break;
                    }
                }
                else if(flag_recv==PASSWORD)
                {
                    if(!strcmp(users[switch_num].name,recv_buf))
                    {
                        //On_Info_Add(users[switch_num].name,conn_fd);
                        p=(online_node_t *)malloc(sizeof(online_node_t));
                        strcpy(p->username,users[switch_num].name);
                        p->sock_fd=conn_fd;
                        //List_AddHead(online_head,p);
                        send_data(conn_fd,"y\n");
                        send_data(conn_fd,"welcome login my TCP service\n");
                        printf("%s login\n",users[switch_num].name);
                        //On_Info_Add(users[switch_num].name,conn_fd);
                        break;
                    }
                    else
                    {
                        send_data(conn_fd,"n\n");
                    }
                }
            }
            close(sock_fd);
            close(conn_fd);
            exit(0);
        }
        else
        {
            close(conn_fd);
        }
    }
    return 0;
}
