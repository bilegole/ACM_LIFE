#include<stdio.h>

int isrun(int year){
	if(year%100==0){return 0;}
	else if(year%4==0){return 1;}
	return 0;
}

int main(){
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int co=0,count=0;
	for(co=0;co<month-1;co++){
		count+=days[co];
	}	count+=(day+isrun(month));
	printf("It is the %dth day \n",count);
	return 0;
}
	
