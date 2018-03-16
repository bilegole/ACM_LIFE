#include<stdio.h>

int isPrime(int x){
	int digit=2;
	for(digit=2;digit<x;digit++){
		if(x%digit==0){
			return 0;
		}
	}
	return 1;
}

void test(){
	int i,j;
	for(i=0;i<100;i++){	
		if(isPrime(i)){
			printf("%d is a prime number \n",i);
		}
	}
}

int main(){
	test();
	return 0;
}
