#include<stdio.h>
#define MAX 4
int isDifferent(int a,int b,int c){
	if(a!=b&&b!=c&&a!=c){return 1;}
	return 0;
}

int main(){
	int co1,co2,co3,count=0;
	for(co1=1;co1<MAX+1;co1++){
		for(co2=1;co2<MAX+1;co2++){
			for(co3=1;co3<MAX+1;co3++){
		if(isDifferent(co1,co2,co3)){
			count++;
			printf("%d\n",co1*100+co2*10+co3);
		}
			}
		}
	}
	return 0;
}
			
