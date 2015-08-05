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

struct user
{
    char name[40];
    char password[40];
};

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
            if(!strcmp(users[i].name,name))
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
    char recv_buf[BUFMAX];

    //创建一个TCP 套接字
    sock_fd=socket(AF_INET,SOCK_STREAM,0);
    if(sock_fd<0)
    {
        perror("socket");
    }

    //设置该套接字使之可以重新绑定
    optval=1;
    
    //len=sizeof(optval);
    if(setsockopt(sock_fd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(int))<0)
    {
        perror("setsockopt");
    }
    
    //初始化本地端
    memset(&srv_sock,0,sizeof(struct sockaddr_in ));
    
    srv_sock.sin_family=AF_INET;
    srv_sock.sin_port=htons(SERV_PORT);
    srv_sock.sin_addr.s_addr=htonl(INADDR_ANY);
   
   /*memset(sock.sin_zero,0,sizeof(sock.sin_zero));
    conn_fd=connect(sock_fd,(struct sockaddr *)&srv_sock,sizeof(struct sockaddr_in));
    if(conn_fd<0)
    {
        perror("connect");
    }
    */
    
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
                    printf("switch %d",switch_num);
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
                        send_data(conn_fd,"y\n");
                        send_data(conn_fd,"welcome login my TCP service\n");
                        printf("%s login\n",users[switch_num].name);
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
