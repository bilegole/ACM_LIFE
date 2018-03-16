#include<stdio.h>

int xadd(int a,int x){
	int co1,ten,sum=0;
	for(co1=x,ten=1;co1>0;co1--,ten*=10){
		sum+=co1*a*ten;
	}
	return sum;
}

int main(){
	printf("%d\n",xadd(2,5));
	return 0;
}
