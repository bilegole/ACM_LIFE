#include<stdio.h>

struct Number{
	int num;
	int factors[100],fatlen;
	int sum;
};

int pro(int x){
	//init the Number;
	struct Number num;
	num.num=x;
	num.factors[0]=1;
	num.fatlen=1;
	//fill the factors;
	int co,tig=1;
	while(tig){
		for (co=2;co<num.num;co++){
			if(num.num%co==0){
				num.factors[num.fatlen]=co;
				num.fatlen++;
				num.num/=co;
				break;
			}
		}
		if(co==num.num){
			num.factors[num.fatlen]=num.num;
			num.fatlen++;
			break;
		}
	}
	//sum them up;
	for(num.sum=0,co=0;co<num.fatlen;co++){
		num.sum+=num.factors[co];
	}
	return num.sum;
}

int main(){
	int co;
	for(co=2;co<1000;co++){
		//if(co==pro(co)){
		printf("The sum of the %d,\t is %d!\n",co,pro(co));
	}
	return 0;
}
		
