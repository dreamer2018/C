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
        printf("inet_addr:\t invalid address\n");
    }
    else
    {
        printf("inet_addr:\t0x%x\n",address);
    }

    if((address=inet_network(buffer))==-1)
    {
        printf("inet_network:\t invalid address\n");
    }
    else
    {  
        printf("inet_network:\t0x%x\n",address);
    }

    if(inet_ntoa(in)==NULL)
    {
        printf("inet_ntoa:\t invalid address\n");
    }
    else
    {
        printf("inet_ntoa:\t%s\n",inet_ntoa(in));
    }
    
    host=inet_lnaof(in);
    network=inet_netof(in);
    printf("inet_lnaof:\t0x%x\n",host);
    printf("inet_netof:\t0x%x\n",network);

    in=inet_makeaddr(network,host);
    printf("inet_makeaddr:\t0x%x\n",in.s_addr);

    return 0;

}
