#include<stdio.h>
//1->Prime 0->NoPrime
int isPrime(int target){
	int i;
	for(i=2;i<target;i++){
		if(target%i==0){return 0;}
	}return 1;
}

int main(){
	int count=0,num=1;
	while(num){
		scanf("%d",&num);
		if(isPrime(num)){
			count++;
		}
	}
	printf("%d\n",count-1);
	return 0;
}
