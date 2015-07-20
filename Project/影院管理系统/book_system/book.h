void Print_Ticket(struct Movie *p ,int a[],int b[],int i)
{
	int j;
	printf("您的订单信息如下：\n");
	printf("影片名:%s\n",p->Movie_name);
	printf("影片票价:%6.2f元/张\n",p->Price);
	printf("票数：%d\n",i);
	printf("总价：%6.2f元\n",p->Price*i);
	for(j=0;j<i;j++)
		printf("第%d张票的位置:(%d,%d)\n",j+1,a[j],b[j]);
}
void Book_Tickets()
{
	char name[20];
	printf("\n亲，请问你要订哪个电影的票呢:");
	scanf("%s",name);
	if(0==Test(name))
	{
		int i,j,k;
		char ch;
		struct Movie *p;
		p=head;
		while(p!=NULL)
		{
			if(strcmp(p->Movie_name,name)==0)
				break;
			p=p->next;
		}
		i=p->Room;
		Seat_Look(i);
		printf("你需要订几张票：");
		scanf("%d",&j);
		getchar();
		int a[j],b[j];
		for(k=0;k<j;k++)
		{
			printf("请输入第%d张票的位置(如“(2,1)”):",k+1);
			scanf("(%d,%d)",&a[k],&b[k]);
			getchar();
		}
		Print_Ticket(p,a,b,j);
		printf("确认订购 :y/n ? ");
		ch=getche();
		while(1)
		{
			if(89==ch || 121==ch)
			{
				for(k=0;k<j;k++)
					Room_Array[i][a[k]-1][b[k]-1]=1;
				printf("\n订购成功,正在出票......\n");Sleep(2000);
				clear();
				break;
			}
			else if(78==ch || 110==ch)
			{
				printf("\n订购失败\n");
				break;
			}
			else
				printf("输入错误，请重新输入！");
		}
	}
	else
	{
		printf("找不到你所输入的电影，请核对电影名是否正确!\n");
		clear();
	}
	Customer_Select();
}
void Ask(head)
{	
	char ch;
	printf("亲，有您满意的影片吗？是否订票:y/n ? ");
	while(1)
	{
		ch=getche();	
		if(89==ch || 121==ch)
		{			
			Book_Tickets();
		}
		else if(78==ch || 110==ch)
        	{
			clear();
		    	Customer_Select();
        	}
		else
			printf("输入错误，请重新输入！\n");
	}
	printf("\n");
}
int Ticket_Test(int a,int b)
{
	if(a<1 || b<1)
	{
		printf("输入的坐标必须大于等于一！！");
		return 0;
	}
	else if(1==Room_Array[10][a][b])
	{
		printf("(a,b)位置已被订，请重新选择其他位置！！");
		return 0;
	}else
	{
		return 1;
	}
}
