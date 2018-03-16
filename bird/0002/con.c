#include<stdio.h>
#define isTest 1

int main(){
	//get the frofit.
	double profit,bonus;
	int rank[6]={0,10,20,40,60,100};
	double rate[6]={0.2,0.1,0.05,0.04,0.03,0.01};
	scanf("%lf",&profit);
	if(isTest==1){printf("My profit is %lf,",profit);} 
	//calculate bonus
	int co;
	for(co=1;co<5;co++){
		if(profit>(rank[co]-rank[co-1])){
			bonus+=(rank[co]-rank[co-1])*rate[co];
			profit-=(rank[co]-rank[co-1]);
		}else{
			bonus+=profit*rate[co];
			profit=0;
			break;
		}
	}
	if(profit>0){bonus+=profit*rate[5];profit=0;}
	printf("And my bouns is %lf!\n",bonus);
	return 0;
}
			
