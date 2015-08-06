/*************************************************************************
	> File Name: Client.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Thu 06 Aug 2015 03:48:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>

#define BUFSIZE 1024
int main()
{
    int conn_fd;
    char recv_buf[1024],send_buf[1024]="Hello world";
    struct sockaddr_in serv_addr;

    memset(&serv_addr,0,sizeof(struct sockaddr_in));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(8080);
    serv_addr.sin_addr.s_addr=inet_aton("127.0.0.1",&serv_addr.sin_addr);
    
    if((conn_fd=socket(AF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket");
    }

    if((conn_fd=connect(conn_fd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in)))<0)
    {
        perror("connect");
    }
    
    if((recv(conn_fd,recv_buf,BUFSIZE,0))<0)
    {
        perror("recv");
    }
    printf(" receive : %s",recv_buf);

    if(send(conn_fd,send_buf,BUFSIZE,0))
    {
        perror("send");
    }
}
