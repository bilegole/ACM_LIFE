#include<stdio.h>
struct Data{
	int day;
	int month;
};
struct Context{
	int weekdata;
	struct Data data;
	int add;
};

int main(){
	int months[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int lock=1;
	struct Context con;
	con.data.day=1;
	con.data.month=1;
	con.weekdata=6;
	con.add=0;
	while(con.data.month<13){
		if(con.add==0&&con.data.day==1){
			printf("*********************************\nThis is the month %d\n\n",con.data.month);
			lock=1;
		}
		//输出数据
		if(con.add==con.weekdata&&lock){
			if(con.data.day<10){printf(" ");}
			printf("%d\t",con.data.day++);
			con.weekdata=(con.weekdata<6)?con.weekdata+1:0;
		}else {	
			printf("  \t");
		}	con.add++;

		//尝试更新月份
		if(con.data.day==months[con.data.month]+1){
			con.data.month++;
			con.data.day=1;
			lock=0;
		}

		//尝试换行
		if(con.add==7){
			printf("\n");
			con.add=0;
		}
	}
	printf("日历打印完毕！\n");
	while(1);
	return 0;
}
			
				
