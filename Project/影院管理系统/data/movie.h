
void National_Analyse(int a)//国籍解析函数，通过用户输入数字，解析出对应的国籍信息；
{
	switch(a)
	{
		case 1:printf("中国\n");break;
		case 2:printf("欧美\n");break;
		case 3:printf("日韩\n");break;
		case 4:printf("其他\n");break;
		default :printf("Error\n");
	}
}
void Type_Analyse(int a)//电影类型解析函数，通过用户输入的数字，解析出对应的类型信息；
{
	switch(a)
	{
		case 1:printf("爱情\n");break;
		case 2:printf("动作\n");break;
		case 3:printf("科幻\n");break;
		case 4:printf("剧情\n");break;
		case 5:printf("文艺\n");break;
		case 6:printf("喜剧\n");break;
		case 7:printf("惊悚\n");break;
		default :printf("Error\n");
	}
}
void Print(struct Movie *p,int i)//打印影片信息函数
{
	if(p==NULL)
		printf("信息为空!\n");
	else
	{
		printf("\n********************************* %d ******************************\n",i);
		printf("影片名:%s\n",p->Movie_name);
		printf("导演名:%s\n",p->Director_name);
		printf("主演名:%s\n",p->Leading_Role_name);
		printf("上映时间:%d年%d月%d日\n",p->Show_date.year,p->Show_date.month,p->Show_date.day);
		printf("影片国籍：");National_Analyse(p->National);
		printf("内容类型:");Type_Analyse(p->Type);
		printf("放映室：%d号\n",p->Room+1);
		printf("影片类型:%s\n",p->Movie_Type);
		printf("影片票价:%6.2f元/张\n",p->Price);
		printf("******************************************************************\n");
	}
}
void Print_All(struct Movie *heada)
{
	int i=0;
	if(head==NULL)
		printf("信息为空!\n");
	else
	{
		struct Movie *p;
		p=head;
		while(p!=NULL)
		{
			i++;
			Print(p,i);
			p=p->next;
		}
		printf("共%d条信息\n",count);
	}
	printf("Press Any Key To Continue.......\n");
	getch();
}
void New_Look()//最新录入的电影查看函数，默认查看最新的五个
{
	if(head==NULL)
		printf("信息为空!");
	else
	{
	       	struct Movie *p;
		int i=0;
		p=head;    
		while(p!=NULL&&i<5)
		{
			i++;
			Print(p,i);
			p=p->next;
		}
	}
}
int Test(char *a) // //影片存在检测函数,如果有则返回0，没有则返回1
{
	int i;
	struct Movie *p;
	p=head;
	for(i=0;i<count;i++)
	{
		if(strcmp(p->Movie_name,a)==0)
			return 0;
		p=p->next;
	}
	return 1;
}

int National_Select_Function(int test)
{
	int i=0;
	if(head==NULL)
	{
		printf("信息为空!");
		printf("Press Any Key To Continue.......\n");
	}
	else
	{
		struct Movie *p;
		p=head;
		while(p!=NULL)
		{
			if(p->National==test)
			{
				i++;
				Print(p,i);
			}
			p=p->next;
		}
	}
	printf("\n共%d条信息\n",i);
	printf("Press Any Key To Continue.......\n");
	getch();
	return i;
}
int Type_Select_Function(int test)//电影类型筛选函数，把用户需要的类型标志输入，然后通过遍历整个链表，找出符合条件的信息，并打印出来
{
    	int i=0;
	if(head==NULL)
	{
		printf("信息为空!");
		printf("Press Any Key To Continue.......\n");
	}
	else
	{
		struct Movie *p;
		p=head;
		while(p!=NULL)
		{
			if(p->Type==test)
			{
				i++;
				Print(p,i);
			}
			p=p->next;
		}
	}
	printf("\n共%d条信息\n",i);
	printf("Press Any Key To Continue.......\n");
	getche();
	return i;
}

