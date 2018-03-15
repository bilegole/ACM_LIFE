#include<stdio.h>

struct Student{
	int id;
	int score;
};
struct Student in(){
	struct Student student;
	scanf("%d",&student.id);
	scanf("%d",&student.score);
	return student;
}

struct Context {
	struct Student stu[10001];
	int stuNum,stunum,stusum,stuave;
};	

int main(){
	struct Context con;
	con.stunum=0;
	do{
		scanf("%d %d",&con.stu[con.stunum].score,&con.stu[con.stunum].id);
		con.stunum++;
	}while(con.stu[con.stunum-1].score!=0&&con.stu[con.stunum-1].id!=0);
	int co_turn1=0,Ra_turn1=con.stuNum=con.stunum;con.stunum-=1;
	//add up anll the score.
	for(con.stusum=0,co_turn1=0;co_turn1<Ra_turn1;co_turn1++){
		con.stusum+=con.stu[co_turn1].score;
	}con.stuave=(int)con.stusum/con.stuNum;
	//sorting students by score and id
	Ra_turn1=con.stuNum-1;
	int co_turn2=0,Ra_turn2;
	for(co_turn1=0;co_turn1<Ra_turn1;co_turn1++){
		for(Ra_turn2=con.stuNum-1-co_turn1,co_turn2=0;co_turn2<Ra_turn2;co_turn2++){
			if(con.stu[con.stuNum-1-co_turn2].score>con.stu[con.stuNum-2-co_turn2].score
			||(con.stu[con.stuNum-1-co_turn2].score==con.stu[con.stuNum-2-co_turn2].score
			&& con.stu[con.stuNum-1-co_turn2].id   > con.stu[con.stuNum-2-co_turn2].id)){	
				con.stu[10001]=con.stu[con.stuNum-1-co_turn2];
				con.stu[con.stuNum-1-co_turn2]=con.stu[con.stuNum-2-co_turn2];
				con.stu[con.stuNum-2-co_turn2]=con.stu[10001];
			}
		}
	}
	//output the students whos score is higher than average
	int co_turn3=0,Ra_turn3=con.stuNum;
	for(co_turn3=0;co_turn3<Ra_turn3&&con.stu[co_turn3].score>=con.stuave;co_turn3++){
		printf("%d %d\n",con.stu[co_turn3].score,con.stu[co_turn3].id);
	}
	return 0;
}
//	int Stunum=0,i,sum=0;
//	struct Student students[10000];
//	for(i=0;;i++){
//		student[i]=in();
//		if(student[i].id=0){break;}
//		Stunum++;
//	}
//	int pin=0;
//	for(i=0;i<Stunum;i++){
		
		
	
	
