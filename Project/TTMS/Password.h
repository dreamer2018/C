#include"../system/conio.h"    //getch和getche函数实现文件
struct passwd //密码验证结构体
{
        char name[21];
        char passwd[21];
}a;
int passwd_test(char passwd[])
{
    int i,j;
	char test;
	int d=1;
    char ch;
    for(j=1;;j++)
    {
        printf("\n请输入密码：");
        for(i=0;i<100;i++)
		{
            ch=getch();
			if(ch=='\n')
			{
				passwd[i]='\0';
				break;
			}
			passwd[i]=ch;
			putchar('*');
		}
        printf("\n");
        if(strcmp(passwd,a.passwd)==0)
        {
            printf("管理员账户登陆成功\n");
		    return 1;
        }
        else
        {
            if(j==3)
            {
                printf("密码三次输入错误，登录失败！！\n");
                return 0;
            }
            printf("登录失败，你还有%d次机会,是否重重新输入密码 y/n:",3-j);
            do{
		    	test=getche();
		        if(121==test||89==test)
		        {
		            break;
		        }
		        else if(110==test||78==test)
		        {
                    printf("登录失败！！\n");
					return 0;
		        }
		        else
		        {
		            printf("输入错误，请重新输入！！\n");
		            d=0;
            	}
			}while(0==d);
        }
    }
}
int Password()
{
    int i,c,d=1;
    char test;
    char user[101];
    char passwd[101];
	char ch;
    strcpy(a.name,"admin");
    strcpy(a.passwd,"admin123");
    for(i=1;;i++)
    {
        printf("\n请输入管理员用户名：");
        scanf("%s",user);
        if(strcmp(a.name,user)==0)
        {
            getchar();
            c=passwd_test(passwd);
            return c;
        }
        else
        {
            if(3==i)
            {
                printf("三次输入错误，登录失败！！\n`");
                return 0;
            }
            printf("用户名错误,你还有%d次机会,是否重新输入Y/n?",3-i);
            getchar();
            do{
		    	ch=getche();
		        if(121==ch||89==ch)
		        {
		            break;
		        }
		        else if(110==ch||78==ch)
		        {
                    printf("登录失败！！");
					return 0;
		        }
		        else
		        {
		            printf("输入错误，请重新输入！！\n");
		            d=0;
		        }
			}while(0==d);
        }
    }
}
