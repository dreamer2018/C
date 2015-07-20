/*
void Input()//录入影片信息函数
{
	int test;
	struct Movie *p,*Old,*New;
	if(head!=NULL)
	{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		for(test=0;;test++)
		{
			New=(struct Movie *)malloc(sizeof(struct Movie));
			printf("=====================================================================\n");
			printf("请输入影片名：");
			scanf("%s",New->Movie_name);
			printf("请输入导演名：");
			scanf("%s",New->Director_name);
			printf("请输入主演名：");
			scanf("%s",New->Leading_Role_name);
			printf("请输入上映时间【年月日之间用空格隔开】:");
			scanf("%d%d%d",&New->Show_date.year,&New->Show_date.month,&New->Show_date.day);
			printf("请输入影片的国籍所代表的序号【1.中国2.欧美3.日韩4.其他】：");
			scanf("%d",&New->National);
			printf("请输入影片内容的类型【1.爱情2.动作3.剧情4.文艺5.喜剧6.惊悚】：");
			scanf("%d",&New->Type);
			New->Room=count%10+1;     //影片影厅由系统自动初始给定，可以到影厅管理下修改
			printf("请输入影片的制作类型【2D,3D,IMAX】：");
			scanf("%s",New->Movie_Type);
			printf("请输入每张票的价格：");
			scanf("%f",&New->Price);
			printf("=====================================================================\n");
			if(Test(New->Movie_name)!=0)
			{
				if(strcmp(New->Movie_name,"0")==0)
					break;
				else
				{
					New->next=NULL;
					p->next=New;
					p=New;
					count++;
				}
			}
			else
			{
					printf("影片重复，录入失败,请重新录入\n");
					test--;
					continue;
			}
		}
	}
	else
	{
		test=0;
		New=(struct Movie *)malloc(sizeof(struct Movie));
		printf("=====================================================================\n");
		printf("请输入影片名：");
		scanf("%s",New->Movie_name);
		printf("请输入导演名：");
		scanf("%s",New->Director_name);
		printf("请输入主演名：");
		scanf("%s",New->Leading_Role_name);
		printf("请输入上映时间【年月日之间用空格隔开】:");
		scanf("%d%d%d",&New->Show_date.year,&New->Show_date.month,&New->Show_date.day);
		printf("请输入影片的国籍所代表的序号【1.中国2.欧美3.日韩4.其他】：");
		scanf("%d",&New->National);
		printf("请输入影片内容的类型【1.爱情2.动作3.剧情4.文艺5.喜剧6.惊悚】：");
		scanf("%d",&New->Type);
		New->Room=count%10;
		printf("请输入影片的制作类型【2D,3D,IMAX】：");
		scanf("%s",New->Movie_Type);
		printf("请输入每张票的价格：");
		scanf("%f",&New->Price);
		printf("=====================================================================\n");
		while(strcmp(New->Movie_name,"0")!=0)
		{
			test++;
			count++;
			if(count==1)
			{
				New->next =NULL;
				Old=New;
				head=New;
			}
			else
			{
				New->next=NULL;
				Old->next=New;
				Old=New;
			}
			New=(struct Movie *)malloc(sizeof(struct Movie));
			while(1)
			{
				printf("=====================================================================\n");
				printf("请输入影片名：");
				scanf("%s",New->Movie_name);
				printf("请输入导演名：");
				scanf("%s",New->Director_name);
				printf("请输入主演名：");
				scanf("%s",New->Leading_Role_name);
				printf("请输入上映时间【年月日之间用空格隔开】:");
				scanf("%d%d%d",&New->Show_date.year,&New->Show_date.month,&New->Show_date.day);
				printf("请输入影片的国籍所代表的序号【1.中国2.欧美3.日韩4.其他】：");
				scanf("%d",&New->National);
				printf("请输入影片内容的类型【1.爱情2.动作3.剧情4.文艺5.喜剧6.惊悚】：");
				scanf("%d",&New->Type);
				New->Room=count%10;
				printf("请输入影片的制作类型【2D,3D,IMAX】：");
				scanf("%s",New->Movie_Type);
				printf("请输入每张票的价格：");
				scanf("%f",&New->Price);
				printf("====================================================================\n");
				if(Test(New->Movie_name)!=0)
					break;
				else
					printf("影片重复，录入失败，请重新输入！\n");
			}
		}
	}
	free(New);
	printf("%d条信息录入成功！\n",test);
}
*/
void Input()
{
	int i=0;
    struct Movie *New;
	while(1)
	{
		New=(struct Movie *)malloc(sizeof(struct Movie));
		printf("=====================================================================\n");
		printf("请输入影片名：");
		scanf("%s",New->Movie_name);
		printf("请输入导演名：");
		scanf("%s",New->Director_name);
		printf("请输入主演名：");
		scanf("%s",New->Leading_Role_name);
		printf("请输入上映时间【年月日之间用空格隔开】:");
		scanf("%d%d%d",&New->Show_date.year,&New->Show_date.month,&New->Show_date.day);
		printf("请输入影片的国籍所代表的序号【1.中国2.欧美3.日韩4.其他】：");
		scanf("%d",&New->National);
		printf("请输入影片内容的类型【1.爱情2.动作3.剧情4.文艺5.喜剧6.惊悚】：");
		scanf("%d",&New->Type);
		New->Room=count%10+1;     //影片影厅由系统自动初始给定，可以到影厅管理下修改
		printf("请输入影片的制作类型【2D,3D,IMAX】：");
		scanf("%s",New->Movie_Type);
		printf("请输入每张票的价格：");
		scanf("%f",&New->Price);
		getchar();
		printf("=====================================================================\n");
        if(0==strcmp(New->Movie_name,"0"))
        {
            free(New);
            break;
        }
        New->next=head;
        head=New;
        count++;
		i++;
    }
    printf("%d条信息录入成功,正在保存数据，请稍候.......\n",i);Sleep(2000);
}
void Delete()//删 除电影信息函数，通过影片名定位影片位置，然后删除影片信息
{
    if(head==NULL)
		printf("信息为空!\n");
	else
	{
		int j,judge=0;
		char movie_name[30];
		struct Movie *p1=NULL,*p2=NULL;
		p2=head;
		p1=p2;
		printf(" 请输入你要删除的电影的电影名：");
		scanf("%s",movie_name);
		if(strcmp(movie_name,head->Movie_name)==0)
		{
			head=head->next;
			count--;
			printf("删除成功！\n");
		}
		else
		{
			while(p2!=NULL)
			{
				if(strcmp(movie_name,p2->Movie_name)==0)
				{
					judge=1;
					break;
				}
				p1=p2;
				p2=p2->next;
			}
			if(judge==1)
			{
				if(count==1)
					head=NULL;
				else
					p1->next=p2->next;
				count--;
				printf("删除成功！\n");
			}
			else
				printf("Not Found:%s\n",movie_name);
		} struct Movie *p;
	}
	printf("Press Any Key To Continue.......\n");
	getch();
}
void Change_Movieinfo()//更改函数，通过影片名定位影片位置，然后提供了一系列的方法，有单个更改影片信息，也提供重置影片信息
{
	if(head==NULL)
		printf("信息为空!\n");
	else
	{
		int num,test,j,i=1,judge=0;
		char movie_name[30];
		struct Movie *p;
		p=head;
		printf(" 请输入你要修改的电影的电影名：");
		scanf("%s",movie_name);
		if(Test(movie_name)==0)
			judge=1;
		if(judge==1)
		{
			while(strcmp(movie_name,p->Movie_name)!=0)
				p=p->next;
			Print(p,i);
			do
			{
				test=0;
				printf("************************************************************\n");
				printf("********************** 影片信息修改 ************************\n");
				printf("************************************************************\n");
			    printf("****************                        ********************\n");
				printf("****************  **0.影片名修改        ********************\n");
				printf("****************  **1.影片导演修改      ********************\n");
				printf("****************  **2.影片主演修改      ********************\n");
				printf("****************  **3.影片上映时间修改  ********************\n");
				printf("****************  **4.影片国籍修改      ********************\n");
				printf("****************  **5.影片内容类型修改  ********************\n");
				printf("****************  **6.影片制作类型修改  ********************\n");
				printf("****************  **7.影片票价修改      ********************\n");
				printf("****************  **8.全部信息修改修改  ********************\n");
				printf("****************  **9.返回上一级        ********************\n");
				printf("****************                         ********************\n");
				printf("*************************************************************\n");
				printf("Please Input Number :");
				num=getch();
				switch(num)
				{
					case '0':printf("请输入新的影片名：");scanf("%s",p->Movie_name) ;break;
					case '1':printf("请输入新的导演名：");scanf("%s",p->Director_name);break;
					case '2':printf("请输入新的主演名：");scanf("%s",p->Leading_Role_name);break;
					case '3':printf("请输入新的上映时间【年月日之间用空格隔开】:");scanf("%d%d%d",&p->Show_date.year,&p->Show_date.month,&p->Show_date.day);break;
					case '4':printf("请输入影片的国籍所代表的序号【1.中国2.欧美3.日韩4.其他】：");scanf("%d",&p->National);break;
					case '5':printf("请输入影片内容的类型【1.爱情2.动作3.剧情4.文艺5.喜剧6.惊悚】：");scanf("%d",&p->Type);break;
					case '6':printf("请输入影片新的的制作类型【2D,3D,IMAX】：");scanf("%s",p->Movie_Type);break;
					case '7':printf("请输入影片新的的票价：");scanf("%f",&p->Price);break;
					case '8':
						printf("请输入新的影片名：");
						scanf("%s",p->Movie_name);
						printf("请输入新的导演名：");
						scanf("%s",p->Director_name);
						printf("请输入新的主演名：");
						scanf("%s",p->Leading_Role_name);
						printf("请输入新的上映时间【年月日之间用空格隔开】:");
						scanf("%d%d%d",&p->Show_date.year,&p->Show_date.month,&p->Show_date.day);
						printf("请输入影片的新的国籍【1.中国2.欧美3.日韩4.其他】：");
						scanf("%d",&p->National);
						printf("请输入影片新的内容的类型【1.爱情 2.动作 3.剧情 4.文艺 5.喜剧 6.惊悚】：");
						scanf("%d",&p->Type);
						printf("请输入影片新的制作类型【2D,3D,IMAX】：");
						scanf("%s",p->Movie_Type);
						printf("请输入新的票价:");
						scanf("%f",&p->Price);
						break;
					case '9':Movie_Manage();break;
					default : test=1;printf("输入错误，请重新输入！");
				}
			}while(test==1);
			printf("修改成功,正在保存数据，请稍候......\n");Sleep(2000);
		}
		else
			printf("Not Found:%d\n",num);
	}
	printf("Press Any Key To Continue.......");
	getch();
}
void Seek_Movie()//电影查询函数，通过电影名查询影片的信息
{
	if(head==NULL)
		printf("信息为空!\n");
	else
	{
		int i;
		char movie_name[30];
		struct Movie *p;
		p=head;
		printf(" 请输入你要查找的电影的电影名：");
		scanf("%s",movie_name);
		while(1)
		{
			if(p==NULL)
			{
				printf("Sorry,未找到 ! \n");
				break;
			}
			else
			{
				if(strcmp(p->Movie_name,movie_name)==0)
				{
					printf("********************* 你所查询的电影信息如下 ***********************\n");
					printf("影片名:%s\n",p->Movie_name);
					printf("导演名:%s\n",p->Director_name);
					printf("主演名:%s\n",p->Leading_Role_name);
					printf("上映时间:%d年%d月%d日\n",p->Show_date.year,p->Show_date.month,p->Show_date.day);
					printf("影片国籍：");National_Analyse(p->National);
					printf("内容类型:");Type_Analyse(p->Type);
					printf("放映室：%d号\n",p->Room+1);
					printf("影片类型:%s\n",p->Movie_Type);
					printf("票价：%6.2f元/张\n",p->Price);
					printf("******************************************************************\n");
					break;
				}
				else
				{
					p=p->next;
				}
			}
		}
	}
	getchar();
	printf("Press Any Key To Continue.......\n");
	getch();
}


