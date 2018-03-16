#include<stdio.h>

int main(){
	int co1,co2,tig=1;//tig=1->isPrime
	for(co1=101;co1<201;co1++){
		for(tig=1,co2=2;co2<co1;co2++){
			if(co1%co2==0){tig=0;}
		}if(tig){printf("%d\tis Prime\n",co1);}
	}
	return 0;
}
