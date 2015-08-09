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
#include<sys/time.h>
#include<sys/ioctl.h>


/*
 * List为自定义的头文件，里面包含了对单向链表的操作：
 * List_Init(head,list_node_t)  单向链表初始化宏定义
 * List_AddHead(head,newNode)   单项链表头插发宏定义
*/
#include<List.h>


//宏定义

#define SERV_PORT 8080      //端口
#define MAX_LIST 10         //最长等待序列
#define BUFSIZE 1024        //缓冲区大小

/*
 *  在线用户链表  
*/

typedef struct On_Line     
{
    char name[21];    //在线的用户名
    int sock_fd;      //在线用户套接字描述符
    struct On_Line *next;
} online_node_t;

//在线用户链表头结点（全局变量）

online_node_t *head;

int main()
{

    int sock_fd;
    int conn_fd;
    int fd_count=0;
    int optval;
    int ret;
    int srv_len,clt_len;
    int fd_list[MAX_LIST];
    int flag_recv=0;
    pid_t pid;
    struct sockaddr_in srv_sock,clt_sock;
    char recv_buf[BUFSIZE];
    List_Init(head,online_node_t);
    memset(fd_list,0,MAX_LIST);  
    fd_set readfds,testfds;
    
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

    fd_list[fd_count]=sock_fd;
    srv_len=sizeof(struct sockaddr_in);
    fd_count++;
    FD_ZERO(&readfds); 
    FD_SET(sock_fd,&readfds);
    while(1)
    {
        int fd;
        int nread;
        int j;
        
        testfds=readfds;
        
        printf("service waiting\n"); 
        ret=select(MAX_LIST, &testfds ,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
        if(ret<0)
        {
            perror("select");
        }
        
        for(fd=0;fd<fd_count;fd++)
        {
            if(FD_ISSET(fd_list[fd],&testfds))  //检测出现响应的在不在在线用户链表中，不在责不进行操作，直接跳过
            {
                if(fd_list[fd]==sock_fd) //如果响应的是监听套接字，则说明是一个新的用户请求
                {
                    clt_len=sizeof(struct sockaddr_in);
                    conn_fd=accept(sock_fd,(struct sockaddr *)&clt_sock,&clt_len);
                                                //使用vfork创建一个进程，用于进行密码注册用户或登录验证
                    FD_SET(conn_fd,&readfds);  
                    fd_list[fd_count]=conn_fd;
                    fd_count++;
                    printf("adding client on fd %d\n",conn_fd);
                }
                else  //否则，表示是已在线的用户出现操作
                {
                    memset(recv_buf,0,sizeof(recv_buf));  //每次先将缓冲区清空
                    nread = recv(fd_list[fd],recv_buf,sizeof(recv_buf),0); //接受用户发送来的数据
                    if(nread==0) //如果数据长度为零，则表示用户离开
                    {
                        close(fd_list[fd]);                
                        FD_CLR(fd_list[fd],&readfds);
                        printf("removeing clinet on fd %d\n",fd);
                        if(fd!=fd_count)
                        {
                            for(j=fd;j<fd_count-1;j++)
                            {
                                fd_list[j]=fd_list[j+1];
                            }
                        }
                        fd_count--;
                    }
                    else 
                    {
                        if((pid=fork())==0)  //创建一个新的进程，用于处理用户发来的信息，解析并转发给其他用户
                        {
                            printf("Tets fd_count=%d\n",fd_count);
                            for(j=1;j<fd_count;j++)
                            {
                                if (fd_list[fd] == fd_list[j])
                                    continue;
                                printf("send test %d\n",j);
                                if(send(fd_list[j],recv_buf,sizeof(recv_buf),0)<0)
                                {
                                    perror("send");
                                }
                            }
                            exit(0);
                        }
                        //printf("recv = %s",recv_buf);
                    }
                }
            }
        }
    }
}
