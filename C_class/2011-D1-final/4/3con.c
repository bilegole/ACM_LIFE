#include<stdio.h>
#define isTest 1

struct Student{
	int id,score;
};

struct Context{
	struct Student stu[10001];
	int Num,sum,ave;
};

int main(){
	//init context;
	struct Context con;
	//input the data of the students;
	int co=0;
	do{
		scanf("%d %d",&con.stu[co].score,&con.stu[co].id);
		co++;
	}while(con.stu[co-1].score!=0&&con.stu[co-1].id!=0);
	con.Num=co-1;
	//sorting the students by their score and id;
	int Len;
	for(Len=con.Num-1;Len>0;Len--){
		for(co=0;co<Len;co++){
			if(con.stu[con.Num-co-1].score> con.stu[con.Num-co-2].score
			||(con.stu[con.Num-co-1].score==con.stu[con.Num-co-2].score
			&& con.stu[con.Num-co-1].id   < con.stu[con.Num-co-2].id))
			{
				con.stu[10000]=con.stu[con.Num-co-1];
				con.stu[con.Num-co-1]=con.stu[con.Num-co-2];
				con.stu[con.Num-co-2]=con.stu[10000];
			}
		}
	}
	//calculate the avergae of the score;
	for(con.sum=0,co=0;co<con.Num;co++){
		con.sum+=con.stu[co].score;
	}	if(con.Num!=0){con.ave=con.sum/con.Num;}
	//display the list of the good students;
	for(co=0;co<con.Num&&con.stu[co].score>con.ave;co++){
		printf("%d\t%d\n",con.stu[co].id,con.stu[co].score);
	}
	return 0;
}
