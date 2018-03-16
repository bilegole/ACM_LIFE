#include<stdio.h>

int pro(int x){
	int sum=0,co;
	for(co=1;co<x;co++){
		if(x%co==0){
			sum+=co;
		}
	}
	return sum;
}
int main(){
	int co;
	for(co=2;co<1000;co++){
		if(co==pro(co)){
			printf("%d\t==>%d\n",co,pro(co));
		}
	}
	return 0;
}
