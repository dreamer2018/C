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

#define SERV_PORT 8080
#define MAX_LIST 10
#define USERNAME 0
#define PASSWORD 1
#define BUFMAX 1024

int main()
{
    int sock_fd;
    int conn_fd;
    int optval;
    int srv_len,clt_len;
    int ret;
    int flag_recv=0;
    int switch_num;
    pid_t pid;
    struct sockaddr_in srv_sock,clt_sock;
    char recv_buf[BUFMAX];
    
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

    srv_len=sizeof(struct sockaddr_in);
    
    FD_ZERO(&readfds);
    FD_SET(sock_fd,&readfds);
    while(1)
    {
        char buf[256];
        int fd;
        int nread;
        
        testfds=readfds;
        
        printf("service waiting\n");
        ret=select(FD_SETSIZE , &testfds ,(fd_set *)0,(fd_set *)0,(struct timeval *)0);
        if(ret<0)
        {
            perror("select");
        }
        
        for(fd=0;fd<FD_SETSIZE;fd++)
        {
            if(FD_ISSET(fd,&testfds))
            {
                if(fd==sock_fd)
                {
                    clt_len=sizeof(struct sockaddr_in);
                    conn_fd=accept(sock_fd,(struct sockaddr *)&clt_sock,&clt_len);
                    FD_SET(conn_fd,&readfds);
                    printf("adding client on fd %d\n",conn_fd);
                }
                else
                {
                    memset(buf,0,sizeof(buf));
                    nread = recv(fd,buf,sizeof(buf),0);
                    
                    if(nread==0)
                    {
                        close(fd);
                        FD_CLR(fd,&readfds);
                        printf("removeing clinet on fd %d\n",fd);
                    }
                    else
                    {
                        printf("recv = %s",buf);
                    }
                }
            }
        }
    }
}
