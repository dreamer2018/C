#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Sleep(x) sleep(x/1000);
int count=0;               //计数，用于计算影片的总数
struct Movie *head=NULL;   //链表头指针
void Movie_Manage();
int Room_Array[10][6][8];//数组第一维代表影厅数，第二维代表影厅有六横排，三维代表有八竖排

//函数声明部分+++++++++++++++++++++++++++++++++++++++++

int Test(char *a);
int National_Select_Function(int test);
int Type_Select_Function(int test);
void Account_Select();	//用户账户选择
void Manage_Select();	//管理员选择
void Movie_Manage();
void Room_Select();
void Customer_Select();
void Type_Select();
void National_Select();
void Print(struct Movie *p,int i);
char getch();
char getche();
void Seat_Look(int i);//座位查看

//××××××××××××××××××××  自定义文件
#include"struct.h"            //结构体文件
#include"./movie/movie.h"
#include"./passwd/Password.h" //密码验证函a数实现文件
#include"./system/clear.h"    //清屏函数实现文件
#include"data.h"
#include"./movie/movie_linked.h"
#include"./book_system/book.h"
#include"./seat_manage/seat_manage.h"

//      int Room_Array[10][6][8];//数组第一维代表影厅数，第二维代表影厅有六横排，三维代表有八竖排



//函数实现部分
void Hello()//欢迎函数
{
	printf("*************************************************************\n");Sleep(1000);
	printf("*************************************************************\n");Sleep(1000);
	printf("********++++++++++++++++++++++++++++++++++++++++++***********\n");Sleep(1000);
	printf("********+     **欢迎使用影院管理系统V0.7**  	 +***********\n");Sleep(1000);
	printf("********+________________________________________+***********\n");Sleep(1000);
	printf("********+                                        +***********\n");Sleep(1000);
	printf("********+    作者：周攀     时间:2015.06.14      +***********\n");Sleep(1000);
	printf("*************************************************************\n");Sleep(1000);
	printf("*************************************************************\n");Sleep(1000);
	printf("系统启动成功，Press Any Key To Continue......");
	getch();
}
void Bye() //结束再见函数
{
	printf("\n");
	printf("*************************************************************************\n");Sleep(1000);
	printf("******     **************** ************ ******* *****          *********\n");Sleep(1000);
	printf("******  谢 **************** ************* ****** ***** ******** *********\n");Sleep(1000);
	printf("******  谢 **************** ************** ***** ***** ******** *********\n");Sleep(1000);
	printf("******  使 **************** ***************    * ***** ******** *********\n");Sleep(1000);
	printf("******  用 ****************         *********** ****** ***      *********\n");Sleep(1000);
	printf("******  ， **************** ******* ********** ******* ******************\n");Sleep(1000);
	printf("******  再 **************** ******* ********* ******** ******************\n");Sleep(1000);
	printf("******  见 **************** ******* ******** ********* ******************\n");Sleep(1000);
	printf("******     ****************         ******* **********          *********\n");Sleep(1000);
	printf("*************************************************************************\n");Sleep(1000);
}
void Account_Select()//用户账户选择函数
{
	int test;
	printf("***************************************************\n");
	printf("******* 你的账户类型：                      *******\n");
	printf("*******     1.管理员       2.游客           *******\n");
	printf("*******                                     *******\n");
	printf("***************************************************\n");
	while(1)
	{
		printf("Please Input Number:");
		test=getche();
		printf("\n");
		switch(test)
		{
           		case '1':if(Password()==1)
					Read();
				else
					exit(0);
				if(head==NULL) 
					Array_Clear();
				clear();
				Manage_Select();
				break;
			case '2': Read();clear();Customer_Select();break;
			default : printf("输入错误，请重新输入！\n");
		}
	}
}
void Manage_Select()//管理员管理选择函数
{
	int test;
	printf("*************************************************************\n");
	printf("**********+           ***  管 理  ***            +***********\n");
	printf("**********+======================================+***********\n");
	printf("**********+          **1. 影片管理   ***         +***********\n");
	printf("**********+          **2. 放映厅管理 ***         +***********\n");
	printf("**********+          **3. 退出系统   ***         +***********\n");
	printf("*************************************************************\n");
	while(1)
	{
		printf("Please Input Number:");
		test=getch();
		switch(test)
		{
			case '1': clear();Movie_Manage();break;
			case '2': clear();Room_Select();break;
			case '3': Bye();Write();exit(0);break;
			default : printf("输入错误，请重新输入！\n");
		}
	}
}
void Movie_Manage()//影片管理选择函数
{
	int num,test;
	printf("*************************************************************\n");
	printf("**********+           ***影片管理***             +***********\n");
	printf("**********+======================================+***********\n");
	printf("**********+            **1.录入影片信息          +***********\n");
	printf("**********+            **2.查询影片信息          +***********\n");
	printf("**********+            **3.修改影片信息          +***********\n");
	printf("**********+            **4.删除影片信息          +***********\n");
	printf("**********+            **5.显示所有影片信息      +***********\n");
	printf("**********+            **6.返回上一级            +***********\n");
	printf("**********+            **7.退出系统              +***********\n");
	printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
	printf("*************************************************************\n");
	do
	{
		test=0;
		printf("Please Input Number:");
		num=getch();
		switch(num)
		{
			case '1': clear();Input(); clear();Movie_Manage();break;
			case '2':clear(); Seek_Movie();clear();Movie_Manage();break;
			case '3': clear();Change_Movieinfo();clear();Movie_Manage();break;
			case '4':clear(); Delete();clear();Movie_Manage();break;
			case '5':clear(); Print_All(head);clear();Movie_Manage();break;
			case '6':clear(); Manage_Select();break;
			case '7': Write();clear();Bye();exit(0);break;
			default : printf("输入错误，请重新输入！\n");test=1;
		}
	}while(test==1);
}
void Room_Select()//放映厅管理选择函数
{
	int num,test;
	printf("*************************************************************\n");
	printf("**********+           ***放映厅管理***           +***********\n");
	printf("**********+=======================================+***********\n");
	printf("**********+          **1.放映厅座位管理          +***********\n");
	printf("**********+          **2.放映厅座位初始化        +***********\n");
	printf("**********+          **3.放映厅电影修改          +***********\n");
	printf("**********+          **4.返回上一级              +***********\n");
	printf("**********+          **5.退出系统                +***********\n");
	printf("*************************************************************\n");
	do
	{
		test=0;
		printf("Please Input Number :");
		num=getch();
		printf("\n");
		switch(num)
	    	{
			case '1': Seat_Manage();clear();Room_Select();clear;break;
			case '2': Array_Clear();printf("初始化完成，Press Any Key To Continue：");getchar();Room_Select();break;
			case '3':clear(); Manage_Select();break;
			case '4': clear();Bye();Write();exit(0);break;
			default : printf("输入错误，请重新输入！\n");
		}
	}while(test==1);
}
void Customer_Select()//顾客选择系统函数
{
	int num,test;
	printf("*************************************************************\n");
	printf("**********+           ***欢迎使用***             +***********\n");
	printf("**********+======================================+***********\n");
	printf("**********+            **1.最新上映              +***********\n");
	printf("**********+            **2.查看所有影片          +***********\n");
	printf("**********+            **3.搜索影片              +***********\n");
	printf("**********+            **4.按国家选              +***********\n");
	printf("**********+            **5.按类型选              +***********\n");
	printf("**********+            **6.订电影票              +***********\n");
	printf("**********+            **7.退出系统              +***********\n");
	printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
	printf("*************************************************************\n");
	do
	{
		test=0;
		printf("Please Input Number :");
		num=getch();
		switch(num)
		{
			case '1': clear();New_Look();Ask();clear();Customer_Select();break;
			case '2': clear();Print_All(head);Ask();clear();Customer_Select();break;
			case '3': clear(); Seek_Movie();clear();Customer_Select();break;
			case '4': clear();National_Select();Customer_Select();break;
			case '5': clear();Type_Select();clear();Customer_Select();break;
			case '6': clear();Book_Tickets();clear();Customer_Select();break;
			case '7': Bye();Write();exit(0);break;
			default : printf("输入错误，请重新输入！\n");test=1;
		}
	}while(test==1);
}
void Type_Select()//电影类型选择函数
{
	int num,test;
	printf("*************************************************************\n");
	printf("**********+           *** 按类选 ***             +***********\n");
	printf("**********+======================================+***********\n");
	printf("**********+            **1.爱情                  +***********\n");
	printf("**********+            **2.动作                  +***********\n");
	printf("**********+            **3.科幻                  +***********\n");
	printf("**********+            **4.剧情                  +***********\n");
	printf("**********+            **5.文艺                  +***********\n");
	printf("**********+            **6.喜剧                  +***********\n");
	printf("**********+            **7.惊悚                  +***********\n");
	printf("**********+            **8.返回上一级             +***********\n");
	printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
	printf("*************************************************************\n");
	do
	{
		test=0;
		printf("Please Input Number :");
		num=getch();
		switch(num)
		{
			case '1': ;
			case '2': ;
			case '3': ;
			case '4': ;
			case '5': ;
			case '6': ;
			case '7': if(Type_Select_Function(num-48)) Ask();break;
			case '8': clear();break;
			default : printf("输入错误，请重新输入！\n");
		}
	}while(test==1);
}
void National_Select()//电影国籍选择函数
{
	int num,test;
	printf("*************************************************************\n");
	printf("**********+           *** 按类选 ***             +***********\n");
	printf("**********+======================================+***********\n");
	printf("**********+            **1.中国                  +***********\n");
	printf("**********+            **2.欧美                  +***********\n");
	printf("**********+            **3.日韩                  +***********\n");
	printf("**********+            **4.其他                  +***********\n");
	printf("**********+            **5.返回上一级            +***********\n");
	printf("**********++++++++++++++++++++++++++++++++++++++++***********\n");
	printf("*************************************************************\n");
	do
	{
		test=0;
		printf("Please Input Number :");
		num=getch();
		switch(num)
		{
			case '1': ;
			case '2': ;
			case '3': ;
			case '4': if(National_Select_Function(num-48)) Ask();break;
			case '5': clear();break;
			default : printf("输入错误，请重新输入！\n");test=1;
		}
	}while(test==1);
}

//主函数，程序的入口
void main()
{
	clear();
	Hello();
	clear();
	Account_Select();
}

