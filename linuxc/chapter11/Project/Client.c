/*************************************************************************
	> File Name: Client.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Wed 05 Aug 2015 04:03:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define INVALID_USERINFO 'n'    //用户信息无效
#define VALID_USERINFO 'y'      //用户信息有效
#define BUFMAX 1024

int my_recv(int conn_fd,char *data_buf,int len)  //
{
   // char buf[BUFMAX];
    int sign;
    sign=recv(conn_fd,data_buf,BUFMAX,len);
    if(sign<0)
    {
        return -1;
    }
    else if(sign==0)
    {
        return -2;
    }
    else
    {
        return sign;
    }
}
 
int get_userinfo(char *buf,int len)     //获取用户输入，存到buf中buf长度为len
{
    
}

void input_userinfo(int conn_fd,char *string) //输入用户名，通过conn_fd 发出
{

}


int main()
{
    
}

