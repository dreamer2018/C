#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Service/Struct.h"
#include"Common/List.h"
#include"View/Studio_UI.h"
#include"View/Schedule_UI.h"
#include"View/Play_UI.h"
#include"View/Account_UI.h"

void Hello()//欢迎函数
{
	system("clear");
	printf("\t\t\033[34m*************************************************************\n");
	printf("\t\t*************************************************************\n");
	printf("\t\t********++++++++++++++++++++++++++++++++++++++++++***********\n");
	printf("\t\t********+     **欢迎使用影院票务管理系统V0.7**   +***********\n");
	printf("\t\t********+________________________________________+***********\n");
	printf("\t\t********+                                        +***********\n");
	printf("\t\t********+    作者：周攀     时间:2015.07.18      +***********\n");
	printf("\t\t*************************************************************\n");
	printf("\t\t*************************************************************\n\033[0m");
	printf("\t\t系统启动成功，Press Any Key To Continue......");
	getchar();
}
int  main()
{
	char choice,i=1;
	Hello();
	do
	{
		system("clear");
		Account_Srv_InitSys();
		choice=SysLogin();
			if(choice==1)
			{
				Account_UI_MgtEntry();
			}
			else if(choice==2)
			{
				do
				{
						char sign;
						system("clear");
						printf("\n\t\t\033[36m==============================================\n");
						printf("\t\t**        A.演出厅管理                      **\n");
						printf("\t\t**        B.剧目管理                        **\n");
						printf("\t\t**        R. 返回　                         **\n");
						printf("\t\t==============================================\033[0m\n");	
						printf("Please Input :");
						scanf("%c",&sign);
						getchar();
						switch(sign)
						{
							case 'a'  : ;
							case 'A'  :		
												Studio_UI_MgtEntry();
												getchar();
												break;
							case 'B' : ;
							case 'b' :
												Play_UI_MgtEntry(1);
												getchar();
												break;
							case 'R' :
							case 'r'  :
												i=0;
												break;					
						}
				}while(i);
			}
			else if(choice==3)
			{
					Sale_UI_MgtEntry(1);
			}
	}while(1);
}
