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
	//init the context;
	struct Context con;
	//input the data;
	int digit=0;
	do{
		scanf("%d %d",&con.stu[digit].score,&con.stu[digit].id);
		digit++;
	}while(con.stu[digit-1].score!=0&&con.stu[digit-1].id!=0);
	con.Num=digit-1;
	if(isTest==1){printf("There is %d students\n",con.Num);}
	//calculate the sum and the average of the students;
	for(con.sum=0,digit=0;digit<con.Num;digit++){
		con.sum+=con.stu[digit].score;
	}	if(con.Num!=0){con.ave=con.sum/con.Num;}
	//sorting the students by the score first;
	int len;
	for(len=con.Num-1;len>0;len--){
		for(digit=0;digit<len;digit++){
			if(con.stu[con.Num-digit-1].score> con.stu[con.Num-digit-2].score
			||(con.stu[con.Num-digit-1].score==con.stu[con.Num-digit-2].score
			&& con.stu[con.Num-digit-1].id   > con.stu[con.Num-digit-2].id))
			{
				con.stu[10000]=con.stu[con.Num-digit-1];
				con.stu[con.Num-digit-1]=con.stu[con.Num-digit-2];
				con.stu[con.Num-digit-2]=con.stu[10000];
			}
		}
	}
	//output the students who's score is higher than the average;
	for(digit=0;digit<con.Num;digit++){
		printf("%d %d\n",con.stu[digit].score,con.stu[digit].id);
	}
	return 0;
}
