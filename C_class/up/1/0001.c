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

int is_diff(int year){
    if(year%100==0){
        return 28;
    }else if(year%4==0){
        return 29;
    }else {
        return 28;
    }
}

int main(){
	int months[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int lock=1;
    int year;
	struct Context con;
    printf("tell me the year!\n");
    scanf("%d",&year);
    int diff=0;
    if(year>2006){
        for(int i=2006;i<year;i++){
            diff+=(5+is_diff(year)-28);
            }
    }else if(year <2006){
        for(int i=2006;i>year;i--){
            diff-=(5+is_diff(year-1)-28);
        }
    }
    months[2]=is_diff(year);
	con.data.day=1;
    con.data.day+=diff;
    while(con.data.day<0){
        con.data.day+=30;}
    while(con.data.day>31){
        con.data.day-=30;}
	con.data.month=1;
	con.weekdata=6;
    con.weekdata+=diff;
    while(con.weekdata>7){
        con.weekdata-=7;}
    while(con.weekdata<1){
        con.weekdata+=7;}
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
	return 0;
}
			
				
