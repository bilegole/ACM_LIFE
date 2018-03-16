#include<stdio.h>

int divide(int num){
	int co;
	printf("%d=",num);
	while(1){
		for(co=2;co<num;co++){
			if(num%co==0){
				num/=co;
				printf("%d*",co);
				break;
			}
		}	if(co==num){printf("%d\n",num);return 0;}
	}
}
	
int main(){
	int num;
	int i;
	for(i=3;i<100;i++){
		divide(i);
	}
	return 0;
}
