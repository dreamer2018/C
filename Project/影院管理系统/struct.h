struct Date                //日期结构体
{
	int year;   //年
	int month;  //月
	int day;    //日
};
struct Movie   //影片信息结构体
{
	char Movie_name[30];         //影片名 （唯一）
	char Director_name[20];		 //影片导演  （唯一）
	char Leading_Role_name[40];	 //影片主演 （可多个）
	struct  Date Show_date;		 //影片上映时间 (依次为年月日)
	int National;				 //影片国籍 （中国，欧美，日韩，其他）
	int Type;					 //影片内容的类型 （爱情，动作，科幻，剧情，文艺，喜剧，惊悚）
	int Room;					 //影片放映室 （暂定为1-10号厅）
	char Movie_Type[10];		 //影片的制作类型 （2D,3D,MAXI,MAXI+3D)
	float Price;				 //票价
	struct Movie *next;
};

