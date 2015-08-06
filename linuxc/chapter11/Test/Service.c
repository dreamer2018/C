/*************************************************************************
	> File Name: Project.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Thu 06 Aug 2015 02:43:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<errno.h>
#include<unistd.h>

#define SREV_PORT 8080
#define LIST_MAX 10
#define BUFSIZE 1024

int main()
{
    int sock_fd;
    int conn_fd;
    int len;
    int ret;
    pid_t pid;
    char recv_buf[BUFSIZE],send_buf[BUFSIZE];
    struct sockaddr_in serv_addr,acc_addr ;
    int optval;

    if((sock_fd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket");
    }
    
    optval=1;
    
    if(setsockopt(sock_fd , SOL_SOCKET,SO_REUSEADDR , (void *)&optval ,sizeof(int))<0)
    {
        perror("setsockopt");
    }

    memset (&serv_addr , 0,sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port=htons(SREV_PORT);
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(sock_fd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in))<0)
    {
        perror("bind");
    }

    if(listen(sock_fd,LIST_MAX))
    {
        perror("listen");
    }
    while(1)
    {
        len=sizeof(struct sockaddr_in);
        if((conn_fd=accept(sock_fd,(struct sockaddr *)&acc_addr,&len))<0)
        {
            perror("accept");
        }
        
        printf("accept a new client ,ip :%s \n",inet_ntoa(acc_addr.sin_addr));
        
        if((pid=fork())==0)
        {
            while(1)
            {
                if(ret=recv(conn_fd,recv_buf,sizeof(recv_buf),0))
                {
                    perror("recv");
                }
                printf("Service receive :%s",recv_buf);
                strcpy(send_buf,"hello");
                if(send(conn_fd,send_buf,strlen(send_buf),0)<0)
                {
                    perror("send");
                }
                break;
            }
        }
    }
    
}

