void Write()//数据保存函数，将输入的电影信息保存到文件中，以便下次用户使用
{
	int i=0;
	int a[10][6][8];
    int s,j,k;
	struct Movie *p;
	p=head;

	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	fp1=fopen("data.dat","wb");
	fp2=fopen("count.dat","wb");
	fp3=fopen("array.dat","w");
	fprintf(fp2,"%d",count);
	for(s=0;s<10;s++)
        for(j=0;j<6;j++)
            for(k=0;k<8;k++)
                    fprintf(fp3,"%d\n",a[s][j][k]);
	while(p!=NULL)
	{
		fwrite(p,sizeof(struct Movie),1,fp1);
		p=p->next;
	}
	printf("%d条信息正在写入，请稍候......\n",count);Sleep(2000);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
void Read()//读取文件信息函数，将保存的影片信息读取出来
{
	int i,n=0,s,j,k;
	int a[10][6][8];
	struct Movie *New,*Old;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	if(fopen("count.dat","rb")==NULL||fopen("data.dat","rb")==NULL||fopen("array.dat","r")==NULL)
	{
		printf("文件不存在，打开失败！\n");
		fp2=fopen("count.dat","wb");
		fp1=fopen("data.dat","wb");
		fp3=fopen("array.dat","w");
    }
	else
	{
		fp2=fopen("count.dat","rb");
		fp1=fopen("data.dat","rb");
		fp3=fopen("array.dat","r");
     	for(s=0;s<10;s++)
             for(j=0;j<6;j++)
                 for(k=0;k<8;k++)
                     fscanf(fp3,"%d\n",&a[s][j][k]);
    	fscanf(fp2,"%d",&count);
    	struct Movie stu[count];
    	for(i=0;i<count;i++)
    	{
    		fread(&stu[i],sizeof(struct Movie),1,fp1);
    	}
    	for(i=0;i<count;i++)
	    {
	    	New=(struct Movie *)malloc(sizeof(struct Movie));
	    	strcpy(New->Movie_name,stu[i].Movie_name);
	    	strcpy(New->Director_name,stu[i].Director_name);
	    	strcpy(New->Leading_Role_name,stu[i].Leading_Role_name);
	    	New->Show_date.year=stu[i].Show_date.year;
	    	New->Show_date.month=stu[i].Show_date.month;
	    	New->Show_date.day=stu[i].Show_date.day;
	    	New->National=stu[i].National;
	    	New->Type=stu[i].Type;
	    	New->Room=stu[i].Room;
	    	New->Price=stu[i].Price;
	    	strcpy(New->Movie_Type,stu[i].Movie_Type);
	    	n++;
	    	if(n==1)
		    {
		    	head=New;
		    	New->next==NULL;
		    	Old=New;
	    	}
	    	else
		    {
			    New->next=NULL;
			    Old->next=New;
			    Old=New;
		    }
	    }
	    printf("\n%d条信息读取成功,请稍候......\n",count);Sleep(2000);
    }
	fclose(fp2);
	fclose(fp1);
	fclose(fp3);
}
