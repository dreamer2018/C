void Seat_Look(int i)//座位查看
{
	int a,b;
	printf("********************%d号厅座位情况**********************\n",i);
	printf("    1   2   3   4   5   6   7   8    \n") ;
	printf("6  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  6 \n",Room_Array[i][5][0],Room_Array[i][5][1],Room_Array[i][5][2],Room_Array[i][5][3],Room_Array[i][5][4],Room_Array[i][5][5],Room_Array[i][5][6],Room_Array[i][5][7]);
	printf("5  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  5 \n",Room_Array[i][4][0],Room_Array[i][4][1],Room_Array[i][4][2],Room_Array[i][4][3],Room_Array[i][4][4],Room_Array[i][4][5],Room_Array[i][4][6],Room_Array[i][4][7]);
	printf("4  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  4 \n",Room_Array[i][3][0],Room_Array[i][3][1],Room_Array[i][3][2],Room_Array[i][3][3],Room_Array[i][3][4],Room_Array[i][3][5],Room_Array[i][3][6],Room_Array[i][3][7]);
	printf("3  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  3 \n",Room_Array[i][2][0],Room_Array[i][2][1],Room_Array[i][2][2],Room_Array[i][2][3],Room_Array[i][2][4],Room_Array[i][2][5],Room_Array[i][2][6],Room_Array[i][2][7]);
	printf("2  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  2 \n",Room_Array[i][1][0],Room_Array[i][1][1],Room_Array[i][1][2],Room_Array[i][1][3],Room_Array[i][1][4],Room_Array[i][1][5],Room_Array[i][1][6],Room_Array[i][1][7]);
	printf("1  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]  1 \n",Room_Array[i][0][0],Room_Array[i][0][1],Room_Array[i][0][2],Room_Array[i][0][3],Room_Array[i][0][4],Room_Array[i][0][5],Room_Array[i][0][6],Room_Array[i][0][7]);
	printf("    1   2   3   4   5   6   7   8      \n");
	printf("说明：0代表座位可用，1代表不可用");
	printf("****************************************************");
}
void Array_Clear() //座位数组Room_Array[10][6][8]初始化函数
{
	int i,j,k;
	for(i=0;i<10;i++)
	{
		for(j=0;j<6;j++)
		{
			for(k=0;k<8;k++)
				Room_Array[i][j][k]=0;
		}
	}
}
void Seat_Manage()
{
	int i,a,b;
	printf("您要对几号厅座位进行修改(1-10)：");
	scanf("%d",&i);
	clear();
	Seat_Look(i);
	printf("请输入你要选择的位置(如上图坐标):(2,1)):");
	scanf("(%d,%d)",&a,&b);
	Room_Array[i][a][b]=0;
	printf("修改成功,正在保存数据，请稍候......");Sleep(1000);
	Seat_Look(i);
}

