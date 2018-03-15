#include<stdio.h>
#define Class_number 3
#define isTest 1
struct Student{
	char name[100];
	int id,grade[Class_number];
	//1->Chinese
	//2->Math
	//3->Science
};
struct Context{
	struct Student stu[100];
	int Num,ave[Class_number],sum[Class_number];
};
void display(struct Context *con){
	//display total;
	int co1,co2;
	printf("%d\t",con->Num);
	for(co1=0;co1<Class_number;co1++){
		printf("%d\t",con->sum[co1]);
	}	printf("\n");
	//display students;
	for(co1=0;co1<con->Num;co1++){
		printf("%d\t",con->stu[co1].id);
		for(co2=0;co2<Class_number;co2++){
			printf("%d\t",con->stu[co1].grade[co2]);
		}	printf("\n");
	}
}
int main(){
	//init the Context;
	struct Context con;
	//input the data;
	scanf("%d",&con.Num);
	int co1;
	for(co1=0;co1<con.Num;co1++){
		scanf("%d %s %d %d %d",&con.stu[co1].id,con.stu[co1].name,
				&con.stu[co1].grade[0],&con.stu[co1].grade[1],&con.stu[co1].grade[2]);
	}
	int co2;
	for(co1=0;co1<Class_number;co1++){						//outer cycle is for three class;
		for(con.sum[co1]=0,co2=0;co2<con.Num;co2++){		//iner cycle is for every student;
			con.sum[co1]+=con.stu[co2].grade[co1];
		}
		con.ave[co1]=con.sum[co1]/con.Num;
	}
	if(isTest==1){display(&con);}
	return 0;
}
