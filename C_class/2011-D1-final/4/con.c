#include<stdio.h>

struct Student{
	int id;
	int score;
}
struct Student in(){
	struct Student student;
	scanf("%d",&student.id);
	scanf("%d",&student.score);
	return student;
}

struct Context {
	struct Student stu[10000];
	int stunum,stusum,stuave;
}	

int main(){
	struct Context con;
	con.stunum=0;
	do{
		scanf("%d %d",&con.stu[con.stunum].score,&con.stu[con.stunum].id);
		con.stunum++;
	}while(con.stu[con.stunum-1].score!=0&&con.stu[con.stunum-1].id!=0);
	int co_turn1=0,Ra_turn1=con.stuNum=con.stunum;con.stunum-=1;
	for(con.stusum=0,co_turn1=0;co_turn1<Ra_turn1;co_turn1++){
		con.stusum+=con.stu[co_turn1].score;
	}con.stuave=(int)con.stusun/con.stuNum;
	//sorting students by the score and id
	int co_turn1=0,Ra_turn1=con.stunum
	for(
//	int Stunum=0,i,sum=0;
//	struct Student students[10000];
//	for(i=0;;i++){
//		student[i]=in();
//		if(student[i].id=0){break;}
//		Stunum++;
//	}
//	int pin=0;
//	for(i=0;i<Stunum;i++){
		
		
	
	
