/*************************************************************************
	> File Name: test_address.c
	> Author: ZhouPan / github:dreamer2018 
	> Blog: blog.csdn.net/it_dream_er 
	> Mail: zhoupans_mail@163.com 
	> Created Time: Tue 04 Aug 2015 08:45:22 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    char buffer[32];
    int ret=0;
    int host=0;
    int network=0;
    unsigned int address=0;
    
    struct in_addr in;
    in.s_addr=0;

    printf("请输入你的ip地址：");
    fgets(buffer,31,stdin);
    buffer[31]='\0';

    if(!(ret=inet_aton(buffer,&in)))
    {
        printf("inet_aton:\t invalid address\n");
    }
    else
    {
        printf("inet_aton:\t0x%x\n",in.s_addr);
    }

    if((address=inet_addr(buffer))==-1)
    {
        printf("inet_aton:\t invalid address\n");
    }
    else
    {
        printf("inet_aton:0x%x",address);
    }

    if((address=inet_network(buffer))==-1)
    {
        printf("inet_aton:\t invalid address\n");
    }
    else
    {  
        printf("inet_aton:0x%x",address);
    }

    if(inet_ntoa(in)==NULL)
    {
        printf("inet_aton:\t invalid address\n");
    }
    else
    {
        printf("inet_aton:\t%s\n",inet_ntoa(in));
    }
}
