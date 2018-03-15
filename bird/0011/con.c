#include<stdio.h>

int main(){
	int p1=1,p2=0,p3=0,sum=1;
	int month=1;
	for(month=0;month<40;month++){
		p3+=p2;
		p2=p1;
		p1=p3;
		sum=p1+p2+p3;
		printf("There is %d ribbits,p1=%d,p2=%d,p3=%d\n",sum,p1,p2,p3);
	}	
	return 0;
}
